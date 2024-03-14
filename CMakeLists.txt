cmake_minimum_required(VERSION 3.5)

project(libcoroutine)

# only for compile example
add_subdirectory(example)

set(libcoroutine_headers
    include/libcoroutine/libcoroutine.h
    include/libcoroutine/debug.h
    )

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)           #设置库文件的输出目录
# set header path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/libcoroutine)
# get source path
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src libcoroutine_sources)

#Generate the static library from the library sources
add_library(coroutine STATIC ${libcoroutine_sources})
target_compile_features(coroutine PUBLIC cxx_std_20)


