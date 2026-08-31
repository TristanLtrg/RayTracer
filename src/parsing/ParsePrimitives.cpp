/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Config.cpp
*/

#include "ParseConfig.hpp"
#include "Diffuse.hpp"
#include "PLight.hpp"
#include "Ambient.hpp"
#include "DirecLight.hpp"
#include <ostream>
#include <iostream>
#include <string>

namespace RayTracer {

    void Config::set(const std::string& file)
    {
        parsespheres(file);
        parsecylindre(file);
        parsecones(file);
        parsehourglass(file);
        parseTriangles(file);
        parsePlan(file);
    }

    void Config::parsespheres(const std::string& file)
    {
        libconfig::Config cfg;
        cfg.readFile(file.c_str());
        const libconfig::Setting& primitives = cfg.lookup("primitives");

        try {
            const libconfig::Setting& spheresSetting = primitives.lookup("spheres");
            for (int i = 0; i < spheresSetting.getLength(); i++) {
                const libconfig::Setting& sphereSetting = spheresSetting[i];
                Sphere_t newSphere;
                newSphere.sphere_pos.x = sphereSetting.lookup("x");
                newSphere.sphere_pos.y = sphereSetting.lookup("y");
                newSphere.sphere_pos.z = sphereSetting.lookup("z");
                newSphere.radius = sphereSetting.lookup("r");
                spheres.push_back(newSphere);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }

    void Config::parsecylindre(const std::string& file)
    {
        libconfig::Config cfg;
        cfg.readFile(file.c_str());
        const libconfig::Setting& primitives = cfg.lookup("primitives");

        try {
            const libconfig::Setting& cylindersSetting = primitives.lookup("cylinders");
            for (int i = 0; i < cylindersSetting.getLength(); i++) {
                const libconfig::Setting& cylinderSetting = cylindersSetting[i];
                Cylinder_t newCylinder;
                newCylinder.cylinder_pos.x = cylinderSetting.lookup("x");
                newCylinder.cylinder_pos.y = cylinderSetting.lookup("y");
                newCylinder.cylinder_pos.z = cylinderSetting.lookup("z");
                newCylinder.radius = cylinderSetting.lookup("r");
                newCylinder.height = cylinderSetting.lookup("h");
                cylinders.push_back(newCylinder);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }

    void Config::parsecones(const std::string& file)
    {
        libconfig::Config cfg;
        cfg.readFile(file.c_str());
        const libconfig::Setting& primitives = cfg.lookup("primitives");

        try {
            const libconfig::Setting& conesSettings = primitives.lookup("cones");
            for (int i = 0; i < conesSettings.getLength(); i++) {
                const libconfig::Setting& coneSettings = conesSettings[i];
                Cone_t newCone;
                newCone.cone_pos.x = coneSettings.lookup("x");
                newCone.cone_pos.y = coneSettings.lookup("y");
                newCone.cone_pos.z = coneSettings.lookup("z");
                newCone.radius = coneSettings.lookup("r");
                newCone.height = coneSettings.lookup("h");
                cones.push_back(newCone);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }
    
    void Config::parsehourglass(const std::string& file)
    {
        libconfig::Config cfg;
        cfg.readFile(file.c_str());
        const libconfig::Setting& primitives = cfg.lookup("primitives");

        try {
            const libconfig::Setting& conesSettings = primitives.lookup("hourglass");
            for (int i = 0; i < conesSettings.getLength(); i++) {
                const libconfig::Setting& coneSettings = conesSettings[i];
                Hourglass_t newHourglass;
                newHourglass.cone_pos.x = coneSettings.lookup("x");
                newHourglass.cone_pos.y = coneSettings.lookup("y");
                newHourglass.cone_pos.z = coneSettings.lookup("z");
                newHourglass.radius = coneSettings.lookup("r");
                newHourglass.height = coneSettings.lookup("h");
                hourglasss.push_back(newHourglass);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }

    void Config::parseTriangles(const std::string& file)
    {
        libconfig::Config cfg;
        cfg.readFile(file.c_str());
        const libconfig::Setting& primitives = cfg.lookup("primitives");

        try {
            const libconfig::Setting& trianglesSetting = primitives.lookup("triangles");
            for (int i = 0; i < trianglesSetting.getLength(); i++) {
                const libconfig::Setting& triangleSetting = trianglesSetting[i];
                Triangle_t newTriangle;
                newTriangle.point1.x = triangleSetting.lookup("p1x");
                newTriangle.point1.y = triangleSetting.lookup("p1y");
                newTriangle.point1.z = triangleSetting.lookup("p1z");
                newTriangle.point2.x = triangleSetting.lookup("p2x");
                newTriangle.point2.y = triangleSetting.lookup("p2y");
                newTriangle.point2.z = triangleSetting.lookup("p2z");
                newTriangle.point3.x = triangleSetting.lookup("p3x");
                newTriangle.point3.y = triangleSetting.lookup("p3y");
                newTriangle.point3.z = triangleSetting.lookup("p3z");
                triangles.push_back(newTriangle);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }

    void Config::parsePlan(const std::string& file) 
    {
        libconfig::Config cfg;
        cfg.readFile(file.c_str());
        const libconfig::Setting& primitives = cfg.lookup("primitives");
        
        try {
            const libconfig::Setting& planesSetting = primitives.lookup("planes");

            for (int i = 0; i < planesSetting.getLength(); i++) {
                const libconfig::Setting& planeSetting = planesSetting[i];
                Plane_t newPlane;
                newPlane.plane_pos = Math::Vector3D();
                newPlane.plane_normal = Math::Vector3D();

                std::string axis = planeSetting.lookup("axis");
                double position = planeSetting.lookup("position");

                if (axis == "X") {
                    newPlane.plane_pos.x = 1;
                    newPlane.plane_normal.x = position;
                } else if (axis == "Y") {
                    newPlane.plane_pos.y = 1;
                    newPlane.plane_normal.y = position;
                } else if (axis == "Z") {
                    newPlane.plane_pos.z = 1;
                    newPlane.plane_normal.z = position;
                }
                planes.push_back(newPlane);
            }
        } catch (const libconfig::SettingNotFoundException&) {
        }
    }


    void Config::setPrimitives()
    {
        for (const auto& sphere : spheres) {
            auto spheres = std::make_shared<Sphere>(sphere.sphere_pos, sphere.radius);
            primitives.push_back(spheres);
        }
        for (const auto& cylinder : cylinders) {
            auto cylinders = std::make_shared<Cylinder>(cylinder.cylinder_pos, cylinder.radius, cylinder.height);
            primitives.push_back(cylinders);
        }
        for (const auto& cone : cones) {
            auto cones = std::make_shared<Cone>(cone.cone_pos, cone.radius, cone.height);
            primitives.push_back(cones);
        }
        for (const auto& hourglass : hourglasss) {
            auto hourglasses = std::make_shared<Hourglass>(hourglass.cone_pos, hourglass.radius, hourglass.height);
            primitives.push_back(hourglasses);
        }
        for (const auto& triangle : triangles) {
            auto triangles = std::make_shared<Triangle>(triangle.point1, triangle.point2, triangle.point3);
            primitives.push_back(triangles);
        }
        for (const auto& plane : planes) {
            auto planes = std::make_shared<Plane>(plane.plane_pos, plane.plane_normal);
            primitives.push_back(planes);
    }
    }
}
