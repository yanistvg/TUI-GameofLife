#include "./libs/headers/main.h"

/**
 * debut de programme du jeu de la vie qui produit un
 * simulation de cellules qui suivent trois regles pour
 * ce reproduire mourir ou naitre
 * 
 * Ce programme genere un grille aleatoire de cellule initiale
 * puit la simulation est demarer pour visualiser ces cellules
 * progresser
 * 
 * @date 2024-06-05
*/
int main(int argc, char **argv) {
    int errors;

    //* ----------------------------------------------- *//
    //* section de preparation avant l'execution du jeu *//
    //* ----------------------------------------------- *//

    if ((errors = getTermSize())) print_error(_YG_FAIL_GET_SCREEN_SIZE_);
    if ((errors = parse_check(argc, (const char**)argv))) parse_show_error(errors);
    if ((errors = game_init_structure(&parameters, &term))) print_error(errors);

    //* ----------------------------------------------- *//
    //*                demarrage du jeu                 *//
    //* ----------------------------------------------- *//
    game_start_drawing();


    //* ----------------------------------------------- *//
    //*          fin de l'execution du programme        *//
    //* ----------------------------------------------- *//
    game_destroy_structure();

    return _YG_SUCCESS_;
}

/**
 * affiche une erreur sur le terminal quand elle est genere par
 * des function extern au projet
 * 
 * @param error valeur de l'erreur qui a ete genere
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void print_error(int error) {
    perror("ERROR");
    exit(error);
}
