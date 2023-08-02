if(USE_LIB_FROZEN)
    add_library(
        frozen STATIC
        "frozen/frozen.c"
        "frozen/frozen.h"
        "frozen_ex.c"
    )
    # target_sources(
    #     ${frozen} PRIVATE
    #     )
    # message("${CMAKE_CURRENT_SOURCE_DIR}/frozen")

    target_include_directories(
        liblarithm PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/frozen"
        "${CMAKE_CURRENT_SOURCE_DIR}"
    )

    target_link_libraries(
        liblarithm PUBLIC
        frozen
    )
endif(USE_LIB_FROZEN)

if(USE_LIB_NUKLEAR)
    message("Failed")

endif(USE_LIB_NUKLEAR)
