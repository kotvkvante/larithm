set(LA_COMMON_SOURCES
    ${LA_COMMON_SOURCES}
    la_map.c
    la_map.h

    la_sequence.c
    la_sequence.h
    la_types.h
)

target_sources(liblarithm PRIVATE
    ${LA_COMMON_SOURCES}
)
