#ifndef TERMIN_H
#define TERMIN_H

#include <string>

enum class Impfstoff {
    Biontech,
    Moderna,
    AstraZeneca,
    JohnsoJohnson
};

const std::string impfstoffName[] = {
    "Biontech", "Moderna", "AstraZeneca", "Johnson&Johnson"
};

class Termin {
private:
    std::string datumUhrzeit;
    std::string patient;
    Impfstoff impfstoff;
    bool geloescht;
public:
    Termin(std::string datumUhrzeit, std::string patient, Impfstoff impfstoff);
    bool operator >(const Termin& termin);
    std::string getDatumUhrzeit() const;
    std::string getPatient() const;
    bool getGeloescht() const;
    void setGeloescht(const bool& newGeloescht);
    Impfstoff getImpfstoff() const;
};

#endif // TERMIN_H
