/*
** EPITECH PROJECT, 2024
** RT
** File description:
** PLight
*/

#include "PLight.hpp"
#include <cmath>

namespace RayTracer {

    PLight::PLight(const Math::Vector3D& position, const Color& color)
        : position_(position), color_(color) {}

    Color PLight::getAColor(const RayTracer::AllMaterials& material) const
    {
        return Color(0, 0, 0);
    }

    Color PLight::getDColor(const Math::Vector3D& point, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const
    {
        auto new_direction = getDirec(point);
        double intensity = calculateIntensity(new_direction, normal, material.diffuseLight_);
        return color_ * intensity;
    }

    Math::Vector3D PLight::getDirec(const Math::Vector3D& point) const
    {
        return (position_ - point).normalize();
    }

    double PLight::getDist(const Math::Vector3D& point) const
    {
        return (position_ - point).length();
    }

    Color PLight::getSColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const
    {
        auto lightDirection = getDirec(point);
        auto reflectDirection = Math::reflect(lightDirection, normal);
        double intensity = std::pow(std::max(reflectDirection.dot(viewDirection), 0.0), material.shiny_) * material.specularLight_;
        return color_ * intensity;
    }

    double PLight::calculateIntensity(const Math::Vector3D& lightVec, const Math::Vector3D& normal, double scale) const
    {
        double dotProduct = lightVec.dot(normal);
        return std::max(dotProduct, 0.0) * scale;
    }
}

