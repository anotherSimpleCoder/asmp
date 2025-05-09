include_directories(
        ${CMAKE_SOURCE_DIR}/include/audio_file
        ${CMAKE_SOURCE_DIR}/include/audio_file_reader
        ${CMAKE_SOURCE_DIR}/include/audio_file_player
        ${CMAKE_SOURCE_DIR}/include/backend
        ${CMAKE_SOURCE_DIR}/include/ui
)

find_package(RtAudio CONFIG REQUIRED)

add_library(ui
        UI.cpp
)

target_link_libraries(ui
        PRIVATE
        RtAudio::rtaudio
        audio_file
        audio_file_reader
        audio_file_player
        backend
)