cmake_minimum_required(VERSION 3.10)

project(SimplePatcher VERSION 1.0 DESCRIPTION "A demo for doing (simple) binary patching.")
include_directories("include/")
add_executable(binary binary_generator.cpp)
set_property(TARGET binary PROPERTY CXX_STANDARD 20)