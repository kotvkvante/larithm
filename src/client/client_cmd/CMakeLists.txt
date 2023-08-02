target_link_libraries(
    laclient_ncurses PUBLIC
    ncursesw
)

# target_include_directories(
#     laclient_ncurses PUBLIC
#     "${CMAKE_SOURCE_DIR}/src/extern/nuklear"
#     "${CMAKE_SOURCE_DIR}/src/extern/nuklear/demo/glfw_opengl4"
# )

target_sources(
    laclient_ncurses PUBLIC
    main.c
)
