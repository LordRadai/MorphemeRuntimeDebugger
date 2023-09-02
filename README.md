# MorphemeRuntimeDebugger
A tool to see how Morpheme runs when the game is open. Works only for SOTFS Ver 1.03.

# Installation
1) Rename `MorphemeRuntimeDebugger.dll` to `dinput8.dll`.
2) Drag and drop `dinput8.dll` and the `MorphemeRuntimeDebugger` folder into your `Game` folder. If you use another DLL, you'll need a DLL chain loader. I use LazyLoader by ChurchGuard (https://www.nexusmods.com/darksouls3/mods/677)

# Basic Usage
* While the game is open, press the INSERT key to open the debugger window.

![Immagine 2023-09-02 191543](https://github.com/LordRadai/MorphemeRuntimeDebugger/assets/22768664/00151c51-b0bf-4f44-8e2c-dfaee1db8357)

# What it can and cannot do
* It can detect the current frame time of a playing animation node. If you load the tracks of an animation node and it starts playing, it will move the cursor. Note that there can be multiple nodes that share a single animation. There is no cheap way to detect this unfortunately.
* It can edit frame times and values of existing tracks, but can't add new ones.
* It can show active nodes in a network.
* It lets you send Morpheme Messages to play animations, as well as adjust ControlParameters manually.
