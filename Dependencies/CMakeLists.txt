# SFML

target_compile_definitions(${PROJECT_NAME} PRIVATE SFML_STATIC)

set (SFML_PATH ${CMAKE_CURRENT_SOURCE_DIR}/SFML)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(SFML_LIBS sfml-graphics-s-d sfml-window-s-d sfml-system-s-d)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")  
    set(SFML_LIBS sfml-graphics-s sfml-window-s sfml-system-s)
else()
    message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}. Must be either Debug or Release.")
endif()
set(SFML_EXTRA_LIBS opengl32 freetype.lib winmm.lib gdi32.lib)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_PATH}/include)

target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_PATH}/lib) 
target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIBS} ${SFML_EXTRA_LIBS})