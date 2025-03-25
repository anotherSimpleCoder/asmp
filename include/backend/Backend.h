//
// Created by amsakan on 25.03.25.
//

#ifndef ASMP_H
#define ASMP_H

#include <string>

#include "AudioFileReader.h"
#include "AudioFilePlayer.h"

class Backend {
    AudioFileReader audioFileReader;
    AudioFilePlayer audioFilePlayer;

public:
    Backend(
      AudioFileReader audioFileReader,
      AudioFilePlayer audioFilePlayer
    );

    void play_file(std::string filepath);
};
#endif //ASMP_H
