#include "KDNode.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"

KDNode::KDNode()
    : left{NULL}, right{NULL}, primitives{std::vector<Geometry*>()} {}

KDNode::KDNode(std::vector<Geometry*> _primitives)
    : primitives{_primitives}, bb{BoundingBox()}
{
  // Compute the overall bounding box
  for (Geometry* p : primitives)
  {
    bb = bb.merge(p->get_bounding_box());
  }
}

KDNode::KDNode(std::vector<Geometry*> _primitives, BoundingBox _bb)
    : primitives{_primitives}, bb{_bb} {}

void KDNode::add_primitive(Geometry* primitive)
{
  add_primitive(primitive, bb.merge(primitive->get_bounding_box()));
}

void KDNode::add_primitive(Geometry* primitive, BoundingBox new_bb)
{
  primitives.push_back(primitive);
  bb = new_bb;
}

void KDNode::build_kd_tree(KDNode* node) {
  // Code inspiration: http://www.flipcode.com/archives/

  BoundingBox currentBB = node->bb;

  // Splits based on the reducing the longest axis by one-half
  int splitaxis = currentBB.max_axis();
  Vector3D lengths = currentBB.most_positive - currentBB.most_negative;

  double axislength;
  if (splitaxis == X_AXIS)
  {
    axislength = lengths.x;
  }
  else if (splitaxis == Y_AXIS)
  {
    axislength = lengths.y;
  }
  else
  {
    axislength = lengths.z;
  }

  // Cease condition
  if (node->primitives.size() < 3 || axislength < 0.01) {
    return;
  }

  // Offset from current_bb.most_negative along splitaxis
  double splitoffset = axislength / 2;

  Point3D midpoint1 = currentBB.most_negative;
  Point3D midpoint2 = currentBB.most_positive;

  if (splitaxis == X_AXIS)
  {
    midpoint1.x += splitoffset;
    midpoint2.x -= splitoffset;
  }
  else if (splitaxis == Y_AXIS)
  {
    midpoint1.y += splitoffset;
    midpoint2.y -= splitoffset;
  }
  else if (splitaxis == Z_AXIS)
  {
    midpoint1.z += splitoffset;
    midpoint2.z -= splitoffset;
  }

  BoundingBox splitboxleft = currentBB;
  splitboxleft.most_positive = midpoint2;

  BoundingBox splitboxright = currentBB;
  splitboxright.most_negative = midpoint1;

  node->left = new KDNode();
  node->right = new KDNode();

  // Put primitives into appropriate bounding box, duplicating if necessary
  for (Geometry* p : node->primitives)
  {
    if (splitboxleft.intersect(p->get_bounding_box()))
    {
      node->left->add_primitive(p, splitboxleft);
    }
    if (splitboxright.intersect(p->get_bounding_box()))
    {
      node->right->add_primitive(p, splitboxright);
    }
  }

  node->primitives.clear();
  node->primitives.shrink_to_fit();

  build_kd_tree(node->left);
  build_kd_tree(node->right);
}

KDNode::~KDNode() {
  if (left != NULL)
  {
    delete left;
  }
  
  if (right != NULL)
  {
    delete right;
  }
}
