#include <gtest/gtest.h>
#include "AudioFile.h"
#include "InvalidAudioFileException.h"

TEST(AudioFileTests, CreateAudioFile_ShouldNotBeNull) {
    float testAudioData[10] = {0};
    const auto testAudioFile = new AudioFile("testFile.wav", testAudioData);

    EXPECT_NE(testAudioFile, nullptr);
}

TEST(AudioFileTests, CreateAudioFile_ShouldNotBeEqual) {
    float testAudioData[10] = {0};
    const auto testAudioFile = new AudioFile("testFile.wav", testAudioData);

    EXPECT_NE(testAudioFile, nullptr);
    EXPECT_EQ(testAudioFile->filename, "testFile.wav");
    EXPECT_EQ(testAudioFile->data, testAudioData);
}

TEST(AudioFileTests, CreateAudioFileWithNoName_ShouldThrowInvalidAudioFileException) {
    float testAudioData[10] = {0};

    EXPECT_THROW(AudioFile("", testAudioData), InvalidAudioFileException);
}