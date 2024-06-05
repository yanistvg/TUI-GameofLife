#include "../headers/parse.h"

struct parameters_t parameters;

/**
 * recupere les differents parametre donne au programme pour
 * preparer la structure qui contient les donnees pour lancer
 * la partie.
 * 
 * @param param_count contient le nombre de parametrre
 * @param param contient les paramettres donnes au lancement
 * du programme
 * 
 * @returns
 * 
 * @date 2024-06-05
*/
int parse_check(const int param_count, const char **param) {
    int i = 0;

    srand((unsigned int)time(NULL));

    /* set des valeurs par default pour en cas de non renseignement */
    parameters.init_cellules_count = (rand() % _YG_RAND_MAX_CELLS_) + 1;
    parameters.max_day = _YG_MIN_DAYS_;

    /* set les valeurs par default si pas de parametre */
    /* ce qui implique de generer un nombre aleatoire  */
    /* de cellules                                     */
    if (param_count <= 1) {
        return _YG_SUCCESS_;
    }

    /* extraction des parametres si present */
    while (++i < param_count) {

        /* extraire le nombre de cellules a creer */
        if (strcmp(param[i], _YG_PARAM_CELLS_) == 0) {
            if (++i >= param_count) return _YG_BAD_CELLS_INPUT_;

            sscanf(param[i], "%d", &(parameters.init_cellules_count));

            if (parameters.init_cellules_count <= 0) return _YG_BAD_CELLS_INPUT_;
            continue;
        }

        /* extraire le nombre de generation a realiser */
        if (strcmp(param[i], _YG_PARAM_DAYS_) == 0) {
            if (++i >= param_count) return _YG_BAD_DAYS_INPUT_;

            sscanf(param[i], "%d", &(parameters.max_day));

            if (parameters.init_cellules_count <= 1) return _YG_BAD_DAYS_INPUT_;
            continue;
        }

        /* afficher le manuel de la commande */
        if (strcmp(param[i], _YG_PARAM_HELP_) == 0) return _YG_SHOW_MAN_;

        return _YG_NO_PARAMETER_INTENTIFY_;

    }

    return _YG_SUCCESS_;
}

/**
 * permet d'afficher un message d'erreur pour le mauvais
 * usage de la commande et afficher le man avant de stopper
 * le programme
 * 
 * @param error valeur de l'erreur genere par parse_check
 * 
 * @return none
 * 
 * @date 2024-06-05
*/
void parse_show_error(int error) {
    /* afficher un message personnaliser en fonction de l'erreur */
    switch (error) {
        case _YG_BAD_PARAMETERS_:
            printf("%sErreur : les parametres donnes ne sont pas valide.%s\n", TEXT_RED, DEFAULT_COLOR); break;
        case _YG_BAD_CELLS_INPUT_:
            printf("%sErreur : parametre %s est soit inferieur a zero ou non definie%s\n", TEXT_RED, _YG_PARAM_CELLS_, DEFAULT_COLOR); break;
        case _YG_NO_PARAMETER_INTENTIFY_:
            printf("%sErreur : un ou plusieur parametre n'ont pas etais identifier%s\n", TEXT_RED, DEFAULT_COLOR); break;
        case _YG_BAD_DAYS_INPUT_:
            printf("%sErreur : parametre %s est soit inferieur a un ou non definie%s\n", TEXT_RED, _YG_PARAM_DAYS_, DEFAULT_COLOR); break;

        case _YG_SHOW_MAN_: error = 0; break;
        default:
            printf("%sErreur : Heu, il faut que je comprenne ... c'est pas normal mais bon erreur quand meme%s\n", TEXT_RED, DEFAULT_COLOR);
    };

    printf("\n%sManuel pour l'execution du programme :%s\n", TEXT_CYAN, DEFAULT_COLOR);
    printf("\tSi le programme est lancer sans parametres, ce dernier va choisir un nombre de cellules aleatoirement est lancer l'execution.\n\n");
    
    printf("\t%s%s%s                   - pour afficher ce manuel\n", TEXT_YELLOW, _YG_PARAM_HELP_, DEFAULT_COLOR);
    printf("\t%s%s %s<number>%s - permet de selectionner le nombre de cellules pour la simulation, le nombre dois etre superieur a zero\n", TEXT_YELLOW, _YG_PARAM_CELLS_, TEXT_GREEN, DEFAULT_COLOR);
    printf("\t%s%s %s<number>%s          - permet de choisir le nombre de generation a effectuer: par default 100\n", TEXT_YELLOW, _YG_PARAM_DAYS_, TEXT_GREEN, DEFAULT_COLOR);

    exit(error);
}
