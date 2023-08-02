add_subdirectory(client_nuklear)
add_subdirectory(client_cmd)


target_include_directories(
    laclient PUBLIC
    "${CMAKE_SOURCE_DIR}/src/common/"
    "${CMAKE_SOURCE_DIR}/src/common/objects"
    # "${CMAKE_SOURCE_DIR}/src/common/map"
)
# message("${CMAKE_SOURCE_DIR}/src/common/")

target_sources(
    laclient PUBLIC
    client.c
    "state/clnt_game.c"
    "state/clnt_menu.c"
    # interaction.c
    # interaction.h
)

target_link_libraries(
    laclient PUBLIC
    liblarithm
    curl
)
# message("Common sources" "${LA_COMMON_SOURCES}")
