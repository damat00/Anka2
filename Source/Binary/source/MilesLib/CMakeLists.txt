cmake_minimum_required(VERSION 3.10)

project(MilesLib CXX C)

file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h")

add_library(MilesLib STATIC ${SRC_FILES} ${HEADER_FILES})

target_include_directories(MilesLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterBase
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterPack
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterLib
)

target_compile_definitions(MilesLib PRIVATE
    WIN32
    _LIB
)