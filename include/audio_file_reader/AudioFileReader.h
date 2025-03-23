#ifndef AUDIOFILEREADER_H
#define AUDIOFILEREADER_H
#include <string>
#include <filesystem>

#include <sndfile.hh>

#include "AudioFile.h"
#include "AudioFileNotFoundException.h"

namespace fs = std::filesystem;

class AudioFileReader {
  public:
    AudioFile read(std::string path);
};
#endif AUDIOFILEREADER_H
