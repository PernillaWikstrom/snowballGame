set(SOURCES
    background.cpp
    entity.cpp
    snowball.cpp
    snowboard.cpp
    brick.cpp
    interactions.cpp
    entityManager.cpp)

set(INCLUDES
"../includes/"
"${CMAKE_BINARY_DIR}/configured_files/include")

add_library(
    ${MY_LIBRARY}
    STATIC
    ${SOURCES}
    "../includes/")

target_include_directories(
    ${MY_LIBRARY}
    PUBLIC
    ${INCLUDES})

target_link_libraries(${MY_LIBRARY} PRIVATE sfml-graphics sfml-system sfml-window)