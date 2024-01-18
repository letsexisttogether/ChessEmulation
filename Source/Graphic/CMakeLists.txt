list(APPEND GRAPHIC_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Drawable/Drawable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Placable/Placable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Intersectable/Intersectable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sprite/Sprite.cpp
)

set(GRAPHIC_SOURCES ${GRAPHIC_SOURCES} PARENT_SCOPE)
