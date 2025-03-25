//
// Created by amsakan on 25.03.25.
//

#ifndef UI_H
#define UI_H

#include "Backend.h"

class UI {
protected:
    Backend* backend;

public:
    UI(Backend* backend);
    virtual void run(int argc, char** argv) = 0;
};
#endif //UI_H
