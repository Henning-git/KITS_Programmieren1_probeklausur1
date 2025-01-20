#include "arztpraxis.h"
#include <iostream>

Arztpraxis::Arztpraxis() {}

bool Arztpraxis::terminAnlegen(std::string patient, std::string datumUhrzeit) {
    // verify free timeslot
    for(Termin& termin: terminListe) {
        if(termin.getGeloescht() == false && termin.getDatumUhrzeit() == datumUhrzeit) {
            return false;
        }
    }

    // add termin to list
    Termin newTermin(datumUhrzeit, patient);
    terminListe.push_back(newTermin);

    return true;
}

bool Arztpraxis::terminLoeschen(std::string patient) {
    // find termin to be deleted
    for(Termin& termin: terminListe) {
        if(termin.getGeloescht() == false && termin.getPatient() == patient) {
            termin.setGeloescht(true);
            return true;
        }
    }

    return false;
}
