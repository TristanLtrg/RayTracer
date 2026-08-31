/*
** EPITECH PROJECT, 2024
** RT
** File description:
** CONE
*/

#ifndef HOURGLASS_HPP
    #define HOURGLASS_HPP

#include "Ray.hpp"
#include "Vector3D.hpp"
#include "IPrimitives.hpp"
#include <optional>

namespace RayTracer {
    class Hourglass : public IPrimitives {
    public:
        Math::Vector3D hourglass_pos;
        double radius;
        double height;

        Hourglass(Math::Vector3D cylinder_pos, double radius, double height);
        std::optional<double> lightHits(const Ray& ray) const override;
        Math::Vector3D getNormalize(const Math::Vector3D& point) const override;

    private:
        double computeQuadraticA(const Ray& ray) const;
        double computeQuadraticB(const Ray& ray) const;
        double computeQuadraticC(const Ray& ray) const;
        double calculateDiscriminant(const Ray& ray, double& a, double& b) const;
        Math::Vector3D center() const;
    };
}

#endif