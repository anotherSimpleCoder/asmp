#include <string>
#include <iostream>

#include "CLI.h"
#include "exception/ASMPException.h"

void CLI::run(int argc, char** argv) {
    try {
        if (argc < 2) {
            throw ASMPException("File is missing!");
        }

        std::string filename(argv[1]);
        this->backend->play_file(filename);
    } catch (ASMPException *exception) {
        std::cerr << exception->what() << std::endl;
    }
}
