cmake_minimum_required(VERSION 3.14)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8 /std:c++latest")
set(ROOT_SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR})


include_directories(Src)
find_package(Qt5 COMPONENTS Gui Core REQUIRED)

# lib
add_library(WinReg STATIC)
target_sources(WinReg PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/WinReg/WinRegUtil.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/WinReg/WinRegUtil.cc)
set_target_properties(WinReg PROPERTIES
    AUTOUIC ON
    AUTOMOC ON
    AUTORCC ON
    #CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    INCLUDE_CURRENT_DIR ON)
target_include_directories(WinReg PUBLIC
    Qt5::Core)
target_link_libraries(WinReg PRIVATE
    Qt5::Core)


add_subdirectory(Test)
