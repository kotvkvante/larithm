cmake_minimum_required(VERSION 3.25)

option(USE_STATIC_LIBS "Staticly linked libs" ON)
option(USE_LIB_FROZEN "Frozen lib for parsing JSON" ON)

# add_compile_options(-Wall -Wextra -pedantic -Werror -Wno-unused-variable)

if(USE_STATIC_LIBS)
    set(GLEW_USE_STATIC_LIBS TRUE)
    set(GLEW_LIB GLEW::glew_s)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
else(USE_STATIC_LIBS)
    set(GLEW_LIB GLEW::glew)
endif(USE_STATIC_LIBS)

set(SOURCES src/main.c)
project(larithm VERSION 1.0)

add_executable(larithm ${SOURCES})
add_executable(laserver)

add_executable(laclient)
# set_target_properties(laclient PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})


add_library(liblarithm STATIC)


find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(
    larithm PUBLIC
    ${GLEW_LIB}
    glfw3
    OpenGL::GL
)

add_subdirectory(src)
