// class_Vector2.h - VT_0.0
#pragma once
#include <math.h>
#include <iostream>


class Vector2
{
    private:
        double x;
        double y;
        double z;
    public:
        Vector2( )
        {
            x = y = z = 0.;
        }
        Vector2(double x_arg, double y_arg, double z_arg)
        {
            x = x_arg;
            y = y_arg;
            z = z_arg;
        }

        int operator=(const Vector2 & vector);
        Vector2 operator+(const Vector2 & vector);
        Vector2 operator-(const Vector2 & vector);
        Vector2 operator*(double k) const;
        double operator*(const Vector2 & vector);
        Vector2 operator^(const Vector2 & vector);

        double len(void);
        void reset(double x_arg, double y_arg, double z_arg);

        friend Vector2 operator*(double k, const Vector2 & vector);
        friend std::ostream & operator<<(std::ostream & os, const Vector2 & vector);

};
