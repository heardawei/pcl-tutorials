set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake")

cmake_minimum_required(VERSION 3.0.0)
project(pcl-tutorials VERSION 0.1.0)

if(CMAKE_HOST_WIN32)

find_package(fmt CONFIG REQUIRED)
find_package(PCL CONFIG REQUIRED)
link_libraries(fmt::fmt ${PCL_LIBRARIES})

elseif(CMAKE_HOST_UNIX)

add_subdirectory(3rd-party/fmtlib/fmt)
find_package(PCL 1.7 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
add_definitions(${PCL_DEFINITIONS})
link_directories(${PCL_LIBRARY_DIRS})
link_libraries(fmt ${PCL_LIBRARIES})

endif(CMAKE_HOST_WIN32)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(pcl_tutorials_utils)
add_subdirectory(filtering)
add_subdirectory(custom_point_type)