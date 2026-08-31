/*
** EPITECH PROJECT, 2024
** raytracer_epitech
** File description:
** Color
*/

#include "HandleColor.hpp"
#include <iostream>
#include <algorithm>

namespace RayTracer {
    Color::Color() : r(0.0), g(0.0), b(0.0) {}

    Color::Color(double red, double green, double blue) : r(red), g(green), b(blue) {}

    double Color::red() const { return r; }
    double Color::green() const { return g; }
    double Color::blue() const { return b; }

    Color Color::operator+ (const Color& c) const
    {
        return Color(r + c.r, g + c.g, b + c.b);
    }

    Color Color::operator* (double k) const
    {
        return Color(k * r, k * g, k * b);
    }

    Color Color::operator* (const Color& c) const
    {
        return Color(r * c.r, g * c.g, b * c.b);
    }

    Color Color::operator/(double scalar) const
    {
        return Color(r / scalar, g / scalar, b / scalar);
    }

    Color Color::getColor() const
    {
        return *this;
    }

    Color& Color::operator+=(const Color& other)
    {
        r += other.r;
        g += other.g;
        b += other.b;
        return *this;
    }

    void Color::clamp()
    {
        double max = 255.0;

        r = std::min(std::max(r / max, 0.0), 1.0);
        g = std::min(std::max(g / max, 0.0), 1.0);
        b = std::min(std::max(b / max, 0.0), 1.0);
    }

    void Color::toRGB()
    {
        r = std::clamp(r, 0.0, 1.0) * 255;
        g = std::clamp(g, 0.0, 1.0) * 255;
        b = std::clamp(b, 0.0, 1.0) * 255;
    }
}
