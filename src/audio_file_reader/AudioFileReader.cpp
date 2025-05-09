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

    auto audioData = new float[file.frames()];
    file.read(audioData, file.frames());

    return {path, audioData};
}
