include_directories(
        ${CMAKE_SOURCE_DIR}/include/audio_file
        ${CMAKE_SOURCE_DIR}/include/audio_file_reader
        ${CMAKE_SOURCE_DIR}/include/audio_file_player
        ${CMAKE_SOURCE_DIR}/include/backend
        ${CMAKE_SOURCE_DIR}/include/ui
        ${CMAKE_SOURCE_DIR}/include/cli
)

add_library(cli
        CLI.cpp
)

target_link_libraries(cli
    audio_file
    audio_file_reader
    audio_file_player
    backend
    ui
)