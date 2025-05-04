#include "AudioFilePlayer.h"
#include "InvalidAudioFileException.h"
#include "NoDevicesAvailableException.h"

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
        NULL,
        NULL,
        &options
    );

    dac.closeStream();
}