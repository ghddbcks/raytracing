#pragma once
#define real float

class Vector3d {
public:
	real x;
	real y;
	real z;

	Vector3d() : x(0), y(0), z(0) {}
	Vector3d(const real& x, const real& y, const real& z) : x(x), y(y), z(z) {}
	Vector3d(const Vector3d& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}

	const Vector3d operator+(const Vector3d& rhs) const;
	const Vector3d operator-(const Vector3d& rhs)const;
	const Vector3d cross(const Vector3d& rhs)const;
	const real dot(const Vector3d& rhs) const;
	const real norm() const;
	const real sqrnorm() const;
	const Vector3d normalization() const;
	const Vector3d operator*(const real& scaler) const;
	const Vector3d operator/(const real& scaler) const;
};

const Vector3d operator*(const real& scaler, const Vector3d& vector);
const Vector3d operator/(const real& scaler, const Vector3d& vector);