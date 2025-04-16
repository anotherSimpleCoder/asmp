FROM ubuntu:latest
USER root

RUN apt update -y && apt upgrade -y
RUN apt install wget -y
RUN wget https://cmake.org/files/v3.30/cmake-3.30.0-linux-x86_64.tar.gz
RUN tar zxvf cmake-3.30.0-linux-x86_64.tar.gz
RUN mv cmake-3.30.0-linux-x86_64 /opt/cmake-3.30.0
RUN ln -sf  /opt/cmake-3.30.0/bin/*    /usr/bin/
RUN cmake --version

RUN apt install clang build-essential git curl pkg-config -y
RUN git clone https://github.com/microsoft/vcpkg.git
RUN ./vcpkg/bootstrap-vcpkg.sh