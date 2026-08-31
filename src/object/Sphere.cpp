/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include <cmath>

namespace RayTracer {

    Sphere::Sphere(const Math::Vector3D &center, double radius)
        : m_center(center), m_radius(radius) {}

    Math::Vector3D Sphere::center() const
    {
        return m_center;
    }

    double Sphere::radius() const
    {
        return m_radius;
    }

    double Sphere::calculateDiscriminant(const Ray& ray, double& a, double& b) const
    {
        Math::Vector3D oc = ray.original_pos - m_center;
        a = ray.new_direction.dot(ray.new_direction);
        b = 2.0 * oc.dot(ray.new_direction);
        double c = oc.dot(oc) - m_radius * m_radius;
        return b * b - 4.0 * a * c;
    }

    std::optional<double> Sphere::lightHits(const Ray& ray) const
    {
        double a, b;
        double discriminant = calculateDiscriminant(ray, a, b);
        if (discriminant < 0) {
            return std::nullopt;
        }
        double sqrtDiscriminant = std::sqrt(discriminant);
        double t1 = (-b - sqrtDiscriminant) / (2 * a);
        double t2 = (-b + sqrtDiscriminant) / (2 * a);

        if (t1 > t2)
            std::swap(t1, t2);
        if (t1 < 0)
            t1 = t2;
        if (t1 < 0)
            return std::nullopt;
        return t1;
    }

    Math::Vector3D Sphere::getNormalize(const Math::Vector3D& position) const {
        return (position - m_center).normalize();
    }
}
