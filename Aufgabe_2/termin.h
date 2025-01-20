#ifndef TERMIN_H
#define TERMIN_H

#include <string>

class Termin {
private:
    std::string datumUhrzeit;
    std::string patient;
    bool geloescht;
public:
    Termin(std::string datumUhrzeit, std::string patient);
    std::string getDatumUhrzeit() const;
    std::string getPatient() const;
    bool getGeloescht() const;
    void setGeloescht(const bool& newGeloescht);
};

#endif // TERMIN_H
