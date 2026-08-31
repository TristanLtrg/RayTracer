/*
** EPITECH PROJECT, 2024
** RT
** File description:
** IAllTypeLights
*/

#ifndef IALLTYPELIGHTS_HPP_
    #define IALLTYPELIGHTS_HPP_

    #include "Ray.hpp"
    #include "HandleColor.hpp"
    #include "Vector3D.hpp"
    #include "AllMaterials.hpp"
    #include <iostream>
    #include <string>
    #include <cmath>
    #include <algorithm>

namespace RayTracer {

    class IAllTypeLights {
    public:
        virtual Color getAColor(const RayTracer::AllMaterials& material) const = 0;
        virtual Color getDColor(const Math::Vector3D& point,const Math::Vector3D& normal , const RayTracer::AllMaterials& material) const = 0;
        virtual Color getSColor(const Math::Vector3D& point, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const RayTracer::AllMaterials& material) const = 0;
        virtual Math::Vector3D getDirec(const Math::Vector3D& point) const = 0;
        virtual double getDist(const Math::Vector3D& point) const = 0;
    };

}

#endif