#include <fstream>
#include <istream>
#include <map>
#include <sstream>
#include "../cameras/Perspective.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../lights/Ambient.hpp"
#include "../lights/Point.hpp"
#include "../materials/Matte.hpp"
#include "../materials/Reflective.hpp"
#include "../samplers/JitterGaussian.hpp"
#include "../utilities/ChessPiece.hpp"
#include "../utilities/Constants.hpp"
#include "../world/World.hpp"

const RGBColor TEAM_COLORS[2] = {RGBColor(0.3, 0.56, 0.64),
                                 RGBColor(1, 0.56, 0.52)};
const Point3D CAMERA_POSITION = Point3D(9, 4, -3.25);
const double KA = 0.2;
const double KD = 3;

void addFile(World* world) {
  Matte* matte = new Matte();
  matte->set_kd(KD);
  matte->set_ka(KA);
  matte->set_cd(TEAM_COLORS[0]);

  double offset = (1.0 - 0.2) / 2.0;
  world->add_ply("models/test.ply", matte,
                 Point3D(20, -20, 20),
                 Point3D(100, 50, 100), true);
}

void World::build(void) {
  bg_color = gray;
  // bg_color = green;
  
  // std::map<char, ChessPiece> dict = initializeDictionary();

  // View plane
  vplane.set_from_camera(CAMERA_POSITION, 20, -30, 60, 0.3);
  // vplane.hres = RESOLUTION;
  // vplane.vres = RESOLUTION;

  vplane.hres = 640;
  vplane.vres = 640;

  // Set max depth higher for more reflections
  vplane.max_depth = 20;

  // Camera, Sampler, and Tracer
  set_camera(new Perspective(CAMERA_POSITION));
  sampler_ptr = new JitterGaussian(camera_ptr, &vplane, 3, 0.25);

  // Lights
  set_ambient_light(new Ambient());
  Point* point = new Point();
  point->set_position(1, 4, 7);
  add_light(point);

  point = new Point(1, 0, 0);
  point->set_position(7, 4, 7);
  add_light(point);

  point = new Point(0, 0, 1);
  point->set_position(1, 4, 1);
  add_light(point);

  point = new Point(0.2);
  point->set_position(9, 4, -1);
  add_light(point);

  // Generate chess board with matte material
  Matte* matte = new Matte();
  matte->set_kd(KD);
  matte->set_ka(KA);

  // Generate chess board with reflective material
  Reflective* reflective = new Reflective();
  reflective->set_cr(1);

  // Emad's custom function
  addFile(this);
}
