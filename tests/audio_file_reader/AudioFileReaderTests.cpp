#include <gtest/gtest.h>
#include "AudioFileReader.h"
#include "AudioFileNotFoundException.h"
#include "NoAudioFileException.h"

class AudioFileReaderTests : public ::testing::Test {
    public:
        AudioFileReader* testAudioFileReader{};

    protected:
        void SetUp() override {
            this->testAudioFileReader = new AudioFileReader();
        }
};

TEST_F(AudioFileReaderTests, ReadNonExistentAudioFile_ShouldThrowAudioFileNotFoundException) {
    EXPECT_THROW(testAudioFileReader->read(""), AudioFileNotFoundException);
}

TEST_F(AudioFileReaderTests, ReadNonAudioFile_ShouldThrowNoAudioFileException) {
    EXPECT_THROW(testAudioFileReader->read("./files/invalid_file.bin"), NoAudioFileException);
}

TEST_F(AudioFileReaderTests, ReadAudioFile_ShouldBeOkay) {
    EXPECT_NO_THROW(testAudioFileReader->read("./files/soundfile.mp3"));
}