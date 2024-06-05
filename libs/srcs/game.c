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
 * @returns _YG_MALLOC_ERROR_ si une erreur c'est produit durant l'allocation
 * de memoire du plateau de jeu
 * @returns _YG_SUCCESS_ si la structure c'est bien initialiser
 * 
 * @date 2024-06-05
*/
int game_init_structure(struct parameters_t *parameters, struct terminal_info_t *term) {
    int i = -1;
    int x, y;

    game.size[X] = term->size[X] % 2 == 0
        ? term->size[X] / 2
        : (term->size[X] - 1) / 2;
    game.size[Y] = term->size[Y] - 2;
    game.day = 0;
    game.board = NULL;
    game.currant_cells = parameters->init_cellules_count < game.size[X] * game.size[Y]
        ? parameters->init_cellules_count
        : game.size[X];
    game.max_day = parameters->max_day;

    // creation du plateau de jeu au dimention de la fenetre
    game.board = malloc(sizeof(char *) * (unsigned long)game.size[X]);
    if (game.board == NULL) return _YG_MALLOC_ERROR_;

    while (++i < game.size[X]) {
        game.board[i] = malloc(sizeof(char) * (unsigned long)game.size[Y]);
        if (game.board[i] == NULL) return _YG_MALLOC_ERROR_;
        bzero(game.board[i], sizeof(char) * (unsigned long)game.size[Y]);
    }

    // placement des cellules sur le plateau
    i = 0;
    do {
        x = rand() % game.size[X];
        y = rand() % game.size[Y];

        if (game.board[x][y] != _YG_CELLS_VALUE_) {
            game.board[x][y] = _YG_CELLS_VALUE_;
            i++;
        }
    } while(i < game.currant_cells);

    return _YG_SUCCESS_;
}

/**
 * permet de supprimer la memoire qui est alloue pour le grille de jeu
 * et de passer a zero l'integralite de la structure
 * 
 * @param
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void game_destroy_structure(void) {
    int x;

    for (x=0; x < game.size[X]; x++) {
        free(game.board[x]);
    }

    bzero(&game, sizeof(struct game_t));
}