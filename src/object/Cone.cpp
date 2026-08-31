/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Cylinder
*/

#include "Cone.hpp"
#include <cmath>

namespace RayTracer {
    Cone::Cone(Math::Vector3D cone_pos, double radius, double height)
        : cone_pos(cone_pos), radius(radius), height(height) {}

    Math::Vector3D Cone::center() const
    {
        return Math::Vector3D(cone_pos.x - radius, cone_pos.y - radius, cone_pos.z);
    }

    double Cone::computeQuadraticA(const Ray& ray) const
    {
        return (ray.new_direction.x * ray.new_direction.x) + (ray.new_direction.y * ray.new_direction.y);
    }

    double Cone::computeQuadraticB(const Ray& ray) const
    {
        Math::Vector3D oc = Math::Vector3D(ray.original_pos.x - cone_pos.x, ray.original_pos.y - cone_pos.y, ray.original_pos.z - cone_pos.z);
        return 2.0 * ((oc.x * ray.new_direction.x) + (oc.y * ray.new_direction.y));
    }

    double Cone::computeQuadraticC(const Ray& ray) const
    {
        Math::Vector3D oc = Math::Vector3D(ray.original_pos.x - cone_pos.x, ray.original_pos.y - cone_pos.y, ray.original_pos.z - cone_pos.z);
        return (oc.x * oc.x) + (oc.z * oc.y) - (radius * radius);
    }



    std::optional<double> Cone::lightHits(const Ray& ray) const
    {
        double a = computeQuadraticA(ray);
        double b = computeQuadraticB(ray);
        double c = computeQuadraticC(ray);
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            return std::nullopt;
        }
        double sqrtDiscriminant = sqrt(discriminant);
        double t1 = (-b - sqrtDiscriminant) / (2 * a);
        double t2 = (-b + sqrtDiscriminant) / (2 * a);

        if (t1 < 0 && t2 < 0) {
            return std::nullopt;
        }
        double t = (t1 < t2 && t1 >= 0) ? t1 : t2;
        double z = ray.original_pos.z + t * ray.new_direction.z;
        if (z < cone_pos.z - height / 2 || z > cone_pos.z + height / 2) {
            return std::nullopt;
        }
        return t;
    }

    Math::Vector3D Cone::getNormalize(const Math::Vector3D& point) const
    {
        return Math::Vector3D(point.x - cone_pos.x, point.y - cone_pos.y, point.z - cone_pos.z).normalize();
    }

}

