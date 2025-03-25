#include <string>

#include "CLI.h"
#include "ASMPException.h"

void CLI::run(int argc, char** argv) {
    if (argc < 2) {
        throw ASMPException("File is missing!");
    }

    std::string filename(argv[1]);
    this->backend->play_file(filename);
}
