/*
** EPITECH PROJECT, 2024
** RT
** File description:
** PLight
*/

#ifndef PLIGHT_HPP_
    #define PLIGHT_HPP_

#include "IAllTypeLights.hpp"
#include "Vector3D.hpp"
#include "HandleColor.hpp"
#include "AllMaterials.hpp"

namespace RayTracer {

    class PLight : public IAllTypeLights {
    public:
        PLight(const Math::Vector3D& position, const Color& color);
        
        Color getAColor(const RayTracer::AllMaterials& material) const override;
        Color getDColor(const Math::Vector3D& point, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const override;
        Math::Vector3D getDirec(const Math::Vector3D& point) const override;
        double getDist(const Math::Vector3D& point) const override;
        Color getSColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const override;

    private:
        Math::Vector3D position_;
        Color color_;
        double calculateIntensity(const Math::Vector3D& lightVec, const Math::Vector3D& normal, double scale) const;
    };
}

#endif