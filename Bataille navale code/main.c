//Pierrot Métille
//3.3.2021
//0.1

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main() {
    SetConsoleOutputCP(65001);

    int mode;
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
           "1. Apprendre a jouer\n2. Jouer\nJe choisi l'option no:");
    scanf("%d",&mode);

    if (mode == 1){
        system("cls");
        //<editor-fold desc="Bienvenu BN">
        printf(" ____  _                                       _                   _\n"
               "| __ )(_) ___ _ ____   _____ _ __  _   _    __| | __ _ _ __  ___  | | __ _\n"
               "|  _ \\| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| | | |  / _` |/ _` | '_ \\/ __| | |/ _` |\n"
               "| |_) | |  __/ | | \\ V /  __/ | | | |_| | | (_| | (_| | | | \\__ \\ | | (_| |\n"
               "|____/|_|\\___|_| |_|\\_/ \\___|_| |_|\\__,_|  \\__,_|\\__,_|_| |_|___/ |_|\\__,_|\n"
               "\n"
               " ____        _        _ _        _   _                  _        _\n"
               "| __ )  __ _| |_ __ _(_) | ___  | \\ | | __ ___   ____ _| | ___  | |\n"
               "|  _ \\ / _` | __/ _` | | |/ _ \\ |  \\| |/ _` \\ \\ / / _` | |/ _ \\ | |\n"
               "| |_) | (_| | || (_| | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/ |_|\n"
               "|____/ \\__,_|\\__\\__,_|_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___| (_)\n");
        //</editor-fold>
        printf("\nvoici une petite explication des règle\n");
        //<editor-fold desc="Tableau Brut">
        printf("  1 2 3 4 5 6 7 8 9 10  Les ○ représente les case ou le joueur\n"
               "A ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   n'a pas encore tiré\n"
               "B ○ ○ ○ ○ ○ ○ ○ ○ ○ ○   Les X représente les cases ou le joueur a tiré mais pas touché\n"
               "C ○ ○ ○ ○ ○ ○ ○ ○ ○ ○\n"
               "D ○ ○ ○ ○ ○ ○ ○ ○ ○ ○\n"
               "E ○ ○ ○ ○ ○ ○ ○ ○ ○ ○\n"
               "F ○ ○ ○ ○ ○ ○ ○ ○ ○ ○\n"
               "G ○ ○ ○ ○ ○ ○ ○ ○ ○ ○\n"
               "H ○ ○ ○ ○ ○ ○ ○ ○ ○ ○\n"
               "I ○ ○ ○ ○ ○ ○ ○ ○ ○ ○\n"
               "J ○ ○ ○ ○ ○ ○ ○ ○ ○ ○\n"
               "Voici un Champs de bataille\n");
        //</editor-fold>

    }






    return 0;
}
