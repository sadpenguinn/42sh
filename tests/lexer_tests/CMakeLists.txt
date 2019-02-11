cmake_minimum_required(VERSION 3.13)
project(tests)

set(SRC lexer_tests.c)
set(LEXER_SRC ../../srcs/lexer/lexer.c ../../srcs/lexer/lexer_tools.c)
set(INC ../../includes)
set(LIBFT_INC ../../srcs/lib/libft/includes)
set(LIBUT_INC ../../srcs/lib/libut/includes)
set(VEC_INC ../../srcs/lib/vector/includes)

include_directories(${INC})
include_directories(${LIBFT_INC})
include_directories(${LIBUT_INC})
include_directories(${VEC_INC})

add_library(libft.a SHARED IMPORTED)
set_target_properties(libft.a PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../../srcs/lib/libft/libft.a)

add_library(libvector.a SHARED IMPORTED)
set_target_properties(libvector.a PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../../srcs/lib/vector/libvector.a)

add_library(libut.a SHARED IMPORTED)
set_target_properties(libut.a PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../../srcs/lib/libut/libut.a)

add_executable(tests ${SRC} ${LEXER_SRC})
target_link_libraries(tests libft.a libvector.a libut.a)