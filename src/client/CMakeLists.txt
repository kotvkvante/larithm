target_include_directories(
    laclient PUBLIC
    "${CMAKE_SOURCE_DIR}/src/common/"
    "${CMAKE_SOURCE_DIR}/src/common/objects"
)
# message("${CMAKE_SOURCE_DIR}/src/common/")

target_sources(
    laclient PUBLIC
    client.c
    # interaction.c
    # interaction.h
)

target_link_libraries(
    laclient PUBLIC
    liblarithm
    curl
)
# message("Common sources" "${LA_COMMON_SOURCES}")
