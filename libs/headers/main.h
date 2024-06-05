#ifndef _YG_MAIN_
#define _YG_MAIN_

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "./returns.h"
#include "./interact-terminal.h"
#include "./parse.h"
#include "./game.h"
#include "./colors.h"

extern struct terminal_info_t term;
extern struct parameters_t parameters;
extern struct game_t game;

void print_error(int error);

#endif
