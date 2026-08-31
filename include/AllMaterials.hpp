/*
** EPITECH PROJECT, 2024
** RT
** File description:
** AllMaterials
*/

#ifndef ALLMATERIALS_HPP_
    #define ALLMATERIALS_HPP_

    #include "HandleColor.hpp"

namespace RayTracer {

    class AllMaterials {
    public:
        AllMaterials(const Color& color, double ambient, double diffuse_light, double specular_light, double shiny);

        Color color() const;
        double ambient() const;
        double diffuse_light() const;
        double specular_light() const;
        double shiny() const;
        double ambientLight_;
        double diffuseLight_;
        double specularLight_;
        double shiny_;
        Color color_;

    private:
    };
}

#endif