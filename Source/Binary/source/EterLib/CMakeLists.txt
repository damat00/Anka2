cmake_minimum_required(VERSION 3.10)

project(EterLib CXX C)

file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h")

add_library(EterLib STATIC ${SRC_FILES} ${HEADER_FILES})

target_include_directories(EterLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterBase
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterPack
)

target_compile_definitions(EterLib PRIVATE
    WIN32
    _LIB
)