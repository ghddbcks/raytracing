#include "vector3d.h"
#include "constants.h"
#include <math.h>

namespace raytracing {
	const Vector3d Vector3d::operator+(const Vector3d& rhs) const
	{
		return Vector3d(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
	}

	const Vector3d Vector3d::operator-(const Vector3d& rhs) const
	{
		return (*this) + -1 * rhs;
	}

	const Vector3d Vector3d::cross(const Vector3d& rhs) const
	{
		return Vector3d(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
	}

	const real Vector3d::dot(const Vector3d& rhs) const
	{
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}

	const real Vector3d::norm() const
	{
		return sqrt(sqrnorm());
	}

	const real Vector3d::sqrnorm() const
	{
		return (*this).dot(*this);
	}

	const Vector3d Vector3d::normalization() const
	{
		return (*this) / this->norm();
	}

	const Vector3d Vector3d::operator*(const real& scaler) const
	{
		return Vector3d(scaler * x, scaler * y, scaler * z);
	}

	const Vector3d Vector3d::operator/(const real& scaler) const
	{
		return 1 / scaler * (*this);
	}

	const Vector3d operator*(const real& scaler, const Vector3d& vector)
	{
		return vector * scaler;
	}

	const Vector3d operator/(const real& scaler, const Vector3d& vector)
	{
		return vector / scaler;
	}
}
