/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Camera.cpp
*/

#include "Camera.hpp"
#include <cmath>
#include <libconfig.h++>
#include <iostream>

namespace RayTracer {

    Camera::Camera() : original_pos(Math::Vector3D(0, 0, 0)), screen(Rectangle3D()), screen_width(1000), screen_height(800), camera_fov(70.0) {}

    Camera::Camera(const Math::Vector3D& origin_, const Rectangle3D& screen_)
        : original_pos(origin_), screen(screen_) {}

    void Camera::getCam(const std::string& file)
    {
        libconfig::Config cfg;
        try {
            cfg.readFile(file.c_str());
            libconfig::Setting& camera = cfg.lookup("camera");
            if (!loadCameraSettings(camera)) {
                std::cerr << "Error loading camera settings." << std::endl;
                exit(84);
            }
            updateViewport();
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
            exit(84);
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
            exit(84);
        }
    }

    Camera Camera::setCamera()
    {
        updateViewport();
        return *this;
    }

    bool Camera::loadCameraSettings(const libconfig::Setting& settings)
    {
        bool loaded = true;
    
        loaded &= settings.lookupValue("fov", camera_fov);
        loaded &= settings["resolution"].lookupValue("width", screen_width);
        loaded &= settings["resolution"].lookupValue("height", screen_height);
        loaded &= settings["position"].lookupValue("x", camera_pos.x);
        loaded &= settings["position"].lookupValue("y", camera_pos.y);
        loaded &= settings["position"].lookupValue("z", camera_pos.z);
        loaded &= settings["rotation"].lookupValue("x", camera_rotation.x);
        loaded &= settings["rotation"].lookupValue("y", camera_rotation.y);
        loaded &= settings["rotation"].lookupValue("z", camera_rotation.z);
        if (loaded) {
            updateViewport();
        }
        return loaded;
    }

    void Camera::updateViewport()
    {
        double aspect_ratio = static_cast<double>(screen_width) / screen_height;
        double viewport_height = 2.0 * tan((camera_fov / 2.0) * M_PI / 180.0);
        double viewport_width = aspect_ratio * viewport_height;
    
        screen = Rectangle3D(
            Math::Vector3D(camera_pos.x + 1.0, camera_pos.y - viewport_width / 2.0, camera_pos.z + viewport_height / 2.0),
            Math::Vector3D(0.0, viewport_width, 0.0),
            Math::Vector3D(0.0, 0.0, viewport_height)
        );
    }

    Ray Camera::getRay(double u, double v) const
    {
        Math::Vector3D dest = screen.pointAt(u, v);
        Math::Vector3D dir = (dest - original_pos).normalize();
        return Ray(original_pos, dir);
    }
}
