#include "graph.h"

// define global vars
char grid[WIDTH][HEIGHT];
int colors[WIDTH][HEIGHT];
int origin_x, origin_y;

void initialize_grid()
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = ' ';
            colors[i][j] = 0;
        }
    }
    origin_x = WIDTH / 2;
    origin_y = HEIGHT / 2;
}

void draw_axes()
{
    for (int i = 0; i < WIDTH; i++)
    {
        grid[i][origin_y] = (i == origin_x) ? '+' : '-';
        colors[i][origin_y] = 1;
    }
    for (int j = 0; j < HEIGHT; j++)
    {
        if (j != origin_y)
        {
            grid[origin_x][j] = '|';
            colors[origin_x][j] = 1;
        }
    }
}

void print_grid()
{
    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            switch (colors[i][j])
            {
            case 1:
                printf(GRAY "%c" RESET, grid[i][j]);
                break;
            case 2:
                printf(GREEN "%c" RESET, grid[i][j]);
                break;
            case 3:
                printf(PINK "%c" RESET, grid[i][j]);
                break;
            case 4:
                printf(RED "%c" RESET, grid[i][j]);
                break;
            default:
                putchar(grid[i][j]);
            }
        }
        putchar('\n');
    }
}

void get_function_parameters(int *use_function, int *func_type, float *a, float *b)
{
    printf("Plot function? (Yes - 1/ No - 0): ");
    scanf("%d", use_function);
    if (*use_function)
    {
        printf("Select function type (1=linear, 2=sin, 3=cos, 4=exp, 5=ln): ");
        scanf("%d", func_type);
        printf("Enter a and b: ");
        scanf("%f %f", a, b);
    }
}

void plot_function(int use_function, int func_type, float a, float b, float scale, int color, char symbol)
{
    if (!use_function)
        return;

    for (int i = 0; i < WIDTH; i++)
    {
        float x_val = (i - origin_x) * scale;
        float y_val;
        int valid = 1;

        switch (func_type)
        {
        case 1:
            y_val = a * x_val + b;
            break;
        case 2:
            y_val = a * sin(b * x_val);
            break;
        case 3:
            y_val = a * cos(b * x_val);
            break;
        case 4:
            y_val = a * exp(b * x_val);
            break;
        case 5:
            if (b * x_val <= 0)
            {
                valid = 0;
            } // remove where log is undefined
            else
            {
                y_val = a * log(b * x_val);
            }
            break;
        default:
            valid = 0;
            break;
        }

        if (valid)
        {
            int j = round(origin_y - y_val / scale);
            if (j >= 0 && j < HEIGHT)
            {
                if (grid[i][j] == ' ')
                {
                    grid[i][j] = symbol;
                    colors[i][j] = color;
                }
                else if (grid[i][j] != ' ' && grid[i][j] != symbol)
                {
                    grid[i][j] = '@';
                    colors[i][j] = 4;
                }
            }
        }
    }
}

void print_message(int func_type, float a, float b)
{

    //   printf("Select function type (1=linear, 2=sin, 3=cos, 4=exp, 5=ln): ");
    printf(GRAY "GRAPH OF " RED);
    switch (func_type)
    {
    case 1:
        printf("line y=%.2fx+%.2f", a, b);
        break;
    case 2:
        printf("Sin y=%.2fsin(%.2fx)", a, b);
        break;
    case 3:
        printf("Cos y=%.2fcos(%.2fx)", a, b);
        break;
    case 4:
        printf("Exp y=%.2fe^(%.2fx)", a, b);
        break;
    case 5:
        printf("ln y=%.2fln(%.2fx)", a, b);
        break;
    default:
        break;
    }
    printf("\n" RESET);
}
