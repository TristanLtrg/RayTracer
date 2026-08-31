/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tristan.darodes-de-tailly
** File description:
** Plan
*/

#include "Plane.hpp"
#include <cmath>

namespace RayTracer {
    Plane::Plane(const Math::Vector3D& norm, const Math::Vector3D& pos)
    : normal(norm), position(pos) {}

    std::optional<double> Plane::lightHits(const Ray& ray) const {
        const double epsilon = 1e-6;
        double denom = normal.dot(ray.new_direction);
        
        if (std::abs(denom) > epsilon) {
            Math::Vector3D v = position - ray.original_pos;
            double t = v.dot(normal) / denom;
            
            if (t >= 0) return t;
        }
        
        return std::nullopt;
    }

    Math::Vector3D Plane::getNormalize(const Math::Vector3D& hit_point) const {
        return normal;
    }
}
