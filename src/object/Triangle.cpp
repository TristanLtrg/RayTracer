/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Triangle
*/

#include "Triangle.hpp"
#include <cmath>

namespace RayTracer {

    Triangle::Triangle(const Math::Vector3D &point1, const Math::Vector3D &point2, const Math::Vector3D &point3)
        : m_point1(point1), m_point2(point2), m_point3(point3) {}

    Math::Vector3D Triangle::point1() const
    {
        return m_point1;
    }

    Math::Vector3D Triangle::point2() const
    {
        return m_point2;
    }

    Math::Vector3D Triangle::point3() const
    {
        return m_point3;
    }

    std::optional<double> Triangle::lightHits(const Ray& ray) const
    {
        Math::Vector3D edge1 = m_point2 - m_point1;
        Math::Vector3D edge2 = m_point3 - m_point1;
        Math::Vector3D normal = Math::Vector3D::cross(edge1, edge2).normalize();
        double denom = normal.dot(ray.new_direction);

        if (std::abs(denom)) {
            return std::nullopt;
        }
        double t = (m_point1 - ray.original_pos).dot(normal) / denom;
        if (t < 0) {
            return std::nullopt;
        }
        Math::Vector3D intersection_point = ray.original_pos + ray.new_direction * t;
        Math::Vector3D edge1_normal = Math::Vector3D::cross(intersection_point - m_point1, m_point2 - m_point1);
        Math::Vector3D edge2_normal = Math::Vector3D::cross(intersection_point - m_point2, m_point3 - m_point2);
        Math::Vector3D edge3_normal = Math::Vector3D::cross(intersection_point - m_point3, m_point1 - m_point3);
        if (edge1_normal.dot(normal) > 0 && edge2_normal.dot(normal) > 0 && edge3_normal.dot(normal) > 0) {
            return t;
        }
        return std::nullopt;
    }

    Math::Vector3D Triangle::getNormalize(const Math::Vector3D& position) const {
        Math::Vector3D edge1 = m_point2 - m_point1;
        Math::Vector3D edge2 = m_point3 - m_point1;
        Math::Vector3D normal = Math::Vector3D::cross(edge1, edge2).normalize();
        return normal;
    }
}
