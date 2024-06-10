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
 * @date 2024-06-10
*/
int parse_check(const int param_count, const char **param) {
    int i = 0;

    srand((unsigned int)time(NULL));

    /* set des valeurs par default pour en cas de non renseignement */
    parameters.init_cellules_count = (rand() % _YG_RAND_MAX_CELLS_) + 1;
    parameters.max_day = _YG_MIN_DAYS_;
    parameters.delay_sleeping = _YG_DEFAULT_WAIT_;
    parameters.set_x = -1;
    parameters.set_y = -1;
    bzero(parameters.export_file, sizeof(char) * (unsigned long)(MAX_SIZE_FILE_NAME + 1));

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

            if (parameters.max_day <= 1) return _YG_BAD_DAYS_INPUT_;
            continue;
        }

        /* extraire le delai entre chaque interationn */
        if (strcmp(param[i], _YG_PARAM_WAIT_) == 0) {
            if (++i >= param_count) return _YG_BAD_WAIT_INPUT_;

            sscanf(param[i], "%d", &(parameters.delay_sleeping));

            if (parameters.delay_sleeping < 0) return _YG_BAD_WAIT_INPUT_;
            continue;
        }

        /* extraire la taille x */
        if (strcmp(param[i], _YG_PARAM_MAX_X_) == 0) {
            if (++i >= param_count) return _YG_BAD_SET_X_;

            sscanf(param[i], "%d", &(parameters.set_x));

            if (parameters.set_x < MIN_X_SIZE) return _YG_BAD_SET_X_;
            continue;
        }

        /* extraire la taille y */
        if (strcmp(param[i], _YG_PARAM_MAX_Y_) == 0) {
            if (++i >= param_count) return _YG_BAD_SET_Y_;

            sscanf(param[i], "%d", &(parameters.set_y));

            if (parameters.set_y < MIN_Y_SIZE) return _YG_BAD_SET_Y_;
            continue;
        }

        /* extraire le fichier de sortie */
        if (strcmp(param[i], _YG_PARAM_CSV_EXPORT_) == 0) {
            if (++i >= param_count) return _YG_BAD_EXPORT_FILE_;

            strncpy(parameters.export_file, param[i], (size_t)MAX_SIZE_FILE_NAME);

            if (strlen(param[i]) > MAX_SIZE_FILE_NAME) return _YG_BAD_EXPORT_FILE_;
            if (strlen(parameters.export_file) == (size_t)0) return _YG_BAD_EXPORT_FILE_;
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
 * @date 2024-06-10
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
        case _YG_BAD_WAIT_INPUT_:
            printf("%sErreur : parametre %s doit etre superieur ou egal a zero ou n'est pas définie%s\n", TEXT_RED, _YG_PARAM_WAIT_, DEFAULT_COLOR); break;
        case _YG_BAD_SET_X_:
            printf("%sErreur : parametre %s doit etre superieur a %d%s\n", TEXT_RED, _YG_PARAM_MAX_X_, MIN_X_SIZE, DEFAULT_COLOR); break;
        case _YG_BAD_SET_Y_:
            printf("%sErreur : parametre %s doit etre superieur a %d%s\n", TEXT_RED, _YG_PARAM_MAX_Y_, MIN_Y_SIZE, DEFAULT_COLOR); break;
        case _YG_BAD_EXPORT_FILE_:
            printf("%sErreur : parametre %s, recuperation du nom du fichier (la taille de la chaine peut etre trop importante)%s\n", TEXT_RED, _YG_PARAM_CSV_EXPORT_, DEFAULT_COLOR); break;

        case _YG_SHOW_MAN_: error = 0; break;
        default:
            printf("%sErreur : Heu, il faut que je comprenne ... c'est pas normal mais bon erreur quand meme%s\n", TEXT_RED, DEFAULT_COLOR);
    };

    printf("\n%sManuel pour l'execution du programme :%s\n", TEXT_CYAN, DEFAULT_COLOR);
    printf("\tSi le programme est lancer sans parametres, ce dernier va choisir un nombre de cellules aleatoirement est lancer l'execution.\n\n");
    
    printf("\t%s%s%s                     - pour afficher ce manuel\n", TEXT_YELLOW, _YG_PARAM_HELP_, DEFAULT_COLOR);
    printf("\t%s%s %s<number>%s   - permet de selectionner le nombre de cellules pour la simulation, le nombre dois etre superieur a zero\n", TEXT_YELLOW, _YG_PARAM_CELLS_, TEXT_GREEN, DEFAULT_COLOR);
    printf("\t%s%s %s<number>%s            - permet de choisir le nombre de generation a effectuer: par default 100\n", TEXT_YELLOW, _YG_PARAM_DAYS_, TEXT_GREEN, DEFAULT_COLOR);
    printf("\t%s%s %s<number>%s           - permet de selectionner le delay entre chaque jours. nombre en microseconde. Par defaut, 1s\n", TEXT_YELLOW, _YG_PARAM_WAIT_, TEXT_GREEN, DEFAULT_COLOR);
    printf("\t%s%s %s<number>%s          - permet de definir la taille en x de la grille de jeu. La valeur doit etre superieur a %d et inferieur a la taille de la fenetre\n", TEXT_YELLOW, _YG_PARAM_MAX_X_, TEXT_GREEN, DEFAULT_COLOR, MIN_X_SIZE);
    printf("\t%s%s %s<number>%s          - permet de definir la taille en y de la grille de jeu. La valeur doit etre superieur a %d et inferieur a la taille de la fenetre\n", TEXT_YELLOW, _YG_PARAM_MAX_Y_, TEXT_GREEN, DEFAULT_COLOR, MIN_Y_SIZE);

    printf("\n\t%s%s %s<file>%s        - permet d'exporter le nombre de cellules par interation au format CSV\n", TEXT_YELLOW, _YG_PARAM_CSV_EXPORT_, TEXT_GREEN, DEFAULT_COLOR);

    exit(error);
}
