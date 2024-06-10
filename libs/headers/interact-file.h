#ifndef _YG_INTERACT_FILE_
#define _YG_INTERACT_FILE_

#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <stdio.h>

int  open_csv_file(const char *file);
void close_csv_file(int fd);
void write_csv_file(const int cells, const int fd);

#endif
