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
 * @date 2024-06-07
*/
void game_destroy_structure(void) {
    int x;

    for (x=0; x < game.size[X]; x++) {
        free(game.board[x]);
    }
    free(game.board);

    bzero(&game, sizeof(struct game_t));
}

/**
 * permet d'afficher le plateau de jeu au lancement de la
 * partie
 * 
 * @param
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void game_start_drawing(void) {
    drawUtils_clear_term();

    showGame_draw_day(game.day);
    showGame_draw_count_cells(game.currant_cells, game.size[X]);
    showGame_draw_max_day(game.max_day, game.size[X]);
    showGame_draw_cells(game.board, game.size);
}

/**
 * permet d'afficher le plateau de jeu en affichant les
 * partie sur le terminal qui change
 * 
 * @param
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void game_drawing(void) {
    showGame_draw_day(game.day);
    showGame_draw_count_cells(game.currant_cells, game.size[X]);
    showGame_draw_cells(game.board, game.size);
}

/**
 * permet de lancer la simulation avec les differents
 * parametre donnes
 * 
 * @param
 * 
 * @return none
 * 
 * @date 2024-06-10
*/
void game_start(void) {
    while (game.day < game.max_day) {
        usleep(1000000);
        game.day++;

        // appliquer les regles du jeu pour chaque cellules
        change_grid_with_rule();

        // afficher les changements sur la grilles
        game_drawing();
    }
}

/**
 * permet d'appliquer les regles du jeu de la vie sur la grille
 * 
 * @param
 * 
 * @returns _YG_MALLOC_ERROR_ en cas de probleme lors du malloc
 * @returns _YG_SUCCESS_      si la grille a bien etais change
 * 
 * @date 2024-06-10
*/
int change_grid_with_rule(void) {
    char **new_board = NULL;
    char **old_board = NULL;
    int i, j;
    int x_compteur, y_compteur;
    int x, y;
    int count_cells;

    new_board = malloc(sizeof(void*) * (unsigned long)game.size[X]);
    if (new_board == NULL) return _YG_MALLOC_ERROR_;

    game.currant_cells = 0;

    for (i=0; i < game.size[X]; i++) {
        new_board[i] = malloc(sizeof(char) * (unsigned long)game.size[Y]);
        if (game.board[i] == NULL) return _YG_MALLOC_ERROR_;
        
        // appliquer les regles sur la ligne
        for (j= 0; j < game.size[Y]; j++) {

            count_cells = 0;

            for (x_compteur = i-1; x_compteur <= i+1; x_compteur++) {
                x = x_compteur;
                if (x < 0) x = game.size[X] - 1;
                if (x >= game.size[X]) x = 0;

                for (y_compteur=j-1; y_compteur <= j+1; y_compteur++) {
                    y = y_compteur;
                    if (y < 0) y = game.size[Y] - 1;
                    if (y >= game.size[Y]) y = 0;

                    if (x == i && y == j) continue;

                    count_cells += (int)game.board[x][y];
                }
            }

            if (count_cells < 2) new_board[i][j] = (char)0;
            if (count_cells == 2) new_board[i][j] = game.board[i][j];
            if (count_cells == 3) new_board[i][j] = (char)1;
            if (count_cells > 3) new_board[i][j] = (char)0;

            game.currant_cells += (int)new_board[i][j];
        }
    }

    // changement des grilles
    old_board = game.board;
    game.board = new_board;

    // suppression de l'ancienne grille
    for (i=0; i < game.size[X]; i++) {
        free(old_board[i]);
    }
    free(old_board);

    return _YG_SUCCESS_;
}
