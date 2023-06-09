# UTILGEN.H Documentation

**Author**: Umang Amrania
**Date**: 09-06-2023

## Description
`UTILGEN.H` is a header file that contains a set of generic utility functions and console manipulation functions. These functions are commonly used for various purposes, including modifying the output on the console. The header file provides functions for setting console colors, moving the cursor, and clearing the console.

## Table of Contents
- [Color Definitions](#color-definitions)
- [Functions](#functions)
  - [set_color](#set_color)
  - [reset_color](#reset_color)
  - [move_cursor](#move_cursor)
  - [set_cursor](#set_cursor)
  - [clear_console](#clear_console)

## Color Definitions<a name="color-definitions"></a>
All the color escape sequences are defined, here are some of them:

- `COLOR_DEFAULT`: Default color
- `COLOR_BLACK`: Black color
- `COLOR_DARK_RED`: Dark red color
- `COLOR_DARK_GREEN`: Dark green color
- `COLOR_DARK_YELLOW`: Dark yellow color
- `COLOR_DARK_BLUE`: Dark blue color
- `COLOR_DARK_MAGENTA`: Dark magenta color
- `COLOR_DARK_CYAN`: Dark cyan color
- `COLOR_LIGHT_GRAY`: Light gray color
- AND MORE
## Functions<a name="functions"></a>

### set_color
```c
void set_color(char *color_escape_sequence)
```

Sets the console color using the provided color escape sequence.

- `color_escape_sequence`: The escape sequence of the color to be set. (Refer to color definitions)

### reset_color
```c
void reset_color()
```

Resets the console color to the default.

### move_cursor
```c
void move_cursor(int rows, int columns)
```

Moves the console cursor relative to its current position.

- `rows`: Number of rows to move (can be negative to move up)
- `columns`: Number of columns to move

### set_cursor
```c
void set_cursor(int x, int y)
```

Sets the console cursor to an absolute position.

- `x`: New X coordinate (positive value)
- `y`: New Y coordinate (positive value)

### clear_console
```c
void clear_console()
```

Clears the console screen.

---

*Note: The Windows-specific code uses the `cls` command to clear the console, while the UNIX-specific code uses the `clear` command.*
