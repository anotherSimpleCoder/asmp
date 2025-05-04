//
// Created by amsakan on 25.04.25.
//

#ifndef NODEVICESAVAILABLEEXCEPTION_H
#define NODEVICESAVAILABLEEXCEPTION_H

#include <string>
#include "ASMPException.h"

class NoAudioDevicesAvailableException : public ASMPException {
public:
    explicit NoAudioDevicesAvailableException()
      : ASMPException("No Audio Devices are available!") {}
};


#endif //NODEVICESAVAILABLEEXCEPTION_H
