//
// Created by amsakan on 23.03.25.
//

#ifndef INVALIDAUDIOFILEDATAEXCEPTION_H
#define INVALIDAUDIOFILEDATAEXCEPTION_H

#include <string>
#include <exception>

class InvalidAudioFileException : public std::exception {
    std::string message;

    public:
      explicit InvalidAudioFileException()
        : message("The given AudioFile Data is invalid!") {}
};
#endif //INVALIDAUDIOFILEDATAEXCEPTION_H
