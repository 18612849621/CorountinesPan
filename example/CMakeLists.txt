cmake_minimum_required(VERSION 3.21)

project(libcoroutineExamples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# set compiled bin path
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../bin")

# include
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include/libcoroutine")
# libs
set(libs 
    coroutine)
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/../lib")
# target files
file(GLOB targets "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# add all file compiling
foreach(file ${targets})
    get_filename_component(file_src ${file} NAME)
    get_filename_component(file_target ${file} NAME_WE)
    add_executable(${file_target} ${file_src})
    target_link_libraries(${file_target} PRIVATE ${libs})
    target_compile_features(${file_target} PUBLIC cxx_std_20)
endforeach()

