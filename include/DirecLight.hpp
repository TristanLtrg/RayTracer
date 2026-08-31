/*
** EPITECH PROJECT, 2024
** RT
** File description:
** DirecLight
*/

#ifndef DIRECLIGHT_HPP_
    #define DIRECLIGHT_HPP_

    #include "IAllTypeLights.hpp"
    #include "HandleColor.hpp"
    #include "Vector3D.hpp"
    #include "AllMaterials.hpp"

namespace RayTracer {
    class DirecLight : public IAllTypeLights {
    public:
        DirecLight(const Math::Vector3D& new_direction, const Color& color, double intensity);

        Color getAColor(const AllMaterials& material) const override;
        Color getDColor(const Math::Vector3D& point, const Math::Vector3D& normal, const AllMaterials& material) const override;
        Math::Vector3D getDirec(const Math::Vector3D& point) const override;
        double getDist(const Math::Vector3D& point) const override;
        Color getSColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const AllMaterials& material) const override;

    private:
        Math::Vector3D direction_;
        Color color_;
        double intensity_;
        void computeLighting(const Math::Vector3D& normal, double& diffuseIntensity, double& specularIntensity, const Math::Vector3D& viewDirection, const AllMaterials& material) const;
    };
}

#endif