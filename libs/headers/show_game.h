#ifndef _YG_SHOW_GAME_
#define _YG_SHOW_GAME_

#include <stdio.h>

#include "./colors.h"
#include "./draw_utils.h"
#include "./interact-terminal.h"

#define _YG_CELL_DRAWING_ "  "
#define _YG_CELL_COLOR_   "\033[47m"
#define _YG_EMPTY_COLOR_  "\033[40m"

void showGame_draw_cells(char **cells, int *size);
void showGame_draw_day(const int day);
void showGame_draw_max_day(const int max_day, const int size_y);
void showGame_draw_count_cells(const int count_cells, const int size_x);

#endif
