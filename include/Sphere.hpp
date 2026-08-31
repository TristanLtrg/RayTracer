/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "Vector3D.hpp"
    #include "IPrimitives.hpp" 
    #include "Ray.hpp"
    #include <optional>

namespace RayTracer {

    class Sphere : public IPrimitives {
    public:
        Math::Vector3D m_center;
        double m_radius;

        double calculateDiscriminant(const Ray& ray, double& a, double& b) const;

        Sphere(const Math::Vector3D &center, double radius);

        Math::Vector3D center() const;
        double radius() const;

        std::optional<double> lightHits(const Ray& ray) const override;
        Math::Vector3D getNormalize(const Math::Vector3D& position) const override;
    };
}

#endif