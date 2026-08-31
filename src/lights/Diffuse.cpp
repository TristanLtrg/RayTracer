/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Diffuse
*/

#include "Diffuse.hpp"
#include <limits>

namespace RayTracer {

    Diffuse::Diffuse(Color color, Math::Vector3D new_direction, double intensity)
        : color_(std::move(color)), direction_(std::move(new_direction)), intensity_(intensity) {}

    Color Diffuse::getAColor(const RayTracer::AllMaterials& material) const
    {
        return Color(0, 0, 0);
    }

    Color Diffuse::getSColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const
    {
        return Color(0, 0, 0);
    }

    Color Diffuse::getDColor(const Math::Vector3D& point, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const
    {
        return color_ * (intensity_ * std::max(0.0, direction_.dot(-getDirec(point)))) * material.diffuseLight_;
    }

    Math::Vector3D Diffuse::getDirec(const Math::Vector3D& point) const
    {
        return direction_;
    }

    double Diffuse::getDist(const Math::Vector3D& point) const
    {
        return std::numeric_limits<double>::infinity();
    }

}
