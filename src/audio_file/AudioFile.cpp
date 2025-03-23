#include "AudioFile.h"
#include "InvalidAudioFileDataException.h"

AudioFile::AudioFile(std::string filename, float* data) {
    if (data == nullptr) {
       throw InvalidAudioFileDataException();
    }

    this->filename = filename;
    this->data = data;
}