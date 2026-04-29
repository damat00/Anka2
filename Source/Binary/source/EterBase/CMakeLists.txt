cmake_minimum_required(VERSION 3.10)

project(EterBase CXX C)

file(GLOB_RECURSE SRC_FILES "*.cpp" "Poly/*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h" "Poly/*.h")

add_library(EterBase STATIC ${SRC_FILES} ${HEADER_FILES})

# Include directories needed by EterBase
target_include_directories(EterBase PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Poly
)

# It uses LZO, we will need to link or include lzo headers eventually, but for now we just compile
target_compile_definitions(EterBase PRIVATE
    WIN32
    _LIB
)