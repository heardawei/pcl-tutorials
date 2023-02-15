#pragma once

#include <fstream>
#include <string>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

namespace tutorials {
void random_init_cloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud,
                       decltype(cloud->width) width,
                       decltype(cloud->height) height);

void print_cloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);
std::string readfile(const std::ifstream &fin);
} // namespace tutorials