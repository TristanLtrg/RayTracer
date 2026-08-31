/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Ray
*/

#ifndef RAY_HPP_
    #define RAY_HPP_

    #include "Vector3D.hpp"
    #include <cmath>

namespace RayTracer {

    class Ray {
        public:
            Math::Vector3D original_pos;
            Math::Vector3D new_direction;

            Ray(const Math::Vector3D& original_pos, const Math::Vector3D& new_direction) : original_pos(original_pos), new_direction(new_direction) {}
            Math::Vector3D at(double t) const {
                return Math::Vector3D((original_pos + new_direction) * t);
            }
    };
}

#endif