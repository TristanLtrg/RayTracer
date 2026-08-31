/*
** EPITECH PROJECT, 2024
** RT
** File description:
** AllMaterials
*/

#include "AllMaterials.hpp"

namespace RayTracer {

    AllMaterials::AllMaterials(const Color& color, double ambient, double diffuse_light, double specular_light, double shiny)
        : color_(color), ambientLight_(ambient), diffuseLight_(diffuse_light), specularLight_(specular_light), shiny_(shiny) {}

    Color AllMaterials::color() const
    {
        return color_;
    }

    double AllMaterials::ambient() const
    {
        return ambientLight_;
    }

    double AllMaterials::diffuse_light() const
    {
        return diffuseLight_;
    }

    double AllMaterials::specular_light() const
    {
        return specularLight_;
    }

    double AllMaterials::shiny() const
    {
        return shiny_;
    }
}
