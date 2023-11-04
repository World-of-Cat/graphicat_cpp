cmake_minimum_required(VERSION 3.26)
project(graphicat_sample)

add_executable(graphicat_sample src/main.cpp)
target_include_directories(graphicat_sample PRIVATE src)
target_link_libraries(graphicat_sample graphicat::graphicat)