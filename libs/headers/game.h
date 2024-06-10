#ifndef _YG_GAME_
#define _YG_GAME_

#include <strings.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#include "./interact-terminal.h"
#include "./parse.h"
#include "./show_game.h"
#include "./draw_utils.h"

#define _YG_CELLS_VALUE_ 1

struct game_t {
    int     size[2];
    char  **board;
    int     day;
    int     currant_cells;
    int     max_day;
};

int  game_init_structure(struct parameters_t *parameters, struct terminal_info_t *term);
void game_destroy_structure(void);
void game_start_drawing(void);
void game_drawing(void);
void game_start(void);
int  change_grid_with_rule(void);

#endif
