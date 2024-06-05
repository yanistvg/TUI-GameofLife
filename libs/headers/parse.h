#ifndef _YG_PARSE_
#define _YG_PARSE_

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "./returns.h"
#include "./colors.h"

#define _YG_PARAM_HELP_  "--help"
#define _YG_PARAM_CELLS_ "--cells-numbers"
#define _YG_PARAM_DAYS_  "--days"

#define _YG_RAND_MAX_CELLS_ 250
#define _YG_MIN_DAYS_       100

struct parameters_t {
    int init_cellules_count;
    int max_day;
};

int  parse_check(const int param_count, const char **param);
void parse_show_error(int error);

#endif
