/*
** EPITECH PROJECT, 2024
** RT
** File description:
** Color
*/

#ifndef HANDLECOLOR_HPP_
    #define HANDLECOLOR_HPP_

namespace RayTracer {
    class Color {
    public:
        double r, g, b;

        Color();
        Color(double red, double green, double blue);

        double red() const;
        double green() const;
        double blue() const;

        Color operator+ (const Color& c) const;
        Color operator* (double k) const;
        Color operator* (const Color& c) const;
        Color operator/(double scalar) const;

        Color getColor() const;
        Color& operator+=(const Color& other);

        void toRGB();
        void clamp();
    };
}

#endif