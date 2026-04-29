cmake_minimum_required(VERSION 3.10)

project(EterPythonLib CXX C)

file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h")

add_library(EterPythonLib STATIC ${SRC_FILES} ${HEADER_FILES})

target_include_directories(EterPythonLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterBase
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterPack
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterLib
    ${CMAKE_CURRENT_SOURCE_DIR}/../ScriptLib
)

target_compile_definitions(EterPythonLib PRIVATE
    WIN32
    _LIB
)