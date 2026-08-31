/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"
#include <cmath>

namespace RayTracer {
    Cylinder::Cylinder(Math::Vector3D cylinder_pos, double radius, double height)
        : cylinder_pos(cylinder_pos), radius(radius), height(height) {}

    double Cylinder::computeQuadraticA(const Ray& ray) const {
        return ray.new_direction.x * ray.new_direction.x + ray.new_direction.y * ray.new_direction.y;
    }

    double Cylinder::computeQuadraticB(const Ray& ray) const {
        Math::Vector3D oc = ray.original_pos - cylinder_pos;
        return 2 * (ray.new_direction.x * oc.x + ray.new_direction.y * oc.y);
    }

    double Cylinder::computeQuadraticC(const Ray& ray) const {
        Math::Vector3D oc = ray.original_pos - cylinder_pos;
        return oc.x * oc.x + oc.y * oc.y - radius * radius;
    }

    std::optional<double> Cylinder::lightHits(const Ray& ray) const {
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
        if (z < cylinder_pos.z - height / 2 || z > cylinder_pos.z + height / 2) {
            return std::nullopt;
        }
        return t;
    }

    Math::Vector3D Cylinder::getNormalize(const Math::Vector3D& point) const {
        return Math::Vector3D(point.x - cylinder_pos.x, 0, point.z - cylinder_pos.z).normalize();
    }
}
