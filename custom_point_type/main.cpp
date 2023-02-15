#include <fmt/core.h>

// Starting with PCL-1.7 you need to define PCL_NO_PRECOMPILE
// before you include any PCL headers to include the templated
// algorithms as well.
#define PCL_NO_PRECOMPILE
#include <pcl/io/pcd_io.h>
#include <pcl/pcl_macros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "pcl_tutorials_utils/utils.h"

struct EIGEN_ALIGN16 PointType {
  PCL_ADD_POINT4D; // preferred way of adding a XYZ+padding
  float test;
  // PCL_MAKE_ALIGNED_OPERATOR_NEW // make sure our new allocators are aligned
};

// The invocation of POINT_CLOUD_REGISTER_POINT_STRUCT
// must be in the global namespace and the name of the
// new point type must be fully qualified.

// here we assume a XYZ + "test" (as fields)
POINT_CLOUD_REGISTER_POINT_STRUCT(
    PointType, (float, x, x)(float, y, y)(float, z, z)(float, test, test))
#include <fstream>
int main() {
  pcl::PointCloud<PointType> cloud;
  cloud.width = 2;
  cloud.height = 1;
  cloud.resize(cloud.width * cloud.height);

  cloud[0].x = 1;
  cloud[0].y = 2;
  cloud[0].z = 3;
  cloud[0].test = 4;

  cloud[1].x = 5;
  cloud[1].y = 6;
  cloud[1].z = 7;
  cloud[1].test = 8;

  constexpr auto pcd = "custom_point_type.pcd";
  fmt::println("save to: {}", pcd);

  pcl::io::savePCDFile(pcd, cloud);

  std::ifstream fin(pcd);
  fmt::println("{}", tutorials::readfile(fin));

  return 0;
}