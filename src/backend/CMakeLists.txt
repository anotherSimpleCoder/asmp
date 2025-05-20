include_directories(
        ${CMAKE_SOURCE_DIR}/include/backend
        ${CMAKE_SOURCE_DIR}/include/audio_file
        ${CMAKE_SOURCE_DIR}/include/audio_file_reader
        ${CMAKE_SOURCE_DIR}/include/audio_file_player
)

add_library(backend
    Backend.cpp
)

target_link_libraries(backend
        audio_file
        audio_file_reader
        audio_file_player
)