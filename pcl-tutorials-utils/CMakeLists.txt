cmake_minimum_required(VERSION 3.1.0)
project(pcl-tutorials-utils VERSION 0.1.0)

add_library(pcl-tutorials-utils utils.cpp)
target_compile_features(pcl-tutorials-utils PRIVATE cxx_std_11)
