#include "AudioFileReader.h"



AudioFile AudioFileReader::read(const std::string path) {
    if (!fs::exists(path)) {
        throw AudioFileNotFoundException(path);
    }

    auto file = SndfileHandle(path);
    float buffer[1024];
    file.read(buffer, 1024);

    return {path, buffer};
}
