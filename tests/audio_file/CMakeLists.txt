include_directories(
        ${CMAKE_SOURCE_DIR}/include/audio_file
)

add_executable(AudioFileTests AudioFileTests.cpp)
target_link_libraries(AudioFileTests
        GTest::gtest
        GTest::gtest_main
        audio_file
)


add_test(NAME AudioFileTests COMMAND AudioFileTests)