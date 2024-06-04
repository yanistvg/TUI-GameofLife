#include "../headers/game.h"

struct game_t game;

/**
 * permet d'initialiser la structure de la partie en creant la grille de jeu
 * au bonne dimention et en placant un nombre de cellules definie dans les
 * parametres sur la grille
 * 
 * @param parameters poiteur sur la structure des parametres traite par le
 * fichier de parse
 * @param term poiteur sur la strutcure des info du terminal traite pat le
 * fichier des interaction du terminal
 * 
 * @returns _YG_SUCCESS_ si la structure c'est bien initialiser
 * 
 * @date 2024-06-04
*/
int game_init_structure(struct parameters_t *parameters, struct terminal_info_t *term) {
    int i = -1;

    game.size[X] = term->size[X] % 2 == 0
        ? term->size[X] / 2
        : (term->size[X] - 1) / 2;
    game.size[Y] = term->size[Y] - 1;
    game.day = 0;
    game.board = NULL;

    game.board = malloc(sizeof(char *) * (unsigned long)game.size[X]);
    if (game.board == NULL) return _YG_MALLOC_ERROR_;

    while (++i < game.size[Y]) {
        game.board[i] = malloc(sizeof(char) * (unsigned long)game.size[Y]);
        if (game.board[i] == NULL) return _YG_MALLOC_ERROR_;
        bzero(game.board[i], sizeof(char) * (unsigned long)game.size[Y]);
    }

    return _YG_SUCCESS_;
}
