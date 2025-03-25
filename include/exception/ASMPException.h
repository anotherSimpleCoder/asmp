//
// Created by amsakan on 25.03.25.
//

#ifndef ASMPEXCEPTION_H
#define ASMPEXCEPTION_H

#include <string>
#include <exception>

class ASMPException : std::exception {
protected:
        std::string message;

public:
    explicit ASMPException(std::string message) {
         this->message = message;
    }

    [[nodiscard]] const char *what() const noexcept override {
        return this->message.c_str();
    }
};
#endif
