#include "AudioFileReader.h"

AudioFile AudioFileReader::read(const std::string path) {
    if (!fs::exists(path)) {
        throw AudioFileNotFoundException(path);
    }

    auto file = SndfileHandle(path);
    bool isValidFormat = file.formatCheck(file.format(), file.channels(), file.samplerate());
    if (!isValidFormat) {

    }


    float* buffer = new float[file.frames()];
    file.read(buffer, file.frames());

    return {path, buffer};
}
