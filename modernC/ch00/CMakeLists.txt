cmake_minimum_required(VERSION 3.10)
project(getting-started2 LANGUAGES C)
add_executable(${PROJECT_NAME})
# uncomment the following line to use glob to find source files
# file(GLOB_RECURSE SOURCES src/*.c)
# then change the following line to use glob to find source files
# target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_sources(${PROJECT_NAME} PRIVATE src/getting-started2.c)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_23)
