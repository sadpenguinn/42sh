cmake_minimum_required(VERSION 3.13)
project(lexer)

set(SRC main.c lexer.c lexer_tools.c)
set(INC ../../includes)
set(LIBFT_INC ../lib/libft/includes)
set(VEC_INC ../lib/vector/includes)

include_directories(${INC})
include_directories(${LIBFT_INC})
include_directories(${VEC_INC})

add_library(libft.a SHARED IMPORTED)
set_target_properties(libft.a PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../lib/libft/libft.a)

add_library(libvector.a SHARED IMPORTED)
set_target_properties(libvector.a PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../lib/vector/libvector.a)

add_executable(lexer ${SRC})
target_link_libraries(lexer libft.a libvector.a)