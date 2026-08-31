/*
** EPITECH PROJECT, 2024
** RT
** File description:
** DirecLight
*/

#include "DirecLight.hpp"
#include <cmath>
#include <limits>

namespace RayTracer {

    DirecLight::DirecLight(const Math::Vector3D& new_direction, const Color& color, double intensity)
        : direction_(new_direction.normalize()), color_(color), intensity_(intensity) {}

    Color DirecLight::getAColor(const AllMaterials& material) const
    {
        return Color(0, 0, 0);
    }

    Color DirecLight::getDColor(const Math::Vector3D& point, const Math::Vector3D& normal, const AllMaterials& material) const
    {
        double diffuseIntensity = std::max(0.0, normal.dot(-direction_));
        return color_ * (material.diffuseLight_ * diffuseIntensity * intensity_);
    }

    Math::Vector3D DirecLight::getDirec(const Math::Vector3D& point) const
    {
        return -direction_;
    }

    double DirecLight::getDist(const Math::Vector3D& point) const
    {
        return std::numeric_limits<double>::infinity();
    }

    Color DirecLight::getSColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const AllMaterials& material) const
    {
        double diffuseIntensity, specularIntensity;
        computeLighting(normal, diffuseIntensity, specularIntensity, viewDirection, material);
        return color_ * (material.specularLight_ * pow(specularIntensity, material.shiny_) * intensity_);
    }

    void DirecLight::computeLighting(const Math::Vector3D& normal, double& diffuseIntensity, double& specularIntensity, const Math::Vector3D& viewDirection, const AllMaterials& material) const
    {
        diffuseIntensity = std::max(0.0, normal.dot(-direction_));
        Math::Vector3D reflectedDirection = Math::reflect(direction_, normal);
        specularIntensity = std::max(0.0, reflectedDirection.dot(viewDirection));
    }
}

