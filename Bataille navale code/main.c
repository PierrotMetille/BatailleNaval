//Pierrot Métille
//3.3.2021
//0.1

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main() {
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
    scanf("%d",mode);






    return 0;
}
