cmake_minimum_required(VERSION 3.25)

set(SOURCES src/main.c)

project(larithm VERSION 1.0)
add_executable(larithm ${SOURCES})

find_package(OpenGL REQUIRED)

include(external_libs.txt)
target_link_directories(
    larithm PUBLIC
    ${LIB_GLEW_PATH}
)

target_link_libraries(
    larithm PUBLIC
    OpenGL::GL
    glfw3
    glew32
)

# include_directories(src/extern/nuklear)
# add_subdirectory(src)
# #include_directories(src/extern/glew-2.2.0/include)
# find_package(OpenGL REQUIRED)
# target_link_libraries(
#     larithm PUBLIC
#     OpenGL::GL
# )
#
# include_directories(src/extern/nuklear)
# add_subdirectory(src)
# #include_directories(src/extern/glew-2.2.0/include)
