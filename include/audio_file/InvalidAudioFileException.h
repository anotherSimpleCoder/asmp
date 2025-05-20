//
// Created by amsakan on 23.03.25.
//

#ifndef INVALIDAUDIOFILEDATAEXCEPTION_H
#define INVALIDAUDIOFILEDATAEXCEPTION_H

#include <string>
#include "exception/ASMPException.h"

class InvalidAudioFileException : public ASMPException {
public:
  explicit InvalidAudioFileException()
    : ASMPException("The given AudioFile Data is invalid!") {}
};
#endif
