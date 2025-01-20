#include "termin.h"
#include <iostream>

Impfstoff Termin::getImpfstoff() const {
    return impfstoff;
}

Termin::Termin(std::string datumUhrzeit, std::string patient, Impfstoff impfstoff) {
    this->datumUhrzeit = datumUhrzeit;
    this->patient = patient;
    this->impfstoff = impfstoff;
    this->geloescht = false;
}

bool Termin::operator >(const Termin &termin) {
    return patient > termin.patient;
}

std::string Termin::getDatumUhrzeit() const {
    return datumUhrzeit;
}

std::string Termin::getPatient() const {
    return patient;
}

bool Termin::getGeloescht() const {
    return geloescht;
}

void Termin::setGeloescht(const bool& newGeloescht) {
    geloescht = newGeloescht;
}
