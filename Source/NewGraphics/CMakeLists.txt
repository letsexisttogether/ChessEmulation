list(APPEND GRAPHICS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Drawable/Drawable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Interactable/Interactable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Intersectable/Intersectable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Placable/Placable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sprite/Sprite.cpp
)

set(NEW_GRAPHIC_SOURCES ${GRAPHICS_SOURCES} PARENT_SCOPE)
