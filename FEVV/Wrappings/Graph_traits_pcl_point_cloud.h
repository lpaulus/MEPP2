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

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>

#include <iterator> // for std::distance
#include<boost/iterator/counting_iterator.hpp>


#include "FEVV/DataStructures/DataStructures_pcl_point_cloud.h"


#if defined(BOOST_MSVC)
#pragma warning(push)
#pragma warning(disable : 4267)
#endif


namespace boost {

template<>
struct vertex_property_type< FEVV::PCLPointCloud >
{
  typedef FEVV::PCLPoint   type;
};


template<>
struct graph_traits< FEVV::PCLPointCloud >
{
private:
  typedef  FEVV::PCLPoint   Point;

public:
  //
  typedef  FEVV::PCLPointCloud::VectorType::size_type        index_type;
    // FEVV::PCLPointCloud::points is a std::vector of FEVV::PCLPoint
    // see https://github.com/PointCloudLibrary/pcl/blob/39732f5a7c8455ed51fd0f6278d8b25322a68dd9/common/include/pcl/point_cloud.h#L426
  typedef  boost::counting_iterator<index_type>              index_iterator;

  // Graph
  typedef  index_type                                        vertex_descriptor;
  typedef  Point                                             vertex_property_type;

  // HalfedgeGraph
  typedef  index_type                                        halfedge_descriptor;
    //TODO-elo-fix  halfedge_descriptor needed by SimpleViewer::draw_or_redraw_mesh()
    //              remove when draw_redraw_mesh() is fixed

   // FaceGraph
  typedef  index_type                                        face_descriptor;
    //TODO-elo-fix  face_decriptor needed par SimpleViewer::internal_createMesh()
    //              remove when internal_createMesh() is fixed
  
  // VertexListGraph
  typedef  index_iterator                                    vertex_iterator;
  typedef  index_type                                        vertices_size_type;

  // nulls
  static vertex_descriptor    null_vertex()   { return -1; }
};

template<>
struct graph_traits< const FEVV::PCLPointCloud >
    : public graph_traits< FEVV::PCLPointCloud >
{ };

} // namespace boost


namespace FEVV {

// Essential free functions specialization for PCLPointCloud.

// See http://www.boost.org/doc/libs/1_61_0/libs/graph/doc/graph_concepts.html
// for BGL concepts description.

// See http://doc.cgal.org/latest/BGL/group__PkgBGLConcepts.html
// for CGAL-BGL concepts description.

// BGL VertexListGraph
//!
//! \brief  Returns the iterator range of the vertices of the mesh.
//!

inline std::pair< typename boost::graph_traits<
                      FEVV::PCLPointCloud >::vertex_iterator,
                  typename boost::graph_traits<
                      FEVV::PCLPointCloud >::vertex_iterator >
vertices(const FEVV::PCLPointCloud &pc)
{
  // returns the index range of vertices
  auto it_beg =
      boost::graph_traits< FEVV::PCLPointCloud >::index_iterator(0);
  auto it_end =
      boost::graph_traits< FEVV::PCLPointCloud >::index_iterator(pc.size());

  return std::pair<
      typename boost::graph_traits< FEVV::PCLPointCloud >::vertex_iterator,
      typename boost::graph_traits< FEVV::PCLPointCloud >::vertex_iterator >(
      it_beg, it_end);
}


// BGL VertexListGraph
//!
//! \brief  Returns an upper bound of the number of vertices of the mesh.
//!
inline
typename boost::graph_traits< FEVV::PCLPointCloud >::vertices_size_type
num_vertices(const FEVV::PCLPointCloud &m)
{
  return static_cast<
      typename boost::graph_traits< FEVV::PCLPointCloud >::vertices_size_type >(
      std::distance(vertices(m).first, vertices(m).second));
}


} // namespace FEVV

