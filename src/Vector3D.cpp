/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

using namespace Math;

Vector3D::Vector3D() : x(0), y(0), z(0) {}

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector3D::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

bool Vector3D::isZero() const
{
    return x == 0 && y == 0 && z == 0;
}

Vector3D Vector3D::cross(const Vector3D& v1, const Vector3D& v2)
{
    return Vector3D(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    );
}

bool Vector3D::areCollinear(const Vector3D& v1, const Vector3D& v2)
{
    Vector3D crossProduct = cross(v1, v2);

    return crossProduct.isZero();
}

double Vector3D::dot(const Vector3D& other) const
{
    return x * other.x + y * other.y + z * other.z;
}

Vector3D Vector3D::operator+(const Vector3D& other) const
{
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D& other) const
{
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

Vector3D Vector3D::operator-() const
{
    return Vector3D(-x, -y, -z);
}

Vector3D Vector3D::operator*(double scalar) const
{
    return Vector3D(x * scalar, y * scalar, z * scalar);
}

Vector3D Vector3D::operator/(double scalar) const
{
    return Vector3D(x / scalar, y / scalar, z / scalar);
}

Vector3D Vector3D::normalize() const
{
    double len = length();

    return len != 0 ? *this / len : Vector3D();
}
