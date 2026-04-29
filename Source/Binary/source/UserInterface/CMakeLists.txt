cmake_minimum_required(VERSION 3.10)

project(UserInterface CXX C)

file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h")

# The Client Executable
add_executable(UserInterface WIN32 ${SRC_FILES} ${HEADER_FILES})

# Ignore legacy Resource.rc or other problematic files initially if needed,
# but we will just add them as is.

target_include_directories(UserInterface PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterBase
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterPack
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterGrnLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../MilesLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../GameLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../ScriptLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterPythonLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../SpeedTreeLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../PRTerrainLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../SphereLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../EffectLib
)

target_compile_definitions(UserInterface PRIVATE
    WIN32
    _WINDOWS
)

target_link_libraries(UserInterface PRIVATE
    GameLib
    EterPythonLib
    EffectLib
    ScriptLib
    SpeedTreeLib
    PRTerrainLib
    SphereLib
    EterGrnLib
    EterLib
    MilesLib
    EterPack
    EterBase
    granny2_static
    # We will also need system libs like d3d8, dinput8, msimg32, etc.
    d3d8
    d3dx8
    dinput8
    dxguid
    winmm
    ws2_32
    imm32
    imagehlp
    version
    # Extern precompiled libraries for Windows (boost, devil, python)
    ${CMAKE_CURRENT_SOURCE_DIR}/../../extern/library/cryptopp.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../extern/library/DevIL.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../extern/library/ILU.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../extern/library/ILUT.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../extern/library/libjpeg-6b.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../extern/library/python27.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../extern/library/lz4.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../extern/library/mss32.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../extern/library/SpeedTreeRT.lib
)