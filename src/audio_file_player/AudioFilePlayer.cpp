#include "AudioFilePlayer.h"
#include "InvalidAudioFileException.h"
#include "NoDevicesAvailableException.h"

int playback(
    void *outputBuffer,
    void *inputBuffer,
    unsigned int nBufferFrames,
    double streamTime,
    RtAudioStreamStatus status,
    void *userData
) {
    unsigned int i, j;
    float *buffer = (float *) outputBuffer;
    float *audioData = (float *) userData;

    for ( i=0; i<nBufferFrames; i++ ) {
        *buffer++ = audioData[i];
    }

    return 0;
}

void AudioFilePlayer::play(AudioFile *fileToPlay) {
    if (fileToPlay == nullptr) {
        throw InvalidAudioFileException();
    }

    RtAudio dac(RtAudio::LINUX_ALSA);
    std::vector<unsigned int> deviceIds = dac.getDeviceIds();

    if ( deviceIds.empty() ) {
        throw NoAudioDevicesAvailableException();
    }

    RtAudio::StreamParameters streamParameters;
    streamParameters.deviceId = dac.getDefaultOutputDevice();
    streamParameters.nChannels = 2;

    RtAudio::StreamOptions options;
    options.flags = RTAUDIO_NONINTERLEAVED;

    dac.openStream(
        &streamParameters,
        NULL,
        RTAUDIO_FLOAT32,
        this->sampleRate,
        &(this->bufferSize),
        &playback,
        fileToPlay->data,
        &options
    );

    dac.startStream();
    std::cin.get();

    dac.closeStream();
}