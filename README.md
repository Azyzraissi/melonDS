<p align="center"><img src="https://github.com/user-attachments/assets/b12b01e7-fc03-4646-a0bf-26e709d17536"></p>
<h2 align="center"><b>melonDS</b></h2>

<a href="https://www.gnu.org/licenses/gpl-3.0" alt="License: GPLv3"><img src="https://img.shields.io/badge/License-GPL%20v3-%23ff554d.svg"></a>
[![PRs Welcome](https://img.shields.io/badge/PRs-welcomed-brightgreen.svg?style=flat)](https://github.com/Azyzraissi/OpenEmu/pulls)
[![Threads](https://img.shields.io/badge/Azyz.raw-000000?style=social&logo=Threads&logoColor=black)](https://www.threads.net/azyz.raw)

DS emulator, <b>a real one.</b>  

This a fork of the original melonDS with a single unique difference : a new icon. It was built and tested on macOS ARM64 (Apple Silicon). You can also build it from source with the shiny new icon. See the [wiki](https://github.com/Azyzraissi/melonDS/wiki) for instructions.

<hr>

## Features

* New icon, obviously.
* Native ARM64 build. 
* Believe or not, built-in [Nintendo WFC](https://melonds.kuribo64.net/board/thread.php?id=285) (Not my work though, not taking credits for it)

## How to use

* Home menu boot requires a BIOS/firmware dump from an original DS or DS Lite.
* DS firmwares dumped from a DSi or 3DS aren't bootable and only contain configuration data, thus they are only suitable when booting games directly.
* As of today, there is no gamelist on melonDS, just open your .nds file directly to load a game.

### Possible firmware sizes

 * 128KB: DSi/3DS DS-mode firmware (reduced size due to lacking bootcode)
 * 256KB: regular DS firmware
 * 512KB: iQue DS firmware

DS BIOS dumps from a DSi or 3DS can be used with no compatibility issues. DSi BIOS dumps (in DSi mode) are not compatible. Or maybe they are. I don't know.

As for the rest, the interface should be pretty straightforward. If you have a question, don't hesitate to ask, fill an issue or pull a request!

## How to build (macOS ARM64)

1. Install the [Homebrew Package Manager](https://brew.sh)
2. Install dependencies: `brew install git pkg-config cmake sdl2 qt@6 libarchive enet zstd`
3. Download the melonDS repository and prepare:
   ```zsh
   git clone https://github.com/melonDS-emu/melonDS
   cd melonDS
   ```
4. Compile:
   ```zsh
   cmake -B build -DCMAKE_PREFIX_PATH="$(brew --prefix qt@6);$(brew --prefix libarchive)"
   cmake --build build -j$(sysctl -n hw.logicalcpu)
   ```
If everything goes well, melonDS.app should now be in the `build` directory.

#### Self-contained app bundle
If you want an app bundle that can be distributed to other computers without needing to install dependencies through Homebrew, you can additionally run `
../tools/mac-libs.rb .` after the build is completed, or add `-DMACOS_BUNDLE_LIBS=ON` to the first CMake command.


## Credits

 * Martin for GBAtek, a good piece of documentation
 * Cydrak for the extra 3D GPU research
 * ~~limittox~~ [vale](https://macosicons.com/#/u/vale) on [macOSicons](https://macosicons.com/) for the icon 
 * All of you comrades who have been testing melonDS, reporting issues, suggesting shit, etc

## Licenses

[![GNU GPLv3 Image](https://www.gnu.org/graphics/gplv3-127x51.png)](http://www.gnu.org/licenses/gpl-3.0.en.html)

melonDS is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

### External
* Images used in the Input Config Dialog - see `src/frontend/qt_sdl/InputConfig/resources/LICENSE.md`
* Used the original Nintendo Font for the new icon because why not.
