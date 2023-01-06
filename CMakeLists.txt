cmake_minimum_required(VERSION 3.25)

# set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
# set(BUILD_SHARED_LIBS OFF)
# set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SOURCES src/main.c)

project(larithm VERSION 1.0)

add_executable(larithm ${SOURCES})

find_package(OpenGL REQUIRED)

set(GLEW_USE_STATIC_LIBS TRUE)
find_package(GLEW REQUIRED)
# find_library(GLEW_LIB REQUIRED
#     NAMES glew32s
# )

find_library(GLFW_LIB REQUIRED
    NAMES glfw3
)

message("Find: " ${GLEW_LIB})


target_link_libraries(
    larithm PUBLIC
    GLEW::glew_s
    ${GLFW_LIB}
    OpenGL::GL
)
add_subdirectory(src)
