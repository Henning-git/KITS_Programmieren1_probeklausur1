#include "arztpraxis.h"
#include <iostream>

Arztpraxis::Arztpraxis(const std::string& name) {
    this->name = name;
}

Arztpraxis::~Arztpraxis() {}

std::vector<Termin*> Arztpraxis::sortTermine() {
    std::vector<Termin*> buf;
    // initialize buf with pointers to terminListe entrys
    for(Termin& termin: terminListe) {
        buf.push_back(&termin);
    }

    // bubble sort
    if(buf.size() >= 2) {
        for(int i = 0; i < buf.size() - 1; i++) {
            for(int j = i + 1; j < buf.size(); j++) {
                if(*(buf[i]) > *(buf[j])) {
                    // swapt i and j
                    Termin* temp = buf[i];
                    buf[i] = buf[j];
                    buf[j] = temp;
                }
            }
        }
    }

    return buf;
}

std::string Arztpraxis::getName() const {
    return name;
}

bool Arztpraxis::terminAnlegen(std::string patient, std::string datumUhrzeit, Impfstoff impfstoff) {
    // verify free timeslot
    for(Termin& termin: terminListe) {
        if(termin.getGeloescht() == false && termin.getDatumUhrzeit() == datumUhrzeit) {
            return false;
        }
    }

    // add termin to list
    Termin newTermin(datumUhrzeit, patient, impfstoff);
    terminListe.push_back(newTermin);

    return true;
}

bool Arztpraxis::terminLoeschen(std::string patient) {
    // find termin to be deleted
    bool success = false;
    for(Termin& termin: terminListe) {
        if(termin.getGeloescht() == false && termin.getPatient() == patient) {
            termin.setGeloescht(true);
            success = true;
        }
    }

    return success;
}

std::string Arztpraxis::getTerminuebersicht() {
    std::string out;

    // add Praxisname
    out += "\t" + name + "\n";

    // sort
    std::vector<Termin*> sorted = sortTermine();
    for(const Termin* termin: sorted) {
        out += "\t\t" + termin->getPatient() + " " + termin->getDatumUhrzeit() + " " + impfstoffName[(int)termin->getImpfstoff()] + "\n";
    }

    return out;
}
