#ifndef _YG_GAME_
#define _YG_GAME_

#include <strings.h>

#include "./interact-terminal.h"
#include "./parse.h"

struct game_t {
    int     size[2];
    char  **board;
    int     day;
};

int game_init_structure(struct parameters_t *parameters, struct terminal_info_t *term);

#endif
