#ifndef CLI_H
#define CLI_H

#include "UI.h"

class CLI : public UI {
public:
    CLI()
    : UI(
        new Backend(
            AudioFileReader(),
            AudioFilePlayer()
        )
    ){};

    void run(int argc, char** argv) override;
    virtual ~CLI() = default;
};
#endif //CLI_H
