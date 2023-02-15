cmake_minimum_required(VERSION 3.1.0)
project(pcl_tutorials_utils VERSION 0.1.0)

add_library(pcl_tutorials_utils utils.cpp)
target_compile_features(pcl_tutorials_utils PRIVATE cxx_std_11)
