cmake_minimum_required(VERSION 3.0.0)
project(pcl-tutorials VERSION 0.1.0)

add_subdirectory(3rd-party/fmtlib/fmt)

link_libraries(fmt)

add_subdirectory(filtering)
