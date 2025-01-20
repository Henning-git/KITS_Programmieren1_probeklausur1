#ifndef CALLCENTER_H
#define CALLCENTER_H

#include "arztpraxis.h"

class Callcenter {
private:
    Arztpraxis arztpraxis;
    void printMainMenu();
public:
    Callcenter();
    void dialog();
};

#endif // CALLCENTER_H
