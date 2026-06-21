add_subdirectory(Application)
add_subdirectory(Logic)

add_executable(${PROJECT_NAME} 
    Main.cpp
    ${APPLICATION_SOURCES}
    ${LOGIC_SOURCES}
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
