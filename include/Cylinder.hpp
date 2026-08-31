/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
    #define CYLINDER_HPP_

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "IPrimitives.hpp"
#include <optional>

namespace RayTracer {
    class Cylinder : public IPrimitives {
    public:
        Math::Vector3D cylinder_pos;
        double radius;
        double height;

        Cylinder(Math::Vector3D cylinder_pos, double radius, double height);
        std::optional<double> lightHits(const Ray& ray) const override;
        Math::Vector3D getNormalize(const Math::Vector3D& point) const override;

    private:
        double computeQuadraticA(const Ray& ray) const;
        double computeQuadraticB(const Ray& ray) const;
        double computeQuadraticC(const Ray& ray) const;
    };
}

#endif