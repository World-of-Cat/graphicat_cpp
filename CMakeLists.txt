cmake_minimum_required(VERSION 3.26)
project(graphicat_cpp)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_library(graphicat
        src/graphicat/graphicat.cpp
        src/graphicat/graphicat.hpp
        src/graphicat/os/window.cpp
        src/graphicat/os/window.hpp)
target_link_libraries(graphicat PUBLIC Vulkan::Vulkan glm::glm spdlog::spdlog glfw)
target_include_directories(graphicat PUBLIC src)

add_library(graphicat::graphicat ALIAS graphicat)

target_compile_options(graphicat PRIVATE
        $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Debug>>:/W4>
        $<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<CONFIG:Debug>>:-Wall -Wextra -Wpedantic>
)

add_subdirectory(sample)