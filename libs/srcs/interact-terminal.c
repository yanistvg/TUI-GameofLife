#include "../headers/interact-terminal.h"

struct terminal_info_t term;

/**
 * permet de preparer le terminal pour les differents affichage
 * et interaction avec le terminal comme la recuperation de la
 * taille de la fenetre
 * 
 * @param
 * 
 * @returns _YG_FAIL_GET_SCREEN_SIZE_ en cas d'erreur lors de la recuperation
 * de la taille de la fenetre
 * @returns _YG_SUCCESS_ si pas d'erreur lors de l'initialisation de la structure
 * term qui contient les differents info sur le terminal
 * 
 * @date 2024-06-04
*/
int getTermSize(void) {
	struct winsize w;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) < 0) return _YG_FAIL_GET_SCREEN_SIZE_;
	term.size[X] = w.ws_col;
	term.size[Y] = w.ws_row;

	if (term.size[X] < MIN_X_SIZE || term.size[Y] < MIN_Y_SIZE) return _YG_MIN_VALUE_REQUIRED_;
	return _YG_SUCCESS_;
}
