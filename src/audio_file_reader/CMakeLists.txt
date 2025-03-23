include_directories(
        ${CMAKE_SOURCE_DIR}/include/audio_file
        ${CMAKE_SOURCE_DIR}/include/audio_file_reader
)

find_package(SndFile CONFIG REQUIRED)

add_library(audio_file_reader
        AudioFileReader.cpp
)

target_link_libraries(audio_file_reader
        SndFile::sndfile
)