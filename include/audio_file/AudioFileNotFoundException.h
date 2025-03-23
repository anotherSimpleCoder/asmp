//
// Created by amsakan on 23.03.25.
//

#ifndef AUDIOFILENOTFOUNDEXCEPTION_H
#define AUDIOFILENOTFOUNDEXCEPTION_H

#include <exception>
#include <string>

class AudioFileNotFoundException : public std::exception {
      std::string message;

    public:
      explicit AudioFileNotFoundException(std::string path)
        : message("The audio file at the path " + path + " was not found") {}
};

#endif //AUDIOFILENOTFOUNDEXCEPTION_H
