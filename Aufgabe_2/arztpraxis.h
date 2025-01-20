#ifndef ARZTPRAXIS_H
#define ARZTPRAXIS_H

#include <string>
#include <vector>
#include "termin.h"

class Arztpraxis {
private:
    const std::string name = "Dr. Koch";
    std::vector<Termin> terminListe;
public:
    Arztpraxis();
    bool terminAnlegen(std::string patient, std::string datumUhrzeit);
    bool terminLoeschen(std::string patient);
};

#endif // ARZTPRAXIS_H
