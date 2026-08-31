/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "Vector3D.hpp"
#include "IPrimitives.hpp"
#include "Ray.hpp"
#include <optional>

namespace RayTracer {

    class Triangle : public IPrimitives {
    public:
        Math::Vector3D m_point1;
        Math::Vector3D m_point2;
        Math::Vector3D m_point3;

        Triangle(const Math::Vector3D &point1, const Math::Vector3D &point2, const Math::Vector3D &point3);

        Math::Vector3D point1() const;
        Math::Vector3D point2() const;
        Math::Vector3D point3() const;

        std::optional<double> lightHits(const Ray& ray) const override;
        Math::Vector3D getNormalize(const Math::Vector3D& position) const override;
    };
}

#endif
