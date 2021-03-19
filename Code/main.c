//Pierrot Métille
//Bataille Navale
//17.03.2021
//Version 1

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
int MODE = 0;
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
           "E7 touche, E8 ne touche pas\n");
    //</editor-fold>
} // Affiche l'aide de jeux
void clear(){
    system("cls");} // Nettoie le terminal
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
}//Affiche l'accueil
void joueurGagne(){
    printf(" ______   _______  _______           _______    _ \n"
           "(  ___ \\ (  ____ )(  ___  )|\\     /|(  ___  )  ( )\n"
           "| (   ) )| (    )|| (   ) || )   ( || (   ) |  | |\n"
           "| (__/ / | (____)|| (___) || |   | || |   | |  | |\n"
           "|  __ (  |     __)|  ___  |( (   ) )| |   | |  | |\n"
           "| (  \\ \\ | (\\ (   | (   ) | \\ \\_/ / | |   | |  (_)\n"
           "| )___) )| ) \\ \\__| )   ( |  \\   /  | (___) |   _ \n"
           "|/ \\___/ |/   \\__/|/     \\|   \\_/   (_______)  (_)\n\n│ 0. Accueil │ 1. Apprendre a jouer │ 2. Jouer │ 3. Quitter │\n\nJe veut :");
    scanf("%d",&MODE);
    fflush(stdin);
}//Affiche le menu "gagner"
int queFair(){
    do {
        printf("Que voulez-vous faire maintenant ?\n│ 0. Accueil │ 1. Apprendre à Jouer │ 2. Jouer │ 3. Quitter │\n");
        printf("Je veut :");
        scanf("%d", &MODE);
        fflush(stdin);
    }while (MODE > 5 || MODE < 0);
    return MODE;
}//Affiche les options disponibles quand l'utilisateur entre une valeur non valable
void newFichier() {
    int nom;
    printf("est ton nom ?\n:");
    scanf("%d", &nom);
    fflush(stdin);
    FILE* fichier = NULL;
    fichier = fopen("logs/nom.txt", "a");
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int stop = 1, colonne = 11, gagner = 2;
    char ligne = 'K', ligneSaisie, tableauJoueur[10][10], nom;
    //<editor-fold desc="Tableau et variable Bateaux">
    char tableauBateaux[10][10] = {
            {1,3,4,5, 'o','o', 'o', 'o', 'o', 'o'},
            {1,3,4,5, 'o','o', 'o', 'o', 'o', 'o'},
            {1,3,4,   'o', 'o','o', 'o', 'o', 'o', 'o'},
            {2,3,4,   'o', 'o', 'o', 'o', 'o', 'o', 'o'},
            {2,3,'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
            {2,   'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
            {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
            {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
            {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
            {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'}
    };//1,2=Sous-Marin/3=Port-Avion/4 =Torpilleur/5=Croiseur
    int sousMarin = 2, sousMarin1Vie = 0, sousMarin2Vie = 0, portAvion = 1, portAvionVie = 0, torpilleur = 1, torpilleurVie = 0, croiseur = 1, croiseurVie = 0;
    //</editor-fold>
    char lettre[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    //initialisation des valeurs du tableau joueur
    for (int y = 0; y < 10; ++y) {
        for (int z = 0; z < 10; ++z) {
            tableauJoueur[y][z] = 'o';
        }
    }
    clear();
    while (stop == 1) {
        switch (MODE) {

            //Affiche de toute façon l'accueil
            case 0 :
                clear();
                accueil();
                queFair();
                break;

                //Si entre 1, affiche l'aide de jeux
            case 1 :
                clear();
                aideDeJeux();
                queFair();
                break;

                //Si 2, joue à la Bataille Navale
            case 2 :
                while (gagner != 1) {
                    clear();
                    if (portAvion == 0 && croiseur == 0 && sousMarin == 0 && torpilleur)
                        gagner = 1;//si tout les navire sont abbatu gagner = 1 et donc affiche le joueurGagner

                    //Affiche le tableau
                    clear();
                    printf("  1 2 3 4 5 6 7 8 9 10\n");
                    for (int i = 0; i < 10; ++i) {

                        printf("%c ", lettre[i]);

                        for (int j = 0; j < 10; ++j) {

                            //Dès que la ligne et la colonne saisie correspond à la case qui va êtres affichée, vérifie si il y a un bateau
                            if (i == ligne && j == colonne) {
                                if (tableauBateaux[i][j] >= 1 && tableauBateaux[i][j] <= 5 &&
                                    tableauJoueur[i][j] != 'o') {

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
                                        case 5:
                                            torpilleurVie++;
                                            if (torpilleurVie == 2) {
                                                torpilleur--;
                                            }
                                            break;
                                        case 4:
                                            croiseurVie++;
                                            if (croiseurVie == 4) {
                                                croiseur--;
                                            }
                                            break;

                                    }
                                    tableauJoueur[i][j] = 'T';
                                }

                                    //Si il y a aucun bateau dans la case, affiche X pour indiquer que le joueur a raté
                                else tableauJoueur[i][j] = 'X';
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
                        printf("\n\nQu'elle est ta première coordonée (A, B, C, ect...)?");
                        scanf("%s", &ligneSaisie);
                        fflush(stdin);
                        if (ligneSaisie >= 65 && ligneSaisie <= 74) ligneSaisie += 32;
                        ligne = ligneSaisie - 97;
                        if (ligneSaisie <= 96 || ligneSaisie >= 107) printf("Sa doit êtes entre A et J !");
                    } while (ligneSaisie <= 96 || ligneSaisie >= 107); //verifie si entre A-J, sinon redemande

                    do {

                        //Même chose que pour les lettres mais cette fois ci pour des nombres
                        printf("\n\nQu'elle est ta seconde coordonée (1, 2, 3, ect...)?");
                        scanf("%d", &colonne);
                        fflush(stdin);
                        colonne -= 1;
                        if (colonne > 9 || colonne < 0) printf("Sa doit êtres entre 1 et 10 !");
                    } while (colonne > 9 || colonne < 0);//verifie si entre 1-10
                    //</editor-fold>

                }
                break;

                //Quitte si l'utilisateur entre 3
            case 3 :
                stop = 0;
                break;

        }
    }

    //Si tout les bateaux son détruis et donc que gagner = 1, affiche le menu de victoire + demande à l'utilisateur son nom, son scor et se qu'il veut faire ensuite
    if (gagner == 1){
        clear();
        joueurGagne();
        newFichier();
        queFair();
    }

    return 0;
}
