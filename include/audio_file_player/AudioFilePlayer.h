//
// Created by amsakan on 25.03.25.
//

#ifndef AUDIOFILEPLAYER_H
#define AUDIOFILEPLAYER_H

#include "AudioFile.h"

class AudioFilePlayer {
    unsigned int sampleRate = 44100;
    unsigned int bufferSize = 256;

public:
    void play(AudioFile* fileToPlay);
};

#endif
