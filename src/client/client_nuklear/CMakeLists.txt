target_link_libraries(
    laclient_nuklear PUBLIC
    ${GLEW_LIB}
    glfw3
    OpenGL::GL
)

target_include_directories(
    laclient_nuklear PUBLIC
    "${CMAKE_SOURCE_DIR}/src/extern/nuklear"
    "${CMAKE_SOURCE_DIR}/src/extern/nuklear/demo/glfw_opengl4"
)

target_sources(
    laclient_nuklear PUBLIC
    main.c
    gui.c
)


target_link_libraries(
    laclient_nuklear_test PUBLIC
    ${GLEW_LIB}
    glfw3
    OpenGL::GL
)

target_include_directories(
    laclient_nuklear_test PUBLIC
    "${CMAKE_SOURCE_DIR}/src/extern/nuklear"
    "${CMAKE_SOURCE_DIR}/src/extern/nuklear/demo/glfw_opengl4"
)

target_sources(
    laclient_nuklear_test PUBLIC
    _main.c
)
