include_directories(
        ${CMAKE_SOURCE_DIR}/include/audio_file
        ${CMAKE_SOURCE_DIR}/include/audio_file_player
)

find_package(RtAudio CONFIG REQUIRED)

add_library(audio_file_player
        AudioFilePlayer.cpp
)

target_link_libraries(audio_file_player
    PRIVATE
    RtAudio::rtaudio
    audio_file
)