/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Diffuse
*/


#ifndef DIFFUSE_HPP_
    #define DIFFUSE_HPP_

    #include "IAllTypeLights.hpp"

namespace RayTracer {
    class Diffuse : public IAllTypeLights {
    public:
        Diffuse(Color color, Math::Vector3D new_direction, double intensity);
        Color getAColor(const RayTracer::AllMaterials& material) const override;
        Color getDColor(const Math::Vector3D& point,const Math::Vector3D& normal , const RayTracer::AllMaterials& material) const override;
        Math::Vector3D getDirec(const Math::Vector3D& point) const override;
        double getDist(const Math::Vector3D& point) const override;
        virtual Color getSColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const override;
    private:
        Color color_;
        Math::Vector3D direction_;
        double intensity_;
    };
}

#endif