# Oczko

Oczko is a Windows desktop card game written in C++/CLI with Windows Forms. The project implements a simple blackjack-style experience with a graphical interface for starting a game, placing bets, and playing against the croupier.

## Features

- Player setup with starting money and player name
- Graphical menu and game screens built with Windows Forms
- Core game actions: hit, stand, double, and split
- Betting flow with wallet tracking
- Bundled card images and application icon

## Tech stack

- C++/CLI
- Windows Forms
- Visual Studio solution/project files (`.sln`, `.vcxproj`)
- .NET Framework 4.7.2

## Project structure

- `main.cpp` — Application entry point
- `MenuForm.h` and `MenuForm.cpp` — Start screen
- `GameForm.h` — Main game UI
- `Core.hpp` and `Core.cpp` — Game orchestration
- `cards/` — Card image assets
- `img/` — Additional images

## Build

This repository contains a Visual Studio C++/CLI project and is intended to be built on Windows with Visual Studio and the C++/CLI toolchain installed.

1. Open `oczko.sln` in Visual Studio.
2. Select a build configuration such as `Debug|x64` or `Release|x64`.
3. Build and run the `oczko` project from Visual Studio.

## Notes

- The project could not be built in this Linux-based environment because the required Visual Studio C++ targets are unavailable.
- The solution references `Microsoft.Cpp.Default.props`, which requires the Visual Studio MSBuild toolchain on Windows.
