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
                std::cout << "\tPatienten Name: ";
                std::string patienName;
                std::cin >> patienName;

                std::cout << "\tImpfstoff (1: Biontech, 2: Moderna, 3: Astra Zeneca, 4: Johnson&Johnson: ";
                Impfstoff impfstoff;
                int i;
                std::cin >> i;
                impfstoff = (Impfstoff)i;

                bool success = false;
                while(!success) {
                    // ersten Termin abfragen
                    if(impfstoff == Impfstoff::Biontech || impfstoff == Impfstoff::Moderna || impfstoff == Impfstoff::AstraZeneca) {
                        std::cout << "\tDatum und Uhrzeit 1/2 \"dd.mm.yyyy:hhmm: ";
                    }
                    else {
                        std::cout << "\tDatum und Uhrzeit 1/1 \"dd.mm.yyyy:hhmm: ";
                    }

                    std::string zeitDatum;
                    std::cin >> zeitDatum;

                    success = arztpraxis.terminAnlegen(patienName, zeitDatum, impfstoff);
                    if(!success) {
                        std::cout << "\tDer Termin ist schon belegt. Versuche es erneut" << std::endl;
                    }
                }
                std::cout << "\tTermin erfolgreich gespeichert." << std::endl;

                if(impfstoff == Impfstoff::Biontech || impfstoff == Impfstoff::Moderna || impfstoff == Impfstoff::AstraZeneca) {
                    success = false;
                    while(!success) {
                        // zweiten Termin abfragen
                        std::cout << "\tDatum und Uhrzeit 2/2 \"dd.mm.yyyy:hhmm: ";
                        std::string zeitDatum;
                        std::cin >> zeitDatum;

                        success = arztpraxis.terminAnlegen(patienName, zeitDatum, impfstoff);
                        if(!success) {
                            std::cout << "\tDer Termin ist schon belegt. Versuche es erneut" << std::endl;
                        }
                    }
                    std::cout << "\tTermin erfolgreich gespeichert." << std::endl;
                }

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
