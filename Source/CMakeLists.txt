add_subdirectory(Application)
add_subdirectory(Spawn)
add_subdirectory(UI)
add_subdirectory(Graphic)
add_subdirectory(Control)
add_subdirectory(Logic)

message("Application: ${APPLICATION_SOURCES}")
message("Spawn: ${SPAWN_SOURCES}")
message("UI: ${UI_SOURCES}")
message("Graphic: ${GRAPHIC_SOURCES}")
message("Control: ${CONTROL_SOURCES}")
message("Logic: ${LOGIC_SOURCES}")

add_executable(${PROJECT_NAME} 
    Main.cpp
    ${APPLICATION_SOURCES}
    ${SPAWN_SOURCES}
    ${UI_SOURCES}
    ${GRAPHIC_SOURCES}
    ${CONTROL_SOURCES}
    ${LOGIC_SOURCES}
)

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

target_include_directories(${PROJECT_NAME} 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
