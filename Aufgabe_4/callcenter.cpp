#include "callcenter.h"
#include <string>
#include <iostream>
#include <limits>

void Callcenter::printMainMenu() {
    // print main menu
    std::cout << "Hauptmenue:" << std::endl
              << "1: Termin anlegen" << std::endl
              << "2: Termin loeschen" << std::endl
              << "3: Arztpraxis anlegen" << std::endl
              << "4: Terminuebersicht" << std::endl
              << "0: Programm beenden" << std::endl;
}

Arztpraxis* Callcenter::selectPraxis() {
    std::cout << "\tWaehle eine Praxis: ";
    std::string praxisName;
    std::cin >> praxisName;

    for(Arztpraxis* praxis: praxisListe) {
        if(praxis->getName() == praxisName) {
            return praxis;
        }
    }

    return nullptr;
}

Callcenter::Callcenter() {}

Callcenter::~Callcenter() {
    // delete all Arztpraxen
    for(Arztpraxis* praxis: praxisListe) {
        delete praxis;
    }
}

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
                // -------- select praxis --------
                if(praxisListe.size() == 0) {
                    std::cout << "\tNoch keine Praxis vorhanden." << std::endl;
                    break;
                }
                Arztpraxis* praxis = nullptr;
                while(!praxis) {
                    praxis = selectPraxis();
                    if(!praxis) {
                        std::cout << "\tDiese Praxis existiert nicht." << std::endl;
                    }
                }

                // -------- Termin anlegen --------
                std::cout << "\tPatienten Name: ";
                std::string patienName;
                std::cin >> patienName;

                std::cout << "\tImpfstoff (1: Biontech, 2: Moderna, 3: Astra Zeneca, 4: Johnson&Johnson: ";
                Impfstoff impfstoff;
                int i;
                std::cin >> i;
                impfstoff = (Impfstoff)(i-1);

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

                    success = praxis->terminAnlegen(patienName, zeitDatum, impfstoff);
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

                        success = praxis->terminAnlegen(patienName, zeitDatum, impfstoff);
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
                // -------- select praxis --------
                if(praxisListe.size() == 0) {
                    std::cout << "\tNoch keine Praxis vorhanden." << std::endl;
                    break;
                }
                Arztpraxis* praxis = nullptr;
                while(!praxis) {
                    praxis = selectPraxis();
                    if(!praxis) {
                        std::cout << "\tDiese Praxis existiert nicht." << std::endl;
                    }
                }

                // -------- termine Löschen --------
                std::cout << "\tPatienten Name: ";
                std::string patienName;
                std::cin >> patienName;

                bool success = praxis->terminLoeschen(patienName);
                if(!success) {
                    std::cout << "\tFuer diese Person konnte kein Termin gefunden werden." << std::endl;
                }
                else {
                    std::cout << "\tTermin erfolgreich geloescht." << std::endl;
                }

                printMainMenu();
                break;
            }

            // -------- Arztpraxis anlegen --------
            case '3': {
                std::cout << "\tPraxisname: ";
                std::string praxisName;
                std::cin >> praxisName;

                praxisListe.push_back(new Arztpraxis(praxisName));
                std::cout << "\tPraxis erfolgreich gespeichert." << std::endl;

                printMainMenu();
                break;
            }

            // -------- Terminübersicht --------
            case '4': {
                if(praxisListe.size() == 0) {
                    std::cout << "\tNoch keine Praxis vorhanden" << std::endl;
                }

                for(Arztpraxis* praxis: praxisListe) {
                    std::cout << praxis->getTerminuebersicht() << std::endl;
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
