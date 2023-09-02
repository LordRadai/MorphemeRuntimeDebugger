# MorphemeRuntimeDebugger
A tool to see how Morpheme runs when the game is open. Works only for SOTFS Ver 1.03.

# Installation
1) Rename `MorphemeRuntimeDebugger.dll` to `dinput8.dll`.
2) Drag and drop `dinput8.dll` and the `MorphemeRuntimeDebugger` folder into your `Game` folder. If you use another DLL, you'll need a DLL chain loader. I use LazyLoader by ChurchGuard (https://www.nexusmods.com/darksouls3/mods/677)

# Basic Usage
* While the game is open, press the INSERT key to open the debugger window.

  ![Immagine 2023-09-02 191543](https://github.com/LordRadai/MorphemeRuntimeDebugger/assets/22768664/00151c51-b0bf-4f44-8e2c-dfaee1db8357)

# Resources window
* The Resources window on the left contains animation nodes. It will filter all the animations that don't have an event track by default.
* You can select an asset and double click it to load EventTracks and related TimeAct in the AnimNode window.

![Immagine 2023-09-02 191418](https://github.com/LordRadai/MorphemeRuntimeDebugger/assets/22768664/9e69b8da-9fa3-404a-bf8d-d559609c86f5)
