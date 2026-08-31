/*
** EPITECH PROJECT, 2024
** RT
** File description:
** ParseMaterials.cpp
*/

#include "ParseConfig.hpp"
#include "Diffuse.hpp"
#include "PLight.hpp"
#include "Ambient.hpp"
#include "DirecLight.hpp"
#include <ostream>
#include <iostream>

namespace RayTracer {
    void Config::getMaterials(const std::string& file)
    {
        libconfig::Config cfg;

        cfg.readFile(file.c_str());
        const libconfig::Setting& materials1 = cfg.lookup("materials");

        try {
            const libconfig::Setting& objectsSetting = materials1.lookup("objects");

            for (int i = 0; i < objectsSetting.getLength(); i++) {
                const libconfig::Setting& objectSetting = objectsSetting[i];
                Material_t newMaterial;
                newMaterial.ambient_ = objectSetting.lookup("ambient");
                newMaterial.diffuse_ = objectSetting.lookup("diffuse_light");
                newMaterial.specular_ = objectSetting.lookup("specular_light");
                newMaterial.shininess_ = objectSetting.lookup("shiny");
                double r = objectSetting.lookup("color.r");
                double g = objectSetting.lookup("color.g");
                double b = objectSetting.lookup("color.b");
                newMaterial.color_ = Color(r, g, b);
                newMaterial.color_.clamp();
                materials.push_back(newMaterial);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }

    void Config::setMaterials()
    {
        for (const auto& material1 : materials) {
            auto m = std::make_shared<AllMaterials>(material1.color_, material1.ambient_, material1.diffuse_, material1.specular_, material1.shininess_);
            material.push_back(m);
        }
    }
}