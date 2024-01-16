add_subdirectory(Scenes)

set(APPLICATION_SOURCES
    ${SCENE_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Application.cpp
    PARENT_SCOPE
)
