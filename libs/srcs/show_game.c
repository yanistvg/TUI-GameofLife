#include "../headers/show_game.h"

/**
 * permet d'afficher la grille du jeu
 * 
 * @param cells la grille de jeu
 * @param size la taille de l'ecrant
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void showGame_draw_cells(char **cells, int *size) {
    int x;
    int y;

    drawUtils_change_term_pos(1, 2);

    for (y = 0; y < size[Y]; y++) {
        for (x=0; x < size[X]; x++) {
            if (cells[x][y]) printf("%s", _YG_CELL_COLOR_);
            else printf("%s", _YG_EMPTY_COLOR_);

            printf("%s", _YG_CELL_DRAWING_);
        }
        printf("%s\n\r", DEFAULT_COLOR);
    }
}

/**
 * permet d'afficher le compte d'iteration effectue sur
 * le terminal
 * 
 * @param day nombre d'iteration effectue
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void showGame_draw_day(const int day) {
    drawUtils_change_term_pos(1, 1);
    printf("%s DAYS : %s%d%s", TEXT_CYAN, TEXT_GREEN, day, DEFAULT_COLOR);
}

/**
 * permet d'afficher le nombre maximal definie d'iteration
 * sur le terminal
 * 
 * @param max_day le nombre maximum d'iteration
 * @param size_x la taille du terminal en x
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void showGame_draw_max_day(const int max_day, const int size_x) {
    char day[30];
    int pos_x;

    bzero(day, sizeof(char) * (unsigned long)30);
    sprintf(day, "%d", max_day);
    pos_x = ((size_x * 2) - 12) - (int)strlen(day);
    drawUtils_change_term_pos(pos_x, 1);
    printf("%sMAX DAYS : %s%s%s", TEXT_CYAN, TEXT_GREEN, day, DEFAULT_COLOR);
}

/**
 * permet d'afficher le nombre de cellules present sur la grille
 * 
 * @param count_cells nombre de cellules sur la grille de jeu
 * @param size_x taille de la fenetre
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void showGame_draw_count_cells(const int count_cells, const int size_x) {
    drawUtils_change_term_pos(size_x - 15, 1);
    printf("%sCELLS : %s%d%s         ", TEXT_CYAN, TEXT_GREEN, count_cells, DEFAULT_COLOR);
}
