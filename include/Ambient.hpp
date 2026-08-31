/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Ambient
*/

#ifndef AMBIENT_HPP_
    #define AMBIENT_HPP_

#include "IAllTypeLights.hpp"
#include "HandleColor.hpp"
#include "AllMaterials.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
    class Ambient : public IAllTypeLights {
    public:
        explicit Ambient(const Color& color);

        Color getAColor(const RayTracer::AllMaterials& material) const override;
        Color getDColor(const Math::Vector3D& point, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const override;
        Math::Vector3D getDirec(const Math::Vector3D& point) const override;
        double getDist(const Math::Vector3D& point) const override;
        Color getSColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const override;

    private:
        Color color_;
    };
}

#endif