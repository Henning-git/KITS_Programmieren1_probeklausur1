#include "termin.h"

Termin::Termin(std::string datumUhrzeit, std::string patient) {
    this->datumUhrzeit = datumUhrzeit;
    this->patient = patient;
    this->geloescht = false;
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
