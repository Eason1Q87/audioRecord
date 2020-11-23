cmake_minimum_required(VERSION 3.5.1)
project(audioRecord)

# Typically you don't care so much for a third party library's tests to be
# run from your own project's code.
#set(JSON_BuildTests OFF CACHE INTERNAL "")

# If you only include this third party in PRIVATE source files, you do not
# need to install it when your main project gets installed.
#set(JSON_Install OFF CACHE INTERNAL "")

# Don't use include(nlohmann_json/CMakeLists.txt) since that carries with it
# unintended consequences that will break the build.  It's generally
# discouraged (although not necessarily well documented as such) to use
# include(...) for pulling in other CMake projects anyways.
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../src/third_party/json json)

#add_library(foo ...)
#target_link_libraries(foo PRIVATE nlohmann_json::nlohmann_json)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-std=c++11  -fno-rtti ${CMAKE_CXX_FLAGS}")

add_definitions(-DWEBRTC_POSIX)
add_definitions(-DWEBRTC_LINUX)
add_definitions(-DWEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE)

#set(ENV{PKG_CONFIG_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../src/third_party/libsourcey/lib/pkgconfig")
find_package(PkgConfig REQUIRED)
#pkg_search_module(PKG_SCY REQUIRED libsourcey)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/third_party/abseil-cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/third_party/restclient-cpp/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/third_party/googletest/src/googlemock/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/third_party/googletest/src/googletest/include/)

include_directories(${PKG_SCY_INCLUDE_DIRS})

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/out/Release/obj)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/out/lib)
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/third_party/restclient-cpp/lib)


add_executable(audioRecord src/main.cpp src/utility.cpp)
target_link_libraries(audioRecord webrtc dl pthread )
