#include <iostream>
#include <portaudio.h>
#include "AudioFilePlayer.h"
#include "AudioEngineException.h"

int callback(
    const void* inputBuffer,
    void* outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void* userData
) {
    auto audioFile = (AudioFile*) userData;
    auto outputFloatBuffer = (float*) outputBuffer;

    for (int i = 0; i < framesPerBuffer; i++) {
        outputFloatBuffer[i] = audioFile->data[i];
        outputFloatBuffer[i+1] = audioFile->data[i+1];
    }

    return 0;
}

void AudioFilePlayer::play(AudioFile *fileToPlay) {
    int err = Pa_Initialize();
    if (err != paNoError) {
        throw new AudioEngineException(Pa_GetErrorText(err));
    }

    PaStream* stream;
    PaStreamParameters outputParameters = {
        Pa_GetDefaultOutputDevice(),
        2,
        paFloat32,
        Pa_GetDeviceInfo( Pa_GetDefaultOutputDevice() )->defaultLowOutputLatency,
        NULL
    };

    err = Pa_OpenStream(
        &stream,
        NULL,
        &outputParameters,
        this->sampleRate,
        this->bufferSize,
        paClipOff,
        callback,
        fileToPlay
    );
    if (err != paNoError) {
        throw new AudioEngineException(Pa_GetErrorText(err));
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        throw new AudioEngineException(Pa_GetErrorText(err));
    }

    Pa_Sleep(24000);

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        throw new AudioEngineException(Pa_GetErrorText(err));
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        throw new AudioEngineException(Pa_GetErrorText(err));
    }

    Pa_Terminate();
}





