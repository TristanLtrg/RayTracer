/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Cylinder
*/

#include "Hourglass.hpp"
#include <cmath>

namespace RayTracer {
    Hourglass::Hourglass(Math::Vector3D hourglass_pos, double radius, double height)
        : hourglass_pos(hourglass_pos), radius(radius), height(height) {}

    Math::Vector3D Hourglass::center() const
    {
        return Math::Vector3D(hourglass_pos.x - radius, hourglass_pos.y - radius, hourglass_pos.z);
    }

    double Hourglass::computeQuadraticA(const Ray& ray) const {
        double r2 = radius * radius;
        double h2 = height * height;
        return ray.new_direction.x * ray.new_direction.x + ray.new_direction.y * ray.new_direction.y - 
            (ray.new_direction.z * ray.new_direction.z * (r2 / h2));
    }

    double Hourglass::computeQuadraticB(const Ray& ray) const {
        Math::Vector3D oc = ray.original_pos - hourglass_pos;
        double r2 = radius * radius;
        double h2 = height * height;
        return 2 * (ray.new_direction.x * oc.x + ray.new_direction.y * oc.y - 
            (ray.new_direction.z * oc.z * (r2 / h2)));
    }

    double Hourglass::computeQuadraticC(const Ray& ray) const {
        Math::Vector3D oc = ray.original_pos - hourglass_pos;
        double r2 = radius * radius;
        double h2 = height * height;
        return oc.x * oc.x + oc.y * oc.y - (oc.z * oc.z * (r2 / h2));
    }



    std::optional<double> Hourglass::lightHits(const Ray& ray) const
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
        if (z < hourglass_pos.z - height / 2 || z > hourglass_pos.z + height / 2) {
            return std::nullopt;
        }
        return t;
    }

    Math::Vector3D Hourglass::getNormalize(const Math::Vector3D& point) const
    {
        return Math::Vector3D(point.x - hourglass_pos.x, 0, point.z - hourglass_pos.z).normalize();
    }

}

