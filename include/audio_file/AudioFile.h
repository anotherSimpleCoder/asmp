//
// Created by amsakan on 23.03.25.
//

#ifndef AUDIOFILE_H
#define AUDIOFILE_H

#include <string>
#include <vector>

class AudioFile {
public:
    std::string filename;
    float* data;

    AudioFile(std::string filename, float* data);
};
#endif
