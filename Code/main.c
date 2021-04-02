//Pierrot Métille
//Bataille Navale
//Projet crée dans le cadre des modules MA 20 et ICT 431
//17.03.2021-
//Version 1

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
//<editor-fold desc="Déclaration de variable">

int MODE = 10, stop = 1, colonne = 11, gagner = 2, score, message,numBateau;
char ligne = 'K', ligneSaisie, tableauJoueur[10][10];

//1,2=Sous-Marin/3=Port-Avion/4 =Torpilleur/5=Croiseur, les tableau sont dans des fichiers externes
int tableauBateaux[10][10];
int sousMarin = 2, sousMarin1Vie = 0, sousMarin2Vie = 0, portAvion = 1, portAvionVie = 0, torpilleur = 1, torpilleurVie = 0, croiseur = 1, croiseurVie = 0;
char lettre[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
//</editor-fold>

//Cette fonction est utilisé pour choisir un champs de travaille aléatoire
void bateauxAleatoir(){
    srand(time(NULL));
    int bAlea;
    char carac, nAleaDansFichier[50];

    bAlea = rand() % 4 + 1;
    FILE* fichier = NULL;
    sprintf(nAleaDansFichier,"../Battefield/B%d.txt",bAlea);
    fichier = fopen(nAleaDansFichier, "r");

        for (int y = 0; y < 10; ++y) {
            for (int z = 0; z < 10; ++z) {
                carac = fgetc(fichier);
                    tableauBateaux[y][z] = carac;
            }
        }
}

//Cette fonction Affiche L'aide de jeux
void aideDeJeux(){
    //<editor-fold desc="Bienvenu BN">
    printf(" ____  _                                            _\n"
           "| __ )(_) ___ _ ____   _____ _ __  _   _  ___    __| | __ _ _ __  ___\n"
           "|  _ \\| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| | | |/ _ \\  / _` |/ _` | '_ \\/ __|\n"
           "| |_) | |  __/ | | \\ V /  __/ | | | |_| |  __/ | (_| | (_| | | | \\__ \\\n"
           "|____/|_|\\___|_| |_|\\_/ \\___|_| |_|\\__,_|\\___|  \\__,_|\\__,_|_| |_|___/\n"
           "\n"
           " _         ____        _        _ _ _        _   _                  _        _\n"
           "| | __ _  | __ )  __ _| |_ __ _(_) | | ___  | \\ | | __ ___   ____ _| | ___  | |\n"
           "| |/ _` | |  _ \\ / _` | __/ _` | | | |/ _ \\ |  \\| |/ _` \\ \\ / / _` | |/ _ \\ | |\n"
           "| | (_| | | |_) | (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/ |_|\n"
           "|_|\\__,_| |____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___| (_)\n");
    //</editor-fold>
    printf("\nvoici une petite explication des règle\n\n");
    //<editor-fold desc="Tableau et règle en printf">
    printf("  1 2 3 4 5 6 7 8 9 10  Les ○ représentent les cases où le joueur\n"
           "A ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   n'a pas encore tiré\n"
           "B ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   Les X représentent les cases où le joueur a\n"
           "C ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   tiré mais pas touché\n"
           "D ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   Les T sont les cases où le joueur a touché\n"
           "E ○ ○ ○ ○ ○ T X ○ ○ ○\n"
           "F ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   Il y a différents type de bateaux:\n"
           "G ○ ○ ○ ○ ○ ○ ○ ○ ○ ○\n"
           "H ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   1 Porte Avion = 5 T\n"
           "I ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   1 Croiseur = 4 T\n"
           "J ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   2 Sous-Marins = 3 T chacun\n"
           "↑ exemple de partie     1 Torpilleur = 2 T\n"
           "\nIl faut donc entrer des coordonées dans le but de toucher\nles navires ennemi, Exemple:\n"
           "E7 touche, E8 ne touche pas\n\n");
    //</editor-fold>
}

//Cette fonction nettoie le terminal grace a l'instruction sysème cls
void clear(){
    system("cls");}

//Cette fonction affiche la page d'accueil
void accueil(){
    //<editor-fold desc="Bataille Navale en ASCII">
    printf(" ____        _        _ _ _        _   _                  _\n"
           "| __ )  __ _| |_ __ _(_) | | ___  | \\ | | __ ___   ____ _| | ___\n"
           "|  _ \\ / _` | __/ _` | | | |/ _ \\ |  \\| |/ _` \\ \\ / / _` | |/ _ \\\n"
           "| |_) | (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/\n"
           "|____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___|\n");
    //</editor-fold>
    //<editor-fold desc="Bateau en ASCII">
    printf("                                        .\n"
           "                           .                 |\n"
           "                           +                 |\n"
           "                  .        |                *+W+-*\n"
           "     .           +y        +W+              . H                 .\n"
           "  .  +y            |I.   y  |               ! H= .           .  ^\n"
           "  !   \\     .     |H '. /   |  ___.        .! H  !   +--.--y !  V\n"
           "  !    \\     \\  +=|H|=='.=+ | |====\\   _  '_H_H__H_. H_/=  J !  !\n"
           ". !     \\'    VVV_HHH_/__'._H |  E  \\_|=|_|========|_|==|____H. ! _______.\n"
           "I-H_I=I=HH_==_|I_IIIII_I_I_=HH|======.I-I-I-=======-I=I=I=I_=H|=H'===I=I/\n"
           "\\                                                                      ,\n"
           " |                                                                    /\n"
           " .___________________________________________________________________'\n");
    //</editor-fold>
}

//Cette fonction Affiche la page gagner
void joueurGagne(){
    MODE = 5;
    printf(" ______   _______  _______           _______    _ \n"
           "(  ___ \\ (  ____ )(  ___  )|\\     /|(  ___  )  ( )\n"
           "| (   ) )| (    )|| (   ) || )   ( || (   ) |  | |\n"
           "| (__/ / | (____)|| (___) || |   | || |   | |  | |\n"
           "|  __ (  |     __)|  ___  |( (   ) )| |   | |  | |\n"
           "| (  \\ \\ | (\\ (   | (   ) | \\ \\_/ / | |   | |  (_)\n"
           "| )___) )| ) \\ \\__| )   ( |  \\   /  | (___) |   _ \n"
           "|/ \\___/ |/   \\__/|/     \\|   \\_/   (_______)  (_)\n");
}

/**
 * Cette fonction Affiche les options disponibles
 * et @return la variable MODE
 */
int queFair(){
    do {
        printf("Que voulez-vous faire maintenant ?\n│ 0. Accueil │ 1. Apprendre à Jouer │ 2. Jouer │ 3. Voir les scores │ 4. Quitter │\n");
        printf("Je veut :");
        scanf("%d", &MODE);
        fflush(stdin);
        //Ajout d'une 4 emm option pour directement afficher la fenêtre de victoire
    }while (MODE > 5 || MODE < 0);
    return MODE;
}

//Cette fonction crée et écris dans le fichier scores le nom et le score de l'utilisateur
void newFichier() {
    char nom[100];
    printf("Quel est ton nom ?\n");
    scanf("%s", &nom);
    fflush(stdin);
    FILE* fichier = NULL;
    fichier = fopen("../Data/Scores.txt", "a");
    fprintf(fichier, "%s %d\n",nom, score);
    printf("Bravo %s ton score est %d ! Plus ton score est haut, moin il est bon.\nLe meilleur score à obtenir est 17 !\n", nom, score);
    fclose(fichier);
}

//Cette fonction est l'entier du programme qui permet de jouer
void jouerDoWhile(){
    //initialisation des valeurs du tableau joueur
    for (int y = 0; y < 10; ++y) {
        for (int z = 0; z < 10; ++z) {
            tableauJoueur[y][z] = 'o';
        }
    }
    bateauxAleatoir();
    for (int y = 0; y < 10; ++y) {
        printf("\n");
        for (int z = 0; z < 10; ++z) {
                printf("%c",tableauBateaux[y][z]);
        }
    }
    system("pause");
    do {
        clear();
        score = 0;
        message = 0;
        //Affiche le tableau
        clear();
        printf("  1 2 3 4 5 6 7 8 9 10\n");
        for (int i = 0; i < 10; ++i) {

            printf("%c ", lettre[i]);

            for (int j = 0; j < 10; ++j) {

                //Dès que la ligne et la colonne saisie correspond à la case qui va êtres affichée, vérifie si il y a un bateau
                if (i == ligne && j == colonne) {
                    if (tableauBateaux[i][j] != '0' && tableauJoueur[i][j] != 'T' && tableauJoueur[i][j] != 'X') {
                        //Pour chaque coup tiré dans une nouvelle case occupant un bateau, le bateau en question pert une vie, dès qu'il en a plus, il est détruis
                        switch (tableauBateaux[i][j]) {
                            case 1:
                                sousMarin1Vie++;
                                if (sousMarin1Vie == 3) {
                                    sousMarin--;
                                }
                                break;
                            case 2:
                                sousMarin2Vie++;
                                if (sousMarin2Vie == 3) {
                                    sousMarin--;
                                }
                                break;
                            case 3:
                                portAvionVie++;
                                if (portAvionVie == 5) {
                                    portAvion--;
                                }
                                break;
                            case 4:
                                torpilleurVie++;
                                if (torpilleurVie == 2) {
                                    torpilleur--;
                                }
                                break;
                            case 5:
                                croiseurVie++;
                                if (croiseurVie == 4) {
                                    croiseur--;
                                }
                                break;

                        }
                        tableauJoueur[i][j] = 'T';
                        message = 1;
                    }
                    else if(tableauJoueur[i][j] == 'T' ||tableauJoueur[i][j] == 'X'){
                        message = 3;
                        score --;
                    }

                        //Si il y a aucun bateau dans la case, affiche X pour indiquer que le joueur a raté
                    else if (tableauBateaux[i][j] == '0')  {
                        tableauJoueur[i][j] = 'X';
                        message = 2;
                    }
                }
                printf("%c ", tableauJoueur[i][j]);
            }
            printf("\n");
        }

        //affiche le nombre de bateau restant
        printf("Il reste %d Porte Avion  %d Croiseur  %d Sous-Marin  %d Torpilleur", portAvion, croiseur,
               sousMarin,
               torpilleur);

        //<editor-fold desc="Système de vérification des valeurs + conversion des lettres en nombre">
        do {
            //Transforme les lettres(maj et min) en ASCII et les font correspondre à un nombre entre un et dix
            switch (message) {
                default:
                    printf("");
                    break;

                case 1:
                    printf("\n\nBravo, tu a touché(e) !");
                    break;

                case 2:
                    printf("\n\nFlûte, tu a raté(e)...");
                    break;

                case 3:
                    printf("\n\nTu a déja entré(e) cette coordonée...");
                    break;

            }
            printf("\n\nQu'elle est ta première coordonée (A, B, C, ect...)?");
            scanf("%s", &ligneSaisie);
            fflush(stdin);
            if (ligneSaisie >= 65 && ligneSaisie <= 74) ligneSaisie += 32;
            ligne = ligneSaisie - 97;
            if (ligneSaisie <= 96 || ligneSaisie >= 107) printf("Sa doit êtes entre A et J !");
        } while (ligneSaisie <= 96 || ligneSaisie >= 107); //verifie si entre A-J, sinon redemande
        score++;
        do {

            //Même chose que pour les lettres mais cette fois ci pour des nombres
            printf("\n\nQu'elle est ta seconde coordonée (1, 2, 3, ect...)?");
            scanf("%d", &colonne);
            fflush(stdin);
            colonne -= 1;
            if (colonne > 9 || colonne < 0) printf("Sa doit êtres entre 1 et 10 !");
        } while (colonne > 9 || colonne < 0);//verifie si entre 1-10
        //</editor-fold>

    }while (portAvion != 0 && croiseur != 0 && sousMarin != 0 && torpilleur);
}

//Cette fonction permet de lire dans le fichier score et de tout réecrire dans la fenètre scores
void tableauScores(){
#define TAILLE_MAX 1000
    FILE* fichier = NULL;
    fichier = fopen("../Data/Scores.txt", "r");
    char chaine[TAILLE_MAX] = "";

    if (fichier != NULL){
        printf("             _      _     _                                               \n"
               "            (_)    (_)   | |                                            _ \n"
               " __   _____  _  ___ _    | | ___  ___     ___  ___ ___  _ __ ___  ___  (_)\n"
               " \\ \\ / / _ \\| |/ __| |   | |/ _ \\/ __|   / __|/ __/ _ \\| '__/ _ \\/ __|    \n"
               "  \\ V / (_) | | (__| |   | |  __/\\__ \\   \\__ \\ (_| (_) | | |  __/\\__ \\  _ \n"
               "   \\_/ \\___/|_|\\___|_|   |_|\\___||___/   |___/\\___\\___/|_|  \\___||___/ (_)\n"
               "                                                                          \n"
               "                                                                          \n\n");
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {
            printf("%s\n", chaine);
        }
        printf("\n\n");
        fclose(fichier);
    }
    else{
        printf("Aucun scores n'a encors été fait...\n\n");
    }
}

//cette fonction est un switch utiliser dans le but de logger se qui se passe durant la Bataille Navale
void logs(){
    int hours, minutes, day, month, year, seconds;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;

    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;

    fflush(stdin);
    FILE* fichier = NULL;
    fichier = fopen("../Data/Loggs.txt", "a");

    switch (MODE) {

        case 10 :
            fprintf(fichier, "%d heure(s) %d minute(s) %d seconde(s) le %d.%d.%d : Application lancée\n", hours, minutes, seconds, day, month, year);
            break;

        case 0 :
            fprintf(fichier, "%d heure(s) %d minute(s) %d seconde(s) le %d.%d.%d : L'utilisateur est sur l'accueil\n", hours, minutes, seconds, day, month, year);
            break;

        case 1 :
            fprintf(fichier, "%d heure(s) %d minute(s) %d seconde(s) le %d.%d.%d : L'utilisateur est sur l'aide de jeux\n", hours, minutes, seconds, day, month, year);
            break;

        case 2 :
            fprintf(fichier, "%d heure(s) %d minute(s) %d seconde(s) le %d.%d.%d : L'utilisateur joue une partie\n", hours, minutes, seconds, day, month, year);
            break;

        case 3 :
            fprintf(fichier, "%d heure(s) %d minute(s) %d seconde(s) le %d.%d.%d : L'utilisateur Affiche le tableau des scores\n", hours, minutes, seconds, day, month, year);
            break;

        case 4 :
            fprintf(fichier, "%d heure(s) %d minute(s) %d seconde(s) le %d.%d.%d : L'utilisateur est sur l'accueil\n", hours, minutes, seconds, day, month, year);
            break;

        case 5 :
            fprintf(fichier, "%d heure(s) %d minute(s) %d seconde(s) le %d.%d.%d : L'utilisateur a gagner la partie\n", hours, minutes, seconds, day, month, year);
            break;

    }
    fclose(fichier);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    clear();
    logs();
    while (stop == 1) {
        switch (MODE) {
            default:
                MODE = 0;
                break;
                //Affiche de toute façon l'accueil
            case 0 :
                logs();
                clear();
                accueil();
                queFair();
                break;

                //Si 1, affiche l'aide de jeux
            case 1 :
                logs();
                clear();
                aideDeJeux();
                queFair();
                break;

                //Si 2, joue à la Bataille Navale
            case 2 :
                logs();
                jouerDoWhile();
                gagner = 1;
                break;

                //si 3, affiche les scores
            case 3 :
                logs();
                clear();
                tableauScores();
                queFair();
                break;

                //Si 4, quitte
            case 4:
                logs();
                clear();
                printf("                                        _          __       _     _            _   //\\  _     _ \n"
                       "     /\\                                (_)         \\_\\     | |   (_)          | | |/ \\|| |   | |\n"
                       "    /  \\  _   _     _ __ _____   _____  _ _ __     __ _    | |__  _  ___ _ __ | |_ ___ | |_  | |\n"
                       "   / /\\ \\| | | |   | '__/ _ \\ \\ / / _ \\| | '__|   / _` |   | '_ \\| |/ _ \\ '_ \\| __/ _ \\| __| | |\n"
                       "  / ____ \\ |_| |   | | |  __/\\ V / (_) | | |_    | (_| |   | |_) | |  __/ | | | || (_) | |_  |_|\n"
                       " /_/    \\_\\__,_|   |_|  \\___| \\_/ \\___/|_|_( )    \\__,_|   |_.__/|_|\\___|_| |_|\\__\\___/ \\__| (_)\n"
                       "                                           |/                                                   \n"
                       "                                                                                               \n");
                system("pause");
                stop = 0;
                break;
        }
        //Si tout les bateaux son détruis et donc que gagner = 1, affiche le menu de victoire + demande à l'utilisateur son nom, son score et se qu'il veut faire ensuite
        if (gagner == 1){
            clear();
            joueurGagne();
            logs();
            newFichier();
            queFair();
        }
    }



    return 0;
}
