include_directories(
        ${CMAKE_SOURCE_DIR}/include/audio_file
        ${CMAKE_SOURCE_DIR}/include/audio_file_reader
        ${CMAKE_SOURCE_DIR}/include/audio_file_player
        ${CMAKE_SOURCE_DIR}/include/backend
        ${CMAKE_SOURCE_DIR}/include/ui
        ${CMAKE_SOURCE_DIR}/include/cli
)

add_executable(asmp main.cpp)
target_link_libraries(asmp
        audio_file
        audio_file_player
        audio_file_reader
        backend
        cli
        ui
)