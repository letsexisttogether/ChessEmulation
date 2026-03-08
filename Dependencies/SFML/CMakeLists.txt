include(FetchContent)

set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)

set(SFML_GIT_TAG CACHE STRING "SFML branch, tag, or commit")

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x 
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(SFML)
