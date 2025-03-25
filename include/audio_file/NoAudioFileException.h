//
// Created by amsakan on 24.03.25.
//

#ifndef NOAUDIOFILEEXCEPTION_H
#define NOAUDIOFILEEXCEPTION_H

#include <exception>
#include <string>

class NoAudioFileException : public ASMPException {
public:
     explicit NoAudioFileException(const std::string& filename)
         : ASMPException("The " + filename + " is not an audio file!") {}
};
#endif
