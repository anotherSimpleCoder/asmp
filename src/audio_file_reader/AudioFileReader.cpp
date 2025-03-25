#include <sndfile.hh>

#include "AudioFileReader.h"
#include "AudioFileNotFoundException.h"
#include "NoAudioFileException.h"

AudioFile AudioFileReader::read(const std::string path) {
    if (!fs::exists(path)) {
        throw AudioFileNotFoundException(path);
    }

    auto file = SndfileHandle(path);
    bool isValidFormat = SndfileHandle::formatCheck(file.format(), file.channels(), file.samplerate());
    if (!isValidFormat) {
        throw NoAudioFileException(path);
    }

    auto buffer = new float[file.frames()];
    file.read(buffer, file.frames());

    std::vector audioData(buffer, buffer + file.frames());
    delete buffer;

    return {path, audioData};
}
