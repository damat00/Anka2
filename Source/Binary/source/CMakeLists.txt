cmake_minimum_required(VERSION 3.10)

project(Metin2Client CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Platform Flags
if(WIN32)
    add_definitions(-DWIN32 -D_WINDOWS -D_CRT_SECURE_NO_WARNINGS)
else()
    # POSIX/Android flags
    add_definitions(-DPOSIX -fpermissive)
endif()

# Global Include Directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Granny-3D-SDK-main/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../extern/include
)

# Bring in Granny 3D static library project
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../Granny-3D-SDK-main/source ${CMAKE_BINARY_DIR}/granny)

# Create a master list of all libraries we need to build
# (We will populate these directories incrementally in future steps)
add_subdirectory(EterBase)
add_subdirectory(EterPack)
add_subdirectory(EterLib)
add_subdirectory(EterGrnLib)
add_subdirectory(MilesLib)
add_subdirectory(GameLib)
add_subdirectory(ScriptLib)
add_subdirectory(EterPythonLib)
add_subdirectory(SpeedTreeLib)
add_subdirectory(PRTerrainLib)
add_subdirectory(SphereLib)
add_subdirectory(EffectLib)
add_subdirectory(UserInterface)
# add_subdirectory(EterGrnLib)
# add_subdirectory(EterPack)
# add_subdirectory(UserInterface)

message(STATUS "Metin2Client CMake Scaffolding Initialized.")
message(STATUS "Granny 3D SDK successfully integrated as a CMake target.")