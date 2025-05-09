#include <AudioFilePlayer.h>
#include <gtest/gtest.h>

#include "InvalidAudioFileException.h"

TEST(AudioFilePlayerTests, Runs) {
    float data[10] = {0};
    auto* testFile = new AudioFile("test.wav", data);
    AudioFilePlayer testPlayer{};

    EXPECT_NO_THROW(testPlayer.play(testFile));
}

TEST(AudioFilePlayerTests, PlayNullFile_ShouldThrowInvalidAudioFileException) {
    AudioFilePlayer testPlayer{};
    EXPECT_THROW(testPlayer.play(nullptr), InvalidAudioFileException);
}