cmake_minimum_required(VERSION 3.18)

find_package(Qt5 COMPONENTS Test REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
enable_testing()

project(tst_WinRegUtil LANGUAGES CXX)
add_executable(tst_WinRegUtil)
target_sources(tst_WinRegUtil PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/tst_WinRegUtil.cc)
set_target_properties(tst_WinRegUtil PROPERTIES
    AUTOUIC ON
    AUTOMOC ON
    AUTORCC ON
    #CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    INCLUDE_CURRENT_DIR ON)
target_include_directories(tst_WinRegUtil PUBLIC
    Qt5::Test WinReg)
target_link_libraries(tst_WinRegUtil PRIVATE
    Qt5::Test WinReg)

add_test(NAME tst_WinRegUtil
    COMMAND tst_WinRegUtil)
