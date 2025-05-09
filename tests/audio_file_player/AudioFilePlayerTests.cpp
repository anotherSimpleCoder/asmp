#include <AudioFilePlayer.h>
#include <gtest/gtest.h>

#include "InvalidAudioFileException.h"


TEST(AudioFilePlayerTests, PlayNullFile_ShouldThrowInvalidAudioFileException) {
    AudioFilePlayer testPlayer{};
    EXPECT_THROW(testPlayer.play(nullptr), InvalidAudioFileException);
}