#include "AudioFile.h"

#include <utility>
#include "InvalidAudioFileException.h"

AudioFile::AudioFile(std::string filename, std::vector<float> data) {
    if (filename.empty()) {
        throw InvalidAudioFileException();
    }

    this->filename = std::move(filename);
    this->data = std::move(data);
}