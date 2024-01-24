set(LOGIC_SOURCES 
    ${LOGIC_SOURCES} 
    ${CMAKE_CURRENT_SOURCE_DIR}/DefaultMove/DefaultMove.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/BasicMove.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Transfer/TransferMove.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Knight/KnightMove.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Pawn/Transfer/PawnTransferMove.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Pawn/Attack/PawnAttackMove.cpp
    PARENT_SCOPE
)

