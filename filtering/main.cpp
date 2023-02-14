#include <fmt/core.h>
#include <pcl/filters/passthrough.h>
#include <pcl/point_types.h>

void random_init_cloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud,
                       decltype(cloud->width) width,
                       decltype(cloud->height) height)
{
  cloud->width = width;
  cloud->height = height;
  cloud->resize(cloud->width * cloud->height);

  for (auto &point : *cloud)
  {
    point.x = 1024 * rand() / (RAND_MAX + 1.0F);
    point.y = 1024 * rand() / (RAND_MAX + 1.0F);
    point.z = 1024 * rand() / (RAND_MAX + 1.0F);
  }
}

void print_cloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
  for (const auto &point : *cloud)
  {
    fmt::print("  ({}, {}, {})\n", point.x, point.y, point.z);
  }
}

int main()
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud(
      new pcl::PointCloud<pcl::PointXYZ>);

  random_init_cloud(cloud, 5, 1);

  fmt::print("Cloud before filtering:\n");
  print_cloud(cloud);

  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setInputCloud(cloud);
  fmt::print("set filter field name: z\n");
  pass.setFilterFieldName("z");
  fmt::print("set filter limits: 0.0 - 1.0\n");
  pass.setFilterLimits(0.0F, 1.0F);
  // fmt::print("set filter inverted: true\n");
  // pass.setNegative(true);
  pass.filter(*filtered_cloud);

  fmt::print("Cloud after filtering:\n");
  print_cloud(filtered_cloud);

  return 0;
}
