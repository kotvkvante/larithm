set(LA_COMMON_SOURCES
    ${LA_COMMON_SOURCES}
    la_actions.c
    la_actions.h
    la_solver.c
    la_solver.h

    la_map.c
    la_map.h

    la_sequence.c
    la_sequence.h
    la_types.h

    la_map_state.c
    la_map_state.h

    objects/wall.c
    objects/wall.h

    objects/base.c
    objects/base.h

    objects/character.c
    objects/character.h
)

# message(">>" ${LA_COMMON_SOURCES})
target_sources(
    liblarithm PRIVATE
    ${LA_COMMON_SOURCES}
)

target_include_directories(
    liblarithm PUBLIC
    "${CMAKE_SOURCE_DIR}/src/common/"
    "${CMAKE_SOURCE_DIR}/src/common/objects"
)
