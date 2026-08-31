/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Rectangle3D
*/

#ifndef SCREEN_HPP_
    #define SCREEN_HPP_

    #include "Vector3D.hpp"

namespace RayTracer {
    class Rectangle3D {
    public:
        Rectangle3D();
        Rectangle3D(const Math::Vector3D& original_pos, const Math::Vector3D& bottom_side, const Math::Vector3D& left_side);

        Math::Vector3D pointAt(double u, double v) const;

    private:
        Math::Vector3D original_pos;
        Math::Vector3D bottom_side;
        Math::Vector3D left_side;

        bool isValidRectangle(const Math::Vector3D& v1, const Math::Vector3D& v2) const;
    };
}

#endif