/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tristan.darodes-de-tailly
** File description:
** Plan
*/

#ifndef PLAN_HPP_
    #define PLAN_HPP_

    #include "Ray.hpp"
    #include "Vector3D.hpp"
    #include "IPrimitives.hpp"
    #include <optional>

namespace RayTracer {
    class Plane : public IPrimitives {
    public:
        Math::Vector3D normal, position;

        Plane(const Math::Vector3D& norm, const Math::Vector3D& pos);

        std::optional<double> lightHits(const Ray& ray) const override;
        Math::Vector3D getNormalize(const Math::Vector3D& hit_point) const override;
    };
}


#endif
