cmake_minimum_required(VERSION 3.15)

if(NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

project(
  C++_CookBook
  VERSION 0.0.0
  DESCRIPTION "Raka's C++ Cookbook"
  LANGUAGES CXX C)

# https://clang.llvm.org/docs/JSONCompilationDatabase.html
# This creates a "Compilation Database" under the build/ directory
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include(Dependencies.cmake)
setup_dependencies()

add_subdirectory(src)
