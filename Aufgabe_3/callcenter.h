#ifndef CALLCENTER_H
#define CALLCENTER_H

#include <vector>
#include "arztpraxis.h"

class Callcenter {
private:
    std::vector<Arztpraxis*> praxisListe;
    void printMainMenu();
    Arztpraxis* selectPraxis();
public:
    Callcenter();
    ~Callcenter();
    void dialog();
};

#endif // CALLCENTER_H
