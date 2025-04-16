#include <iostream>

#include "AudioFilePlayer.h"
#include "InvalidAudioFileException.h"

void AudioFilePlayer::play(AudioFile *fileToPlay) {
    if (fileToPlay == nullptr) {
        throw InvalidAudioFileException();
    }

    for (float sample : fileToPlay->data) {
        std::cout << sample << std::endl;
    }
}

