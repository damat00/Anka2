cmake_minimum_required(VERSION 3.10)

project(SphereLib CXX C)

file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h")

add_library(SphereLib STATIC ${SRC_FILES} ${HEADER_FILES})

target_include_directories(SphereLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterBase
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterPack
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterLib
)

target_compile_definitions(SphereLib PRIVATE
    WIN32
    _LIB
)