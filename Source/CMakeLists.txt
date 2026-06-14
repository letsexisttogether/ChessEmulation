add_subdirectory(Application)
add_subdirectory(NewGraphics)
add_subdirectory(NewScene)
add_subdirectory(Math)

add_executable(${PROJECT_NAME} 
    Main.cpp
    ${APPLICATION_SOURCES}
    ${NEW_GRAPHIC_SOURCES}
    ${NEW_SCENE_SOURCES}
    ${MATH_SOURCES}
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ChessEmulation 
    PRIVATE sfml-graphics sfml-window sfml-system)

if(WIN32)
    add_custom_command(TARGET ChessEmulation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-graphics>
            $<TARGET_FILE:sfml-window>
            $<TARGET_FILE:sfml-system>
            $<TARGET_FILE_DIR:ChessEmulation>
    )
else()
    message("Not WIN32")
endif()
