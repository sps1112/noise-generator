cmake_minimum_required(VERSION 3.16.3)
project(noise-generator)

set(CMAKE_CXX_STANDARD 11)
if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++11")
endif(MSVC)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(includes)

add_executable(noise-generator 
                src/main.cpp
                src/stb_image_write.cpp)

if(WIN32)
add_custom_command(TARGET noise-generator POST_BUILD   
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/dlls/libstdc++-6.dll"
        $<TARGET_FILE_DIR:noise-generator>)    
endif()