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
 * @date 2024-06-04
*/
int main(int argc, char **argv) {
    int errors;

    if (getTermSize() == _YG_FAIL_GET_SCREEN_SIZE_) {
        printf("**ERROR de recuperation de la taille de la fenetre\n");
        return 1;
    }

    errors = parse_check(argc, (const char**)argv);
    if (errors) parse_show_error(errors);

    return _YG_SUCCESS_;
}
