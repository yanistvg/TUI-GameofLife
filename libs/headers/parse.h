#ifndef _YG_PARSE_
#define _YG_PARSE_

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>

#include "./returns.h"
#include "./colors.h"

#define _YG_PARAM_HELP_       "--help"
#define _YG_PARAM_CELLS_      "--cells-numbers"
#define _YG_PARAM_DAYS_       "--days"
#define _YG_PARAM_WAIT_       "--delay"
#define _YG_PARAM_MAX_X_      "--size-x"
#define _YG_PARAM_MAX_Y_      "--size-y"
#define _YG_PARAM_CSV_EXPORT_ "--export-csv"

#define _YG_RAND_MAX_CELLS_ 250
#define _YG_MIN_DAYS_       100
#define _YG_DEFAULT_WAIT_   1000000

#define MIN_X_SIZE 30
#define MIN_Y_SIZE 10

#define MAX_SIZE_FILE_NAME 200

struct parameters_t {
    int  init_cellules_count;
    int  max_day;
    int  delay_sleeping;
    int  set_x;
    int  set_y;
    char export_file[MAX_SIZE_FILE_NAME + 1];
};

int  parse_check(const int param_count, const char **param);
void parse_show_error(int error);

#endif
