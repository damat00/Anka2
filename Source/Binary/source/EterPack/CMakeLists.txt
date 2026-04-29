cmake_minimum_required(VERSION 3.10)

project(EterPack CXX C)

file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h")

add_library(EterPack STATIC ${SRC_FILES} ${HEADER_FILES})

target_include_directories(EterPack PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../EterBase
)

target_compile_definitions(EterPack PRIVATE
    WIN32
    _LIB
)