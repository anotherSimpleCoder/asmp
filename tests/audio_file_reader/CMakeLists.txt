include_directories(
        ${CMAKE_SOURCE_DIR}/include/audio_file
        ${CMAKE_SOURCE_DIR}/include/audio_file_reader
)

add_executable(AudioFileReaderTests AudioFileReaderTests.cpp)
target_link_libraries(AudioFileReaderTests
        GTest::gtest
        GTest::gtest_main
        audio_file
        audio_file_reader
)

add_test(NAME AudioFileReaderTests COMMAND AudioFileReaderTests)