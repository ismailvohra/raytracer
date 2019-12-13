#include "Light.hpp"

Light::Light() : color{RGBColor(1, 1, 1)}, ls{1.0} {}

Light::Light(float c) : color{RGBColor(c, c, c)}, ls{1.0} {}

Light::Light(float r, float g, float b) : color{RGBColor(r, g, b)}, ls{1.0} {}

Light::Light(const RGBColor& _color) : color{_color}, ls{1.0} {}

void Light::set_color(float c) { color = RGBColor(c, c, c); }

void Light::set_color(float r, float g, float b) { color = RGBColor(r, g, b); }

void Light::set_color(const RGBColor& pt) { color = pt; }