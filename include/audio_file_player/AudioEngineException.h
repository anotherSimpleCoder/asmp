//
// Created by amsakan on 10.05.25.
//

#ifndef AUDIOENGINEEXCEPTION_H
#define AUDIOENGINEEXCEPTION_H

#include <string>
#include "exception/ASMPException.h"

class AudioEngineException : public ASMPException {
    public:
      explicit AudioEngineException(const std::string& errorMessage)
          : ASMPException("Audio engine exception: " + errorMessage) {}
};

#endif //AUDIOENGINEEXCEPTION_H
