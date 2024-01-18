list(APPEND GRAPHIC_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Drawable/Drawable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Placable/Placable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Intersectable/Intersectable.cpp
)

set(GRAPHIC_SOURCES ${GRAPHIC_SOURCES} PARENT_SCOPE)
