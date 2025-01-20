#ifndef TERMIN_H
#define TERMIN_H

#include <string>

enum class Impfstoff {
    Biontech,
    Moderna,
    AstraZeneca,
    JohnsoJohnson
};

class Termin {
private:
    std::string datumUhrzeit;
    std::string patient;
    Impfstoff impfstoff;
    bool geloescht;
public:
    Termin(std::string datumUhrzeit, std::string patient, Impfstoff impfstoff);
    std::string getDatumUhrzeit() const;
    std::string getPatient() const;
    bool getGeloescht() const;
    void setGeloescht(const bool& newGeloescht);
};

#endif // TERMIN_H
