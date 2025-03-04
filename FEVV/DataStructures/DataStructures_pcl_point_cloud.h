// Copyright (c) 2012-2019 University of Lyon and CNRS (France).
// All rights reserved.
//
// This file is part of MEPP2; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 3 of
// the License, or (at your option) any later version.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#pragma once

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>


namespace FEVV {

using PCLPoint = pcl::PointXYZ;
  // or pcl::PointNormal (point + normal)
  // beware 'point' is ambiguous: does it mean pure geometry
  // or datastructure used to store points attributes?

using PCLPointCloud = pcl::PointCloud< PCLPoint >;

} // namespace FEVV

