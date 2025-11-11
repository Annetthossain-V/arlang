cmake_minimum_required(VERSION 3.16)
project(arlang LANGUAGES CXX)

set(CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE arlang_src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx")

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "LLVM Include dir: ${LLVM_INCLUDE_DIRS}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(arlang ${arlang_src})

target_compile_options(arlang PRIVATE 
  $<$<CONFIG:Release>: -O3 -march=x86-64-v2 -fno-plt -fstack-protector -Wall -Wextra -flto>
)

target_link_options(arlang PRIVATE 
  $<$<CONFIG:Release>: -O2 -flto>
)

llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(arlang PRIVATE ${llvm_libs})

