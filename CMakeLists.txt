cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

file(READ VERSION.txt VERSION_INFORMATION)
string(STRIP ${VERSION_INFORMATION} VERSION_INFORMATION)
project(tree VERSION ${VERSION_INFORMATION} LANGUAGES CXX)

# The following is needed for conan when it is trying to build the
# dependencies.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Install conan and enable this cmake setup to use it.
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from github")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.py
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing
                GENERATORS cmake)

set(CMAKE_CXX_COMPILER /usr/bin/clang++-7)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fno-exceptions -fno-omit-frame-pointer -O3")

add_subdirectory(include)

add_subdirectory(benchmark)
add_subdirectory(doc)

# This enable_testing call should be in the root directory as per
# https://cmake.org/cmake/help/v3.10/command/enable_testing.html
enable_testing()
add_subdirectory(test)
