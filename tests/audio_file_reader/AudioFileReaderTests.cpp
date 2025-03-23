#include <gtest/gtest.h>
#include "AudioFileReader.h"
#include "AudioFileNotFoundException.h"

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