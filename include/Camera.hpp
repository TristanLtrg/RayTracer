/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Camera.hpp
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "Vector3D.hpp"
    #include "Screen.hpp"
    #include "Ray.hpp"
    #include <string>
    #include <libconfig.h++>

namespace RayTracer {
    class Camera {
    public:
        Math::Vector3D original_pos;
        Rectangle3D screen;
        int screen_width, screen_height;
        double camera_fov;
        Math::Vector3D camera_pos;
        Math::Vector3D camera_rotation;

        Camera();
        Camera(const Math::Vector3D& origin_, const Rectangle3D& screen_);
        
        void getCam(const std::string& file);

        Ray getRay(double u, double v) const;

        Camera setCamera();

    private:
        bool loadCameraSettings(const libconfig::Setting& settings);

        void updateViewport();
    };
}

#endif