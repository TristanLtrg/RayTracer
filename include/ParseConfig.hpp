/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Config
*/

#ifndef PARSECONFIG_HPP_
    #define PARSECONFIG_HPP_

    #include "Sphere.hpp"
    #include "Cylinder.hpp"
    #include "Triangle.hpp"
    #include "Cone.hpp"
    #include "Hourglass.hpp"
    #include "Plane.hpp"
    #include "Vector3D.hpp"
    #include "HandleColor.hpp"
    #include "IPrimitives.hpp"
    #include "IAllTypeLights.hpp"
    #include <libconfig.h++>
    #include <string>
    #include <vector>
    #include <memory>

namespace RayTracer {
    class Config {
        public:
            Config() = default;
            ~Config() = default;

            struct Sphere_t {
                Math::Vector3D sphere_pos;
                double radius;
                int sphere_r, sphere_g, sphere_b;
            };
            std::vector<Sphere_t> spheres;

            struct Cylinder_t {
                Math::Vector3D cylinder_pos;
                double radius;
                double height;
            };
            std::vector<Cylinder_t> cylinders;

            struct Cone_t {
                Math::Vector3D cone_pos;
                double radius;
                double height;
            };
            std::vector<Cone_t> cones;

            struct Hourglass_t {
                Math::Vector3D cone_pos;
                double radius;
                double height;
            };
            std::vector<Hourglass_t> hourglasss;

            struct Triangle_t {
                Math::Vector3D point1;
                Math::Vector3D point2;
                Math::Vector3D point3;
            };
            std::vector<Triangle_t> triangles;

            struct Plane_t {
                Math::Vector3D plane_pos;
                Math::Vector3D plane_normal;
            };
            std::vector<Plane_t> planes;

            struct Material_t {
                Color color_;
                int sphere_int;
                int sphere_g;
                int sphere_b;
                double ambient_;
                double diffuse_;
                double specular_;
                double shininess_;
            };
            std::vector<Material_t> materials;

            struct PointLight_t {
                Math::Vector3D position_;
                Color color_;
            };
            std::vector<PointLight_t> pointLights;

            struct DirectionalLight_t {
                Math::Vector3D direction_;
                Color color_;
                double intensity;
            };
            std::vector<DirectionalLight_t> directionalLights;

            struct DiffuseLight_t {
                Color color_;
                Math::Vector3D direction_;
                double intensity_;
            };
            std::vector<DiffuseLight_t> diffuseLights;

            struct AmbientLight_t {
                Color color_;
            };
            std::vector<AmbientLight_t> ambientLights;

            std::vector<std::shared_ptr<IPrimitives>> primitives;
            std::vector<std::shared_ptr<IAllTypeLights>> lights;
            std::vector<std::shared_ptr<AllMaterials>> material;

            void getLights(const std::string& file);
            void getMaterials(const std::string& file);
            void set(const std::string& file);
            void parsespheres(const std::string& file);
            void parsecylindre(const std::string& file);
            void parsecones(const std::string& file);
            void parsehourglass(const std::string& file);
            void parseTriangles(const std::string& file);
            void parsePlan(const std::string& file);
            // void processPlane(const libconfig::Setting& planeSetting, Plane_t& newPlane);
            void setPrimitives();
            void setMaterials();
            void setLights();
    };
}

#endif