#include "pcl-tutorials-utils/utils.h"

#include <random>

#include <fmt/core.h>

namespace tutorials {
void random_init_cloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud,
                       decltype(cloud->width) width,
                       decltype(cloud->height) height) {
  cloud->width = width;
  cloud->height = height;
  cloud->resize(cloud->width * cloud->height);

  std::random_device rd;
  std::uniform_real_distribution<float> dist(-1.0F, 1.0F);
  for (auto &point : *cloud) {
    point.x = dist(rd);
    point.y = dist(rd);
    point.z = dist(rd);
  }
}

void print_cloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud) {
  for (const auto &point : *cloud) {
    fmt::print("  ({}, {}, {})\n", point.x, point.y, point.z);
  }
}
} // namespace tutorials