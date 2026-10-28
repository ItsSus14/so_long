# so_long

A small 2D game written in C as part of the 42 School Common Core.

The objective is to collect every collectible on the map and reach the exit. The game uses MiniLibX to render a 2D environment and handle keyboard input.

## Features

- 2D graphics using MiniLibX for Linux.
- Custom XPM textures for the player, walls, floor, collectibles, and exit.
- Keyboard controls and collision detection.
- Collectibles tracking and exit unlocking.
- Movement counter displayed in the terminal.
- Map parsing and validation before game initialization.
- Recursive path validation to check whether the map is completable.
- Error handling and explicit resource cleanup.

## Controls

| Key | Action |
| --- | --- |
| W / Up Arrow | Move up |
| A / Left Arrow | Move left |
| S / Down Arrow | Move down |
| D / Right Arrow | Move right |
| ESC | Quit the game |

## Map Format

The program accepts a map file with the `.ber` extension.

| Character | Meaning |
| --- | --- |
| `1` | Wall |
| `0` | Empty space |
| `P` | Player starting position |
| `C` | Collectible |
| `E` | Exit |

A valid map must:

- Be rectangular, with all rows having the same width.
- Be enclosed by walls.
- Contain exactly one player (`P`) and one exit (`E`).
- Contain at least one collectible (`C`).
- Contain only supported characters.
- Provide a valid path from the player to every collectible and to the exit.
- Contain no malformed rows, including unexpected empty rows.

## Requirements

- Linux
- GCC or a compatible C compiler
- GNU Make
- MiniLibX for Linux and its required system dependencies
- The `libft` and `ft_printf` libraries used by this project

## Installation

### 1. Clone the repository

```bash
git clone https://github.com/ItsSus14/so_long.git
cd so_long
```

### 2. Clone the required libraries

`libft` and `ft_printf` are maintained in separate repositories and are not included in this repository.

Clone them alongside `so_long`:

```bash
git clone git@github.com:ItsSus14/libft.git ../libft
git clone git@github.com:ItsSus14/ft_printf.git ../ft_printf
```

The expected directory structure is:

```text
Projects/
├── so_long/
├── libft/
├── ft_printf/
└── minilibx-linux/
```

The directory names must match the paths configured in the Makefile. If you use different names or locations, update the corresponding variables in the Makefile.

Both libraries must be available locally so that the project can build and link against them.

### 3. Install MiniLibX

Place the Linux version of MiniLibX in the expected location and install its required development dependencies.

The Makefile must point to the correct MiniLibX directory and link the required libraries.

## Build

Compile the project from its root directory:

```bash
make
```

Available Makefile targets:

```bash
make       # Compile the project
make clean # Remove object files
make fclean # Remove object files and executable
make re    # Clean and rebuild
```

## Run

Pass a `.ber` map as the program's only argument:

```bash
./so_long maps/map.ber
```

The program validates the map before initializing the game window. If the map is invalid or a required resource cannot be loaded, initialization fails and allocated resources are cleaned up.

## Map Validation

Map validation is performed before the game starts and covers both the map's structure and its playability.

The validation process checks:

1. **Map dimensions:** all rows must have the same width, and the map must have a valid rectangular shape.
2. **Allowed characters:** unsupported symbols and malformed rows are rejected.
3. **Required elements:** the map must contain exactly one player, exactly one exit, and at least one collectible.
4. **Wall enclosure:** the map must be surrounded by walls.
5. **Reachability:** all collectibles and the exit must be reachable from the player's starting position.

### Recursive path checking

To check whether the map is completable, the program uses a recursive traversal starting from the player's position (`P`).

The algorithm explores the available directions and marks visited positions by replacing their contents with a wall character (`1`). This prevents the recursion from revisiting the same positions indefinitely.

Once the traversal finishes, the algorithm checks whether any collectibles (`C`) or the exit (`E`) remain unvisited.

- If a collectible or the exit remains, the map is not completable.
- If all collectibles and the exit have been reached, the map passes the path validation.

This approach verifies reachability without opening the graphical window or starting the game.

## Memory Management

The project explicitly manages dynamically allocated memory and MiniLibX resources, including map data, loaded images, the game window, and the graphics context.

Error paths are designed to release resources that were successfully initialized before a failure occurred.

The project has also been tested with Valgrind to check for memory leaks and memory errors during execution and selected failure scenarios.

## Memory Testing

Use Valgrind to check for memory leaks and memory errors:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long maps/map.ber
```

Check the final summary for outstanding allocations and memory errors. A clean run should report no memory leaks and `ERROR SUMMARY: 0 errors`.

The project has been tested during normal execution and with selected initialization failures, including a missing texture.

## Project Structure

```text
so_long/
├── Makefile
├── include/
│   └── so_long.h
├── src/
│   ├── map/
│   ├── render/
│   └── ...
├── maps/
│   └── map.ber
├── textures/
│   ├── floor.xpm
│   ├── collect.xpm
│   ├── exit.xpm
│   ├── player.xpm
│   └── wall.xpm
└── README.md
```

The `libft`, `ft_printf`, and `minilibx-linux` directories are external dependencies located alongside the project.

## Learning Objectives

This project provided practical experience with:

- C programming and dynamic memory allocation.
- File handling and map parsing.
- Recursive algorithms and pathfinding.
- Graphics rendering and event handling.
+- Error handling and resource cleanup.
- Building and linking a project with external libraries.


