#include <portaudio.h>
#include <iostream>

#include "AudioFilePlayer.h"
#include "InvalidAudioFileException.h"

PaError audioFileCallback(
    const void *outputBuffer,
    void *inputBuffer,
    unsigned long nBufferFrames,
    const PaStreamCallbackTimeInfo *timeinfo,
    PaStreamCallbackFlags statusFlags,
    void *userData
) {
    auto* floatOutputBuffer = (float*)(outputBuffer);
    auto* audioFileData = static_cast<AudioFile *>(userData);
    std::vector<float> fileAudio = audioFileData->data;

    for (int i = 0; i < nBufferFrames; i++) {
        for (auto sample: fileAudio) {
            floatOutputBuffer[i] = sample;
        }
    }
    return 0;
}

void AudioFilePlayer::play(AudioFile *fileToPlay) {
    if (fileToPlay == nullptr) {
        throw InvalidAudioFileException();
    }

    auto err = Pa_Initialize();
    if (err != paNoError ) {
        throw ASMPException("Error while setting up audio drivers: " + std::string(Pa_GetErrorText(err)));
    }

    PaStream *stream;
    err = Pa_OpenDefaultStream(
        &stream,
        0,
        2,
        paFloat32,
        this->sampleRate,
        this->bufferSize,
        audioFileCallback,
        fileToPlay
    );
    if (err != paNoError) {
        throw ASMPException("Error while opening audio stream: " + std::string(Pa_GetErrorText(err)));
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        throw ASMPException("Error while starting playback: " + std::string(Pa_GetErrorText(err)));
    }

    std::cin.get();

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        throw ASMPException("Error while stopping playback: " + std::string(Pa_GetErrorText(err)));
    }

    err = Pa_Terminate();
    if (err != paNoError ) {
        throw ASMPException("Error while shutting down audio drivers: " + std::string(Pa_GetErrorText(err)));
    }
}

