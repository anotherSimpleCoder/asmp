//
// Created by amsakan on 24.03.25.
//

#ifndef NOAUDIOFILEEXCEPTION_H
#define NOAUDIOFILEEXCEPTION_H

#include <exception>
#include <string>

class NoAudioFileException : public std::exception {
    std::string message;

    public:
         explicit NoAudioFileException(std::string filename)
             : message("The " + filename + " is not an audio file!") {}
};
#endif //NOAUDIOFILEEXCEPTION_H
