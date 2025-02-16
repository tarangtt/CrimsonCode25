#ifndef GRAPH_H
#define GRAPH_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

// terminal height n width
#define WIDTH 80
#define HEIGHT 24

// color codes
#define GRAY "\033[90m"
#define GREEN "\033[92m"
#define PINK "\033[95m"
#define RED "\033[91m"
#define RESET "\033[0m"

// global variables
extern char grid[WIDTH][HEIGHT];
extern int colors[WIDTH][HEIGHT];
extern int origin_x, origin_y;

void initialize_grid();
void draw_axes();
void print_grid();
void get_function_parameters(int *use_function, int *func_type, float *a, float *b);
void plot_function(int use_function, int func_type, float a, float b, float scale, int color, char symbol);
void print_message(int func_type, float a, float b);

#endif
