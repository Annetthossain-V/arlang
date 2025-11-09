cmake_minimum_required(VERSION 3.16)
project(Arlang LANGUAGES CXX)

file(GLOB_RECURSE arlangc_src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx")

add_executable(arlangc ${arlangc_src})

target_compile_options(arlangc PRIVATE 
  $<$<CONFIG:Release>: -O3 -march=x86-64-v2 -fno-plt -fstack-protector -Werror -Wall -Wextra -flto>
)

target_link_options(arlangc PRIVATE 
  $<$<CONFIG:Release>: -O2 -lto>
)
