add_subdirectory(Application)
add_subdirectory(Spawn)
add_subdirectory(UI)
add_subdirectory(Graphic)
add_subdirectory(Control)

message("Application: ${APPLICATION_SOURCES}")
message("Spawn: ${SPAWN_SOURCES}")
message("UI: ${UI_SOURCES}")
message("Graphic: ${GRAPHIC_SOURCES}")
message("Control: ${CONTROL_SOURCES}")

add_executable(${PROJECT_NAME} 
    Main.cpp
    ${APPLICATION_SOURCES}
    # ${SPAWN_SOURCES}
    # ${UI_SOURCES}
    ${GRAPHIC_SOURCES}
    ${CONTROL_SOURCES}
)

target_include_directories (${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})