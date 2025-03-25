#include "Backend.h"

Backend::Backend(AudioFileReader audioFileReader, AudioFilePlayer audioFilePlayer) {
    this->audioFileReader = audioFileReader;
    this->audioFilePlayer = audioFilePlayer;
}

void Backend::play_file(std::string filepath) {
    auto audioFile = this->audioFileReader.read(filepath);
    audioFilePlayer.play(&audioFile);
}
