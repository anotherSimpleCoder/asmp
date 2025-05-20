include_directories(
        ${CMAKE_SOURCE_DIR}/include/audio_file_player
        ${CMAKE_SOURCE_DIR}/include/audio_file
)


add_executable(AudioFilePlayerTests AudioFilePlayerTests.cpp)
target_link_libraries(AudioFilePlayerTests
        GTest::gtest
        GTest::gtest_main
        audio_file_player
)

add_test(NAME AudioFilePlayerTests COMMAND AudioFilePlayerTests)