/**
 * @file UTILGEN.H
 * @brief Contains a set of generic utility functions and console manipulation functions
 * 
 * This header file contains a set of generic utility functions
 * that are used often, along with some functions that are used
 * to modify the output on the console.
 * 
 * AUTHOR: UMG_AMRANIA
 * DATE: 09-06-2023
 * 
*/

#pragma once

#ifndef _UTILGEN_H
#define _UTILGEN_H
#endif

#define COLOR_DEFAULT       "\033[39m"
#define COLOR_BLACK       "\033[30m"
#define COLOR_DARK_RED      "\033[31m"
#define COLOR_DARK_GREEN    "\033[32m"
#define COLOR_DARK_YELLOW     "\033[33m"
#define COLOR_DARK_BLUE     "\033[34m"
#define COLOR_DARK_MAGENTA    "\033[35m"
#define COLOR_DARK_CYAN     "\033[36m"
#define COLOR_LIGHT_GRAY    "\033[37m"
#define COLOR_DARK_GRAY     "\033[90m"
#define COLOR_RED         "\033[91m"
#define COLOR_GREEN       "\033[92m"
#define COLOR_ORANGE      "\033[93m"
#define COLOR_BLUE        "\033[94m"
#define COLOR_MAGENTA       "\033[95m"
#define COLOR_CYAN        "\033[96m"
#define COLOR_WHITE       "\033[97m"

#define BG_COLOR_DEFAULT     "\033[49m"
#define BG_COLOR_BLACK     "\033[40m"
#define BG_COLOR_DARK_RED    "\033[41m"
#define BG_COLOR_DARK_GREEN  "\033[42m"
#define BG_COLOR_DARK_YELLOW   "\033[43m"
#define BG_COLOR_DARK_BLUE   "\033[44m"
#define BG_COLOR_DARK_MAGENTA  "\033[45m"
#define BG_COLOR_DARK_CYAN   "\033[46m"
#define BG_COLOR_LIGHT_GRAY  "\033[47m"
#define BG_COLOR_DARK_GRAY   "\033[100m"
#define BG_COLOR_RED       "\033[101m"
#define BG_COLOR_GREEN     "\033[101m"
#define BG_COLOR_ORANGE    "\033[103m"
#define BG_COLOR_BLUE      "\033[104m"
#define BG_COLOR_MAGENTA     "\033[105m"
#define BG_COLOR_CYAN      "\033[106m"
#define BG_COLOR_WHITE     "\033[107m"

#include <stdlib.h>

#ifdef _WIN32
  // specific code for windows

  #define _INC_UTILGEN

  #ifndef _INC_STDIO
  #include <stdio.h>
  #endif

  #ifndef _INC_CONIO
  #include <conio.h>
  #endif

  #ifndef _INC_WINDOWS
  #include <windows.h>
  #endif
#else
  // specific code for UNIX

  #ifndef _STDIO_H
  #include <stdio.h>
  #endif

  #ifndef _TERMIOS_H
  #include <termios.h>
  #endif

  #ifndef _UNISTD_H
  #include <unistd.h>
  #endif

  /**
   * Implementation oF getch function for UNIX
  */
  int getch() {
    struct termios oldAttr, newAttr;
    int ch;

    // Save the old terminal attributes
    tcgetattr(STDIN_FILENO, &oldAttr);  

    // Set the terminal to non-canonical mode
    newAttr = oldAttr;
    newAttr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);

    // Read a character from the input stream
    ch = getchar();

    // Restore the terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &oldAttr);

    return ch;
  }
#endif

/**
 * Sets console color
 * @param color_escape_sequence The Escape sequence of the color to be set. (All colors are pre-defined as macros)
*/
void set_color(char *color_escape_sequence){  
  #ifdef _WIN32
    /** 
     * In Linux, every time a program exits, the color is automatically reset to white 
     * color needs to be manually set back to white in Windows
    */
    atexit(reset_color);
  #endif

  printf("%s", color_escape_sequence);
}

/**
 * Resets the console color to default
*/
void reset_color(){
  // Reseting foreground color
  printf("\033[39m");

  // Reseting background color
  printf("\033[49m");
}

/**
 * Move console cursor relative to its current position
 * 
 * @param rows How many rows to move (Works with negative also)
 * @param columns How many columns to move
*/
void move_cursor(int rows, int columns) {
  if (rows < 0) {
    printf("\033[%dA", -rows);  // Move cursor up by |rows| positions
  } else if (rows > 0) {
    printf("\033[%dB", rows);  // Move cursor down by rows positions
  }

  if (columns < 0) {
    printf("\033[%dD", -columns);  // Move cursor left by |columns| positions
  } else if (columns > 0) {
    printf("\033[%dC", columns);  // Move cursor right by columns positions
  }
}

/**
 * Set console cursor to an absolute position (Relative to console)
 * 
 * @param x New X coordinate (positive value)
 * @param y New Y coordinate (positive value)
*/
void set_cursor(int x, int y){
  printf("\033[%d;%dH", x, y);
}

/**
 * Clears the console
*/
void clear_console(){
  #ifdef _WIN32
    const char *cmd = "cls";
  #else
    const char *cmd = "clear";
  #endif

  system(cmd);
}
