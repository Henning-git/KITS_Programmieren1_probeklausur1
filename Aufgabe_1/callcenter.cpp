#include "callcenter.h"
#include <string>
#include <iostream>
#include <limits>

void Callcenter::printMainMenu() {
    // print main menu
    std::cout << "Hauptmenue:" << std::endl
              << "1: Termin anlegen" << std::endl
              << "2: Termin loeschen" << std::endl
              << "0: Programm beenden" << std::endl;
}

Callcenter::Callcenter() {}

void Callcenter::dialog() {
    printMainMenu();

    while(true) {
        // -------- read input --------
        std::cout << "_> ";

        char c;
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> c;

        switch(c) {
            // -------- Termin anlegen --------
            case '1': {
                bool success = false;
                while(!success) {
                    std::cout << "\tPatienten Name: ";
                    std::string patienName;
                    std::cin >> patienName;

                    std::cout << "\tDatum und Uhrzeit \"dd.mm.yyyy:hhmm: ";
                    std::string uhrzeitDatum;
                    std::cin >> uhrzeitDatum;

                    success = arztpraxis.terminAnlegen(patienName, uhrzeitDatum);
                    if(!success) {
                        std::cout << "\tDer Termin ist schon belegt. Versuche es erneut" << std::endl;
                    }
                }
                std::cout << "\tTermin erfolgreich gespeichert." << std::endl;

                printMainMenu();
                break;
            }

            // -------- Termin loeschen --------
            case '2': {
                std::cout << "\tPatienten Name: ";
                std::string patienName;
                std::cin >> patienName;

                bool success = arztpraxis.terminLoeschen(patienName);
                if(!success) {
                    std::cout << "\tFuer diese Person konnte kein Termin gefunden werden." << std::endl;
                }
                else {
                    std::cout << "\tTermin erfolgreich geloescht." << std::endl;
                }

                printMainMenu();
                break;
            }

            // -------- exit --------
            case '0': {
                return;
                break;
            }

            // -------- invalid inout --------
            default: {
                std::cout << "invalid input" << std::endl;
                break;
            }
        }
    }
    return;
}
