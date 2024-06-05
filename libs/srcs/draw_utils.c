#include "../headers/draw_utils.h"

/**
 * permet de changer de position sur le terminal avec des position x et y
 * 
 * @param pos_x position en x du deplacement
 * @param pos_y position en y du deplacement
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void drawUtils_change_term_pos(const int pos_x, const int pos_y) {
	printf("\e[%d;%dH", pos_y, pos_x);
	fflush(stdout);
}

/**
 * permet de supprimer l'affichage sur le terminal commme la
 * commande clear
 * 
 * @param
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void drawUtils_clear_term(void) {
    printf("\e[1;1H\e[2J");
    fflush(stdout);
}
