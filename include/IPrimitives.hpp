/*
** EPITECH PROJECT, 2024
** RT
** File description:
** IPrimitives.hpp
*/

#ifndef IPRIMITIVES_HPP_
    #define IPRIMITIVES_HPP_

#include <string>
#include <libconfig.h++>
#include <optional>
#include "Ray.hpp"

namespace RayTracer {
    class IPrimitives  {
        public:
            virtual ~IPrimitives() = default;
            virtual std::optional<double> lightHits(const Ray& ray) const = 0;
            virtual Math::Vector3D getNormalize(const Math::Vector3D& position) const = 0;
            double distance;
        protected:
        private:
    };
}

#endif