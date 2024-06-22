#include "../headers/interact-file.h"

int open_csv_file(const char *file) {
    return open(file, O_WRONLY | O_APPEND | O_CREAT, 0666);
}

void close_csv_file(int fd) {
    write(fd, "\n", 1);
    close(fd);
}

void write_csv_file(const int cells, const int fd) {
    if (fd <= 0) return;
    char element[100];

    bzero(element, sizeof(char) * (unsigned long)100);
    sprintf(element, "%d", cells);
    strcat(element, ",");
    write(fd, element, strlen(element));
}
