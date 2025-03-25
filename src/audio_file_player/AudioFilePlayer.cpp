#include <rtaudio/RtAudio.h>

#include "AudioFilePlayer.h"
#include "InvalidAudioFileException.h"

int audioFileCallback(
    void *outputBuffer,
    void *inputBuffer,
    unsigned int nBufferFrames,
    double streamTime,
    RtAudioStreamStatus status,
    const AudioFile *userData
) {
    float* floatOutputBuffer = static_cast<float*>(outputBuffer);
    std::vector<float> fileAudio = userData->data;

    for (int i = 0; i < nBufferFrames; i++) {
        for (auto sample: fileAudio) {
            *floatOutputBuffer++ = sample;
        }
    }
    return 0;
}

void AudioFilePlayer::play(AudioFile *fileToPlay) {
    if (fileToPlay == nullptr) {
        throw InvalidAudioFileException();
    }

    RtAudio *dac = new RtAudio();
    dac->setErrorCallback([](RtAudioErrorType type,const std::string &errorText ) {
        throw ASMPException("Error while setting up audio drivers: " + errorText);
    });

    RtAudio::StreamParameters parameters {
        dac->getDefaultOutputDevice(),
        2,
        0
    };

    dac->openStream(
        &parameters,
        nullptr,
        RTAUDIO_FLOAT32,
        this->sampleRate,
        &(this->bufferSize),
        reinterpret_cast<RtAudioCallback>(&audioFileCallback),
        fileToPlay
    );
    dac->startStream();

    std::cin.get();

    if (dac->isStreamRunning()) {
        dac->stopStream();
    }

    if (dac->isStreamOpen()) {
        dac->closeStream();
    }

    delete dac;
}

