#include "graph.h"

/*******************************************************************************************
 * Programmers: Isaac-Jacob Sanchez, Tarang Teredesai, John Gohol
 * Class: CptS 122, Spring 2025
 * Crimson Code 2025
 * Theme: Art in Innovation
 * Date: Feb 15, 2025
 * Description: Program that plots various types of cool and artistic graphs in the terminal
 *******************************************************************************************/

int main()
{
    float scale, a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    int use_f1 = 0, use_f2 = 0;
    int func1_type = 0, func2_type = 0;

    printf("Enter scale (units per box): ");
    scanf("%f", &scale);

    get_function_parameters(&use_f1, &func1_type, &a1, &b1);
    get_function_parameters(&use_f2, &func2_type, &a2, &b2);

    initialize_grid();
    draw_axes();

    plot_function(use_f1, func1_type, a1, b1, scale, 2, '*');
    plot_function(use_f2, func2_type, a2, b2, scale, 3, '#');
    print_grid();
    Sleep(5);
    system("cls");

    if (use_f1) print_message(func1_type, a1, b1);
    if (use_f1) print_message(func1_type, a2, b2);
    print_grid();
    system("pause");
    return 0;
}
