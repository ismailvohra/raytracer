#pragma once

#include "../brdfs/PerfectSpecular.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../world/World.hpp"
#include "Phong.hpp"

class Reflective : public Phong {
private:
  PerfectSpecular* reflective_brdf;

 public:
 //Constructor
  Reflective(void);

  // Copy constuctor and assignment operator.

  Reflective(const Reflective& rm);
  Reflective& operator=(const Reflective& rhs);
  
  //Virtual Copy Constructor
  virtual Reflective* clone() const;

//Destructor
  virtual ~Reflective(void);

  void set_kr(const float k);

  void set_cr(const RGBColor& c);

  void set_cr(const float r, const float g, const float b);
  
  void set_cr(const float c);

  virtual RGBColor shade(const ShadeInfo& sinfo);

 
};

