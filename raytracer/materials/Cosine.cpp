#include "Cosine.hpp"
#include "../utilities/ShadeInfo.hpp"

Cosine::Cosine (void)
	:   color(RGBColor(0))
{}

// ---------------------------------------------------------------- constructor

Cosine::Cosine (float c)
	:
		color(RGBColor(c))
{}

Cosine::Cosine (float r, float g, float b)
	:
		color(RGBColor(r,g,b))
{}

Cosine::Cosine (const RGBColor &c)
	:
		color(c)
{}

Cosine* Cosine::clone() const { return new Cosine(*this); }

RGBColor Cosine::shade(const ShadeInfo& sinfo) {
  return color * (sinfo.normal * -sinfo.ray.d);
}
