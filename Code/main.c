//Pierrot Métille
//3.3.2021
//0.1

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int mode, stop = 1,c=11, gagner=2, nbrct = 0;//c=Colone nbrct= nombre de coup touché, utiliser pour sttoper le programme dès que l'utilisateur a toucher 17x
    char l = 'K', lsais;//l=ligne  lsais=l qui est saisie
    //tableau joueur
    char TJ[10][10];
    //<editor-fold desc="tableau et variable Bateaux">
    char TB [10][10]={//1,2=Sous-Marin/3=Port-Avion/4 =Torpilleur/5=Croiseur
            {1,3,4,5,'o','o','o','o','o','o'},
            {1,3,4,5,'o','o','o','o','o','o'},
            {1,3,4,'o','o','o','o','o','o','o'},
            {2,3,4,'o','o','o','o','o','o','o'},
            {2,3,'o','o','o','o','o','o','o','o'},
            {2,'o','o','o','o','o','o','o','o','o'},
            {'o','o','o','o','o','o','o','o','o','o'},
            {'o','o','o','o','o','o','o','o','o','o'},
            {'o','o','o','o','o','o','o','o','o','o'},
            {'o','o','o','o','o','o','o','o','o','o'}
    };
    int SM=2, PA=1, T=1, C=1;
    //</editor-fold>
    char lettre[10]={'A','B','C','D','E','F','G','H','I','J'};
    system("cls");
    //initialisation des valeur du tableau joueur
    for (int y = 0; y < 10; ++y) {
        for (int z = 0; z < 10; ++z) {
            TJ[y][z] = 'o';
        }
    }

    while (stop == 1) {
        mode = 0;
        if (mode == 0) {
            system("cls");
            //Amélioration graphique, bataille navale en gros et une image de bateau
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
            //Afficher les opions disponible, voir les précédent score et quitter ne sont pas encors disponible

            printf("Que voulez-vous faire ?\n"
                   "│ 1. Apprendre a jouer │ 2. Jouer │ 3. Quitter │\nJe veut ");
            scanf("%d", &mode);
        }
        //si entre 1, affiche l'aide de jeux
        if (mode == 1) {
            system("cls");
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
            printf("  1 2 3 4 5 6 7 8 9 10  Les ○ représente les case ou le joueur\n"
                   "A ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   n'a pas encore tiré\n"
                   "B ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   Les X représente les cases ou le joueur a\n"
                   "C ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   tiré mais pas touché\n"
                   "D ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   Les T sont les case ou le joueur a Touché\n"
                   "E ○ ○ ○ ○ ○ T X ○ ○ ○\n"
                   "F ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   Il y a différent type de bateau:\n"
                   "G ○ ○ ○ ○ ○ ○ ○ ○ ○ ○\n"
                   "H ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   1 Porte Avion = 5 T\n"
                   "I ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   1 Croiseur = 4 T\n"
                   "J ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   2 Sous-Marins = 3 T chacun\n"
                   "↑ exemple de partie     1 Torpilleur = 2 T\n"
                   "\nIl faut donc entrer des coordonée dans le but de toucher\nles navire ennemi, Exemple:\n"
                   "E7 touche, E8 ne touche pas\n");
            //</editor-fold>
            printf("Que voulez-vous faire maintenant ?\n│ 0. Accueil │ 2. Jouer │ 3. Quitter │\n");
            printf("Je veut ");
            scanf("%d", &mode);

        }
        //quitte si l'utilisateur entre 3
        if (mode == 3) {
            stop = 0;
        }

        if (mode == 2) {
            while (gagner != 1) {
                system("cls");
                if (nbrct = 17)gagner=1;//si 17 coup toucher, gagner = 1 et donc affiche le gg
                printf("  1 2 3 4 5 6 7 8 9 10\n");
                for (int i = 0; i < 10; ++i) {
                    printf("%c ", lettre[i]);
                    for (int j = 0; j < 10; ++j) {
                        if (i == l && j == c) {
                            if (TB[i][j] >= 1 && TB[i][j] <= 5)TJ[i][j] = 'T', ++nbrct;
                            else TJ[i][j] = 'X';
                        }
                        printf("%c ", TJ[i][j]);
                    }
                    printf("\n");
                }
                printf("Il reste %d Porte Avion  %d Croiseur  %d Sous-Marin  %d Torpilleur", PA, C, SM, T);

                //<editor-fold desc="Systeme de vérification des valeur + conversion des letres en nbr">
                do {
                    printf("\n\nQu'elle est ta première coordonée (A, B, C, ect...)?");
                    scanf("%s", &lsais);
                    if (lsais >= 65 && lsais <= 74) lsais += 32;
                    l = lsais - 96;
                    if (lsais <= 96 || lsais >= 107) printf("Sa doit êtes entre A et J !");
                } while (lsais <= 96 || lsais >= 107); //verifie si entre A-J

                do {

                    printf("\n\nQu'elle est ta seconde coordonée (1, 2, 3, ect...)?");
                    scanf("%d", &c);
                    if (c > 10 || c < 1) printf("Sa doit êtres entre 1 et 10 !");
                } while (c > 10 || c < 1);
                //</editor-fold>
            }
        }
        if (gagner =1){
            system("cls");
            printf(" ______   _______  _______           _______    _ \n"
                   "(  ___ \\ (  ____ )(  ___  )|\\     /|(  ___  )  ( )\n"
                   "| (   ) )| (    )|| (   ) || )   ( || (   ) |  | |\n"
                   "| (__/ / | (____)|| (___) || |   | || |   | |  | |\n"
                   "|  __ (  |     __)|  ___  |( (   ) )| |   | |  | |\n"
                   "| (  \\ \\ | (\\ (   | (   ) | \\ \\_/ / | |   | |  (_)\n"
                   "| )___) )| ) \\ \\__| )   ( |  \\   /  | (___) |   _ \n"
                   "|/ \\___/ |/   \\__/|/     \\|   \\_/   (_______)  (_)\n│ 0. Accueil │ 1. Apprendre a jouer │ 2. Jouer │ 3. Quitter │\n");
            scanf("%d",&mode);
        }

        else {
            system("cls");
            //j'ai un petit bug, il faut entrer 2 fois pour que sa marche
            printf("Ce n'est pas une option disponible ! │ 0. Accueil │ 1. Apprendre a jouer │ 2. Jouer │ 3. Quitter │");
            scanf("%d",&mode);
        }
    }





    return 0;
}
