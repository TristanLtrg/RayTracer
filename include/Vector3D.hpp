/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Point3D
*/

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_

#include <cmath>

namespace Math {
    class Vector3D {
    public:
        double x, y, z;

        Vector3D();
        Vector3D(double x, double y, double z);
        Vector3D(const Vector3D& other) = default;
        Vector3D(Vector3D&& other) = default;
        Vector3D& operator=(const Vector3D& other) = default;
        Vector3D& operator=(Vector3D&& other) = default;
        ~Vector3D() = default;

        double length() const;
        bool isZero() const;
        static Vector3D cross(const Vector3D& v1, const Vector3D& v2);
        static bool areCollinear(const Vector3D& v1, const Vector3D& v2);
        double dot(const Vector3D& other) const;
        Vector3D operator+(const Vector3D& other) const;
        Vector3D operator-(const Vector3D& other) const;
        Vector3D operator-() const;
        Vector3D operator*(double scalar) const;
        Vector3D operator/(double scalar) const;
        Vector3D normalize() const;
    };

    inline Vector3D operator*(const double scalar, const Vector3D& vec) 
    {
        return Vector3D(scalar * vec.x, scalar * vec.y, scalar * vec.z);
    }

    inline Vector3D reflect(const Math::Vector3D& incident, const Math::Vector3D& normal)
    {
        return incident - 2 * incident.dot(incident) * normal;
    }
}

#endif