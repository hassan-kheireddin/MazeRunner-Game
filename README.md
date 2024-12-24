# so_long

[![42 École](https://img.shields.io/badge/42-École-000000?style=flat&logo=42&logoColor=white)](https://42.fr)

**so_long** is a 2D game project developed as part of the 42 École curriculum. This project combines game mechanics, graphics programming, and event handling to create an interactive and visually appealing game.

---

## Table of Contents
- [About the Project](#about-the-project)
- [Features](#features)
- [Getting Started](#getting-started)
- [Installation](#installation)


---

## About the Project

The **so_long** project involves creating a small 2D game where the player navigates a character through a map, collecting items and reaching an exit while avoiding obstacles. The game uses the **MiniLibX** library for rendering graphics and handling events.

This project enhances skills in:
- Graphics rendering and window management.
- Game mechanics like player movement, collision detection, and map parsing.
- Handling user inputs and keyboard events.

---

## Features

- **2D Rendering:** Uses the MiniLibX library to render game graphics.
- **Keyboard Input:** Supports WASD keys for movement.
- **Collectibles and Exit:** The player must collect all items to unlock the exit.
- **Dynamic Map Parsing:** Reads maps from `.ber` files and validates them.
- **Simple Game Logic:** Implements game over and success states.

---

## Getting Started

### Prerequisites
- A Unix-based operating system (Linux or macOS recommended).
- GCC or another compatible C compiler.
- Make utility.
- The MiniLibX library.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/hassan-kheireddin/so_long.git
   ```
2. Enter the folder:
   ```bash
   cd so_long
   ```
3. compile:
   ```bash
   make
   ```