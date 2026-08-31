/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Rectangle3D
*/

#include "Screen.hpp"
#include <stdexcept>

namespace RayTracer {
    Rectangle3D::Rectangle3D() = default;

    Rectangle3D::Rectangle3D(const Math::Vector3D& original_pos, const Math::Vector3D& bottom_side, const Math::Vector3D& left_side)
        : original_pos(original_pos), bottom_side(bottom_side), left_side(left_side) 
    {
        if (!isValidRectangle(bottom_side, left_side)) {
            throw std::invalid_argument("Not a rectangle sorry");
        }
    }

    Math::Vector3D Rectangle3D::pointAt(double u, double v) const
    {
        return original_pos + bottom_side * u + left_side * v;
    }

    bool Rectangle3D::isValidRectangle(const Math::Vector3D& v1, const Math::Vector3D& v2) const
    {
        return !v1.isZero() && !v2.isZero() && !Math::Vector3D::areCollinear(v1, v2);
    }
}

