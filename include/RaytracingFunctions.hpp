/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tristan.darodes-de-tailly
** File description:
** RaytracingFunctions
*/

#ifndef RAYTRACINGFUNCTIONS_HPP_
#define RAYTRACINGFUNCTIONS_HPP_

#include <vector>
#include <memory>
#include <optional>
#include <limits>
#include <filesystem>
#include <compare>
#include "IPrimitives.hpp"
#include "IAllTypeLights.hpp"
#include "AllMaterials.hpp"
#include "Ray.hpp"
#include "HandleColor.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
    void error_handling(int ac, char **av)
    {
        if (ac != 2) {
            std::cerr << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration" << std::endl;
            exit(84);
        }
        std::string arg = av[1];
        if (arg == "--help") {
            std::cout << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration" << std::endl;
            exit(0);
        }
        if (!std::filesystem::exists(arg)) {
            std::cerr << "Invalid scene file" << std::endl;
            exit(84);
        }
    }

    Color GetTotalAmbientLight(const std::vector<std::shared_ptr<IAllTypeLights>>& lights, const AllMaterials& material)
    {
        Color totalAmbientColor = Color();
        for (const auto& light : lights) {
            totalAmbientColor += light->getAColor(material);
        }
        return totalAmbientColor;
    }
    
    Color GetTotalDiffuseColor(const AllMaterials& material, const Math::Vector3D& normal, const Math::Vector3D& position, const std::vector<std::shared_ptr<IAllTypeLights>>& lights)
    {
        Color totalDiffuseColor;
        for (const auto& light : lights) {
            Color diffuseColor = light->getDColor(position, normal, material);
            double dotProduct = normal.dot(light->getDirec(position));
            if (dotProduct > 0) {
                totalDiffuseColor += material.color_ * diffuseColor * dotProduct;
            }
        }
        return totalDiffuseColor;
    }

    Color GetTotalSpecularColor(const AllMaterials& material, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const Math::Vector3D& position, const std::vector<std::shared_ptr<IAllTypeLights>>& lights)
    {
        Color totalSpecularColor;
    
        for (const auto& light : lights) {
            Color specularColor = light->getSColor(position, viewDirection, normal, material);
            double dotProduct = normal.dot(light->getDirec(position));
            if (dotProduct > 0) {
                Math::Vector3D reflectionDirection = (2 * dotProduct * normal - light->getDirec(position)).normalize();
                double specularIntensity = std::pow(std::max(0.0, reflectionDirection.dot(-viewDirection)), material.specularLight_);
                totalSpecularColor += material.color_ * specularColor * specularIntensity;
            }
        }
        return totalSpecularColor;
    }

    Color Phong(const AllMaterials& material, const Math::Vector3D& viewDirection, const Math::Vector3D& normal, const Math::Vector3D& position, const std::vector<std::shared_ptr<IAllTypeLights>>& lights)
    {
        return material.color_ * GetTotalAmbientLight(lights, material) +
            GetTotalDiffuseColor(material, normal, position, lights) +
            GetTotalSpecularColor(material, viewDirection, normal, position, lights);
    }

    int distanceObj(const Ray& ray, const std::vector<std::shared_ptr<IPrimitives>>& prim)
    {
        int closestPrimIndex = -42;
        double closestDistance = std::numeric_limits<double>::infinity();

        for (int i = 0; i < prim.size(); i++) {
            std::optional<double> distance = prim[i]->lightHits(ray);
            if (distance && distance.value() >= 0.0 && distance.value() < closestDistance) {
                closestPrimIndex = i;
                closestDistance = distance.value();
                prim[i]->distance = distance.value();
            }
        }
        return closestPrimIndex;
    }
}

#endif /* !RAYTRACINGFUNCTIONS_HPP_ */