set(EXE_SOURCES
    main.cpp)

add_executable(${MY_EXECUTABLE} ${EXE_SOURCES})
target_link_libraries(
    ${MY_EXECUTABLE}
    PUBLIC
    ${MY_LIBRARY})


target_link_libraries(${MY_EXECUTABLE} PRIVATE sfml-graphics sfml-system sfml-window)