#ifndef _YG_INTERACT_TERMINAL_
#define _YG_INTERACT_TERMINAL_

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <strings.h>

#include "./returns.h"

struct terminal_info_t {
    int size[2];
};

#define X 0
#define Y 1

#define MIN_X_SIZE 30
#define MIN_Y_SIZE 10

int getTermSize(void);

#endif
