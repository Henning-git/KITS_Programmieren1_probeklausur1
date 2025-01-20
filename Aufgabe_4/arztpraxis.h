#ifndef ARZTPRAXIS_H
#define ARZTPRAXIS_H

#include <string>
#include <vector>
#include "termin.h"

class Arztpraxis {
private:
    std::string name;
    std::vector<Termin> terminListe;
public:
    Arztpraxis(const std::string& name);
    ~Arztpraxis();
    std::string getName() const;
    bool terminAnlegen(std::string patient, std::string datumUhrzeit, Impfstoff impfstoff);
    bool terminLoeschen(std::string patient);
};

#endif // ARZTPRAXIS_H
