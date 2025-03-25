#include "CLI.h"
#include <string>


int main(int argc, char** argv) {
    const auto cli = new CLI();
    cli->run(argc, argv);
    return 0;
}