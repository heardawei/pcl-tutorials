cmake_minimum_required(VERSION 3.1.0)
project(filtering VERSION 0.1.0)

add_executable(filtering main.cpp)
target_compile_features(filtering PRIVATE cxx_std_11)
target_link_libraries(filtering PRIVATE pcl_tutorials_utils)
