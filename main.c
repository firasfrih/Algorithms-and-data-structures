#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "cds.h"
#include "tools.h"
#include "datetime.h"
#include "datastructure.h"
#include "database.h"




int main() {
    int choice;
    char title[] = "CD-Verwaltung Deluxe";
    char menuoptions[7][50]= {"Neue CD anglegen", "CD bearbeiten", "CD loeschen", "Suchen","Sortieren", "Auflisten","Programm beenden"};

    load();
waitForEnter();
    do {
        choice = getmenu(title,menuoptions);
                switch (choice) {
        case 1 :
            createCD();
            save();
            waitForEnter();
            break;

        case 2 :
            editCD();
            waitForEnter();
            break;

        case 3 :
            deleteCD();
            waitForEnter();
            break;

        case 4 :
            searchSong();
            waitForEnter();
            break;

        case 5 :
            sortCD();
            //waitForEnter();
            break;

        case 6 :

            listCD();
            waitForEnter();
            break;
        case 7 :
            if (!askYesOrNo("Programm beenden?(j/n)\n"))
               choice = 0;
            break;

        default :
            break;
        }


    } while (choice != 7);
   if(askYesOrNo("Moechten sie speicher?(j/n)\n"))
      save();
    return 0;
}
