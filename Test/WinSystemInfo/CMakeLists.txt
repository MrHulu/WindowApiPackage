cmake_minimum_required(VERSION 3.18)

find_package(Qt5 COMPONENTS Test REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
enable_testing()

project(tst_WinSystemInfoUtil LANGUAGES CXX)
add_executable(tst_WinSystemInfoUtil)
target_sources(tst_WinSystemInfoUtil PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/tst_WinSystemInfoUtil.cc)
set_target_properties(tst_WinSystemInfoUtil PROPERTIES
    AUTOUIC ON
    AUTOMOC ON
    AUTORCC ON
    #CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    INCLUDE_CURRENT_DIR ON)
target_include_directories(tst_WinSystemInfoUtil PUBLIC
    Qt5::Test WinSystemDisplayInfo)
target_link_libraries(tst_WinSystemInfoUtil PRIVATE
    Qt5::Test WinSystemDisplayInfo)

add_test(NAME tst_WinSystemInfoUtil
    COMMAND tst_WinSystemInfoUtil)
