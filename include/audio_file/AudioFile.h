//
// Created by amsakan on 23.03.25.
//

#ifndef AUDIOFILE_H
#define AUDIOFILE_H
#include <string>

class AudioFile {
        std::string filename;
        float* data;

    public:
        AudioFile(std::string filename, float* data);
};
#endif //AUDIOFILE_H
