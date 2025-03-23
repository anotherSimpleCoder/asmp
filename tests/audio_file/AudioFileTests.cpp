#include <gtest/gtest.h>
#include "AudioFile.h"
#include "InvalidAudioFileDataException.h"

TEST(AudioFileTests, CreateAudioFile_ShouldNotBeNull) {
    const auto testAudioFile = new AudioFile("testFile.wav", new float[10]);
    EXPECT_NE(testAudioFile, nullptr);
}

TEST(AudioFileTests, CreateAudioFileWithInvalidData_ShouldThrowException) {
    EXPECT_THROW(AudioFile("invalidFile.wav", nullptr), InvalidAudioFileDataException);
}