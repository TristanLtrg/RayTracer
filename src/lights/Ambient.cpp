/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Ambient
*/

#include "Ambient.hpp"

using namespace RayTracer;

Ambient::Ambient(const Color& color)
    : color_(color) {}

Color Ambient::getAColor(const RayTracer::AllMaterials& material) const
{
    return color_ * material.ambientLight_ * material.color_;
}

Color Ambient::getDColor(const Math::Vector3D& point, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const
{
    return Color(0, 0, 0);
}

Math::Vector3D Ambient::getDirec(const Math::Vector3D& point) const
{
    return Math::Vector3D(0, 0, 0);
}

double Ambient::getDist(const Math::Vector3D& point) const
{
    return 0;
}

Color Ambient::getSColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const
{
    return Color(0, 0, 0);
}
