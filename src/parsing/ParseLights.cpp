/*
** EPITECH PROJECT, 2024
** RT
** File description:
** ParseLights.cpp
*/

#include "ParseConfig.hpp"
#include "Diffuse.hpp"
#include "PLight.hpp"
#include "Ambient.hpp"
#include "DirecLight.hpp"
#include <ostream>
#include <iostream>

namespace RayTracer {

    static void parsePointLights(const libconfig::Setting& lights, Config& config) {
        try {
            const libconfig::Setting& PointsSetting = lights.lookup("point_lights");

            for (int i = 0; i < PointsSetting.getLength(); i++) {
                const libconfig::Setting& PointSetting = PointsSetting[i];
                Config::PointLight_t newPointLight;
                newPointLight.position_.x = PointSetting.lookup("position.x");
                newPointLight.position_.y = PointSetting.lookup("position.y");
                newPointLight.position_.z = PointSetting.lookup("position.z");
                double ra = PointSetting.lookup("Color.r");
                double ga = PointSetting.lookup("Color.g");
                double ba = PointSetting.lookup("Color.b");
                newPointLight.color_ = Color(ra, ga, ba);
                newPointLight.color_.clamp();
                config.pointLights.push_back(newPointLight);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }

    static void parseDirectionalLights(const libconfig::Setting& lights, Config& config)
    {
        try {
            const libconfig::Setting& DirectionalsSetting = lights.lookup("directional_lights");

            for (int i = 0; i < DirectionalsSetting.getLength(); i++) {
                const libconfig::Setting& DirectionalSetting = DirectionalsSetting[i];
                Config::DirectionalLight_t newDirectionalLight;
                newDirectionalLight.direction_.x = DirectionalSetting.lookup("new_direction.x");
                newDirectionalLight.direction_.y = DirectionalSetting.lookup("new_direction.y");
                newDirectionalLight.direction_.z = DirectionalSetting.lookup("new_direction.z");
                newDirectionalLight.intensity = DirectionalSetting.lookup("intensity");
                double r = DirectionalSetting.lookup("color.r");
                double g = DirectionalSetting.lookup("color.g");
                double b = DirectionalSetting.lookup("color.b");
                newDirectionalLight.color_ = Color(r, g, b);
                newDirectionalLight.color_.clamp();
                config.directionalLights.push_back(newDirectionalLight);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }

    static void parseAmbientLights(const libconfig::Setting& lights, Config& config)
    {
        try {
            const libconfig::Setting& AmbientsSetting = lights.lookup("ambient_lights");

            for (int i = 0; i < AmbientsSetting.getLength(); i++) {
                const libconfig::Setting& AmbientSetting = AmbientsSetting[i];
                Config::AmbientLight_t newAmbientLight;
                double r = AmbientSetting.lookup("color.r");
                double g = AmbientSetting.lookup("color.g");
                double b = AmbientSetting.lookup("color.b");
                newAmbientLight.color_ = Color(r, g, b);
                newAmbientLight.color_.clamp();
                config.ambientLights.push_back(newAmbientLight);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }

    static void parseDiffuseLights(const libconfig::Setting& lights, Config& config)
    {
        try {
            const libconfig::Setting& DiffusesSetting = lights.lookup("diffuse_lights");

            for (int i = 0; i < DiffusesSetting.getLength(); i++) {
                const libconfig::Setting& DiffuseSetting = DiffusesSetting[i];
                Config::DiffuseLight_t newDiffuseLight;
                double r = DiffuseSetting.lookup("color.r");
                double g = DiffuseSetting.lookup("color.g");
                double b = DiffuseSetting.lookup("color.b");
                newDiffuseLight.color_ = Color(r, g, b);
                newDiffuseLight.color_.clamp();
                newDiffuseLight.direction_.x = DiffuseSetting.lookup("direction.x");
                newDiffuseLight.direction_.y = DiffuseSetting.lookup("direction.y");
                newDiffuseLight.direction_.z = DiffuseSetting.lookup("direction.z");
                newDiffuseLight.intensity_ = DiffuseSetting.lookup("diffuseMult");
                config.diffuseLights.push_back(newDiffuseLight);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }

    void Config::getLights(const std::string& file) {
        libconfig::Config cfg;
        cfg.readFile(file.c_str());
        const libconfig::Setting& lights = cfg.lookup("lights");
        parsePointLights(lights, *this);
        parseDirectionalLights(lights, *this);
        parseAmbientLights(lights, *this);
        parseDiffuseLights(lights, *this);
    }

    void Config::setLights()
    {
        for (const auto& pointLight1 : pointLights) {
            auto p = std::make_shared<PLight>(pointLight1.position_, pointLight1.color_);
            lights.push_back(p);
        }
        for (const auto& directionalLight1 : directionalLights) {
            auto d = std::make_shared<DirecLight>(directionalLight1.direction_, directionalLight1.color_, directionalLight1.intensity);
            lights.push_back(d);
        }
        for (const auto& ambientLight1 : ambientLights) {
            auto a = std::make_shared<Ambient>(ambientLight1.color_);
            lights.push_back(a);
        }
        for (const auto& diffuseLight1 : diffuseLights) {
            auto d = std::make_shared<Diffuse>(diffuseLight1.color_, diffuseLight1.direction_, diffuseLight1.intensity_);
            lights.push_back(d);
        }
    }
}
