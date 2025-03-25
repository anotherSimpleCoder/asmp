//
// Created by amsakan on 23.03.25.
//

#ifndef AUDIOFILENOTFOUNDEXCEPTION_H
#define AUDIOFILENOTFOUNDEXCEPTION_H

#include <string>
#include "ASMPException.h"

class AudioFileNotFoundException : public ASMPException {
public:
    explicit AudioFileNotFoundException(const std::string& path)
      : ASMPException("The audio file at the path " + path + " was not found") {}
};

#endif
