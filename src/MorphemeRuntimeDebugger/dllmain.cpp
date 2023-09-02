#include "includes.h"
#include "common.h"
#include "TaeTemplate/TaeTemplate.h"
#define APPNAME_W L"MorphemeRuntimeDebugger v1.0.0"
#define APPNAME_A "MorphemeRuntimeDebugger v1.0.0"

HINSTANCE hinst_dll = 0;
std::thread begin_thread;
std::thread main_loop;

extern "C" UINT_PTR directinput_create_proc = 0;
extern "C" __declspec(dllexport) HRESULT __cdecl DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter);
static decltype(&DirectInput8Create) original_dinput8_create;

HMODULE g_moduleAddr;
uint64_t g_gameManagerImp;
uint64_t g_networkManager;
uint64_t g_katanaMainApp;
int g_gameState;
int g_prevGameState = 0;

oSendMessage sendMessage;
oTaeLookup taeLookup;

HWND window = NULL;

static ID3D11Device* pDevice = NULL;
static ID3D11DeviceContext* pContext = NULL;
static IDXGISwapChain* g_pSwapChain = NULL;
static ID3D11RenderTargetView* mainRenderTargetView = NULL;

bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc_Alt(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool g_openMorphemeDebugger = false;
AppGUI g_morphemeDebugger;

EventTrackEditor g_eventTrackEditor;

TimeActEditor g_timeActEditorPl;
TimeActEditor g_timeActEditorSfx;
TimeActEditor g_timeActEditorSnd;

TaeTemplate g_taeTemplate;

oUpdateCPInt pUpdateCpInt = nullptr;
oUpdateCPInt pUpdateCpIntTarget;

oUpdateCPFloat pUpdateCpFloat = nullptr;
oUpdateCPFloat pUpdateCpFloatTarget;

void initImGui(HWND hwnd)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImNodes::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGuiStyle& style = ImGui::GetStyle();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(pDevice, pContext);

    io.Fonts->AddFontDefault();

    g_morphemeDebugger.GUIStyle();
}

int keyPressed(int key) {
    return (GetAsyncKeyState(key) & 0x8000 != 0);
}

bool Begin(uint64_t qModuleHandle) {

    char dllpath[MAX_PATH];

    g_moduleAddr = GetModuleHandleA("DarkSoulsII.exe");

    GetSystemDirectoryA(dllpath, MAX_PATH);
    strcat_s(dllpath, "\\dinput8.dll");
    hinst_dll = LoadLibraryA(dllpath);

    MH_STATUS status = MH_Initialize();
    if (status != MH_OK)
    {
        std::string sStatus = MH_StatusToString(status);
        printf_s("Minhook init failed.");
        return false;
    }

    if (!hinst_dll) {
        MessageBoxA(NULL, "Failed to load original DLL", "Error", MB_ICONERROR);
        return false;
    };

    original_dinput8_create = (decltype(&DirectInput8Create))GetProcAddress(hinst_dll, "DirectInput8Create");
    if (!original_dinput8_create) {
        MessageBoxA(NULL, "Failed to load original DLL", "Error", MB_ICONERROR);
        return false;
    }

#ifdef _CONSOLE
    AllocConsole();

    FILE* fDummy;
    freopen_s(&fDummy, "CONOUT$", "w", stdout);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONIN$", "r", stdin);
    std::cout.clear();
    std::clog.clear();
    std::cerr.clear();
    std::cin.clear();
#endif

    FRPG2Hook::InitHooks();

    return true;
};

bool MainLoop(uint64_t qModuleHandle)
{
    do
    {
        if ((GetAsyncKeyState(VK_INSERT) & 1) && !g_openMorphemeDebugger)
            g_openMorphemeDebugger = true;
        
        if (g_openMorphemeDebugger)
        {
            g_openMorphemeDebugger = false;
            FRPG2::assignFunctionAddr();

            //ImGui_ImplWin32_EnableDpiAwareness();
            WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, WndProc_Alt, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, APPNAME_W, NULL };
            ::RegisterClassExW(&wc);
            HWND hwnd = ::CreateWindowW(wc.lpszClassName, APPNAME_W, WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

            // Initialize Direct3D
            if (!CreateDeviceD3D(hwnd))
            {
                CleanupDeviceD3D();
                ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
                return 1;
            }

            ifstream file(".//MorphemeRuntimeDebugger//res//def//timeact.json");
            g_taeTemplate = TaeTemplate(file);

            // Show the window
            ::ShowWindow(hwnd, SW_SHOWDEFAULT);
            ::UpdateWindow(hwnd);
            SetForegroundWindow(hwnd);

            initImGui(hwnd);

            ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

            bool done = false;
            while (!done)
            {
                if ((GetAsyncKeyState(VK_INSERT) & 1))
                {
                    SetForegroundWindow(hwnd);
                    MessageBoxA(hwnd, "Morpheme Network Inspector already running", "Network Inspector", MB_ICONINFORMATION);
                }

                if (g_moduleAddr)
                {
                    g_gameManagerImp = *(uint64_t*)((uint64_t)g_moduleAddr + 0x16148F0);
                    g_networkManager = *(uint64_t*)((uint64_t)g_moduleAddr + 0x1616CF8);
                    g_katanaMainApp = *(uint64_t*)((uint64_t)g_moduleAddr + 0x16751F8);

                    if (g_gameManagerImp)
                    {
                        g_gameState = *(int*)(g_gameManagerImp + 0x24AC);

                        if (g_gameState == 30)
                        {
                            UINT64 aiManager = *(UINT64*)(g_gameManagerImp + 0x28);

                            g_morphemeDebugger.m_gameDebugFlags.m_disableAi = (bool*)(aiManager + 0x18);
                        }
                    }
                }

                if (g_gameState != g_prevGameState)
                {
                    Debug::DebuggerMessage(Debug::LVL_INFO, "Game State changed: %d -> %d.\n", g_prevGameState, g_gameState);
                    g_prevGameState = g_gameState;
                }

                MSG msg;
                while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
                {
                    ::TranslateMessage(&msg);
                    ::DispatchMessage(&msg);
                    if (msg.message == WM_QUIT)
                        done = true;
                }
                if (done)
                    break;

                // Start the Dear ImGui frame
                ImGui_ImplDX11_NewFrame();
                ImGui_ImplWin32_NewFrame();
                ImGui::NewFrame();

                g_morphemeDebugger.RenderGUI(APPNAME_A);

                ImGui::Render();
                const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
                pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
                pContext->ClearRenderTargetView(mainRenderTargetView, clear_color_with_alpha);
                ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

                if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
                {
                    ImGui::UpdatePlatformWindows();
                    ImGui::RenderPlatformWindowsDefault();
                }

                g_pSwapChain->Present(1, 0); // Present with vsync
            }

            ImGui_ImplDX11_Shutdown();
            ImGui_ImplWin32_Shutdown();
            ImNodes::DestroyContext();
            ImGui::DestroyContext();

            CleanupDeviceD3D();
            ::DestroyWindow(hwnd);
            ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        }       
    } while (true);

    return true;
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {

    switch (fdwReason) {
        case (DLL_PROCESS_ATTACH): {
            DisableThreadLibraryCalls(hinstDLL);
            main_loop = std::thread(MainLoop, (uint64_t)hinstDLL);
            begin_thread = std::thread(Begin, (uint64_t)hinstDLL);
            break;
        };
        case (DLL_PROCESS_DETACH): {
            begin_thread.detach();
            main_loop.detach();
            FreeLibrary(hinst_dll);
            break;
        };
    }
    return TRUE;
}

// Define original dll export and call the original function
extern "C" __declspec(dllexport) HRESULT __cdecl DirectInput8Create(
    HINSTANCE hinst,
    DWORD dwVersion,
    REFIID riidltf,
    LPVOID * ppvOut,
    LPUNKNOWN punkOuter)
{
    return original_dinput8_create(hinst, dwVersion, riidltf, ppvOut, punkOuter);
}

bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;
    //createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &pDevice, &featureLevel, &pContext) != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
    if (pContext) { pContext->Release(); pContext = NULL; }
    if (pDevice) { pDevice->Release(); pDevice = NULL; }
}

void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
    pBackBuffer->Release();
}

void CleanupRenderTarget()
{
    if (mainRenderTargetView) { mainRenderTargetView->Release(); mainRenderTargetView = NULL; }
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc_Alt(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (pDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
            CreateRenderTarget();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}