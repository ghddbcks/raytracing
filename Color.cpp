#include "Color.h"
#include <algorithm>
#include "constants.h"

const Color Color::calculate_reflection(const Color& lightcolor, const Color& objectcolor) const
{
	return Color(std::min(lightcolor.x, objectcolor.y), std::max(lightcolor.y, objectcolor.y), std::max(lightcolor.z, lightcolor.z));
}
