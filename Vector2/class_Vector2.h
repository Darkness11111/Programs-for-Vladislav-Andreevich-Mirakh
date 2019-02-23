// class_Vector2.h - VT_0.0
#pragma once
#include <cmath>
#include <iostream>
#include <assert.h>


const double PI = 3.141593;


class Vector2
{
    private:
        double x_;
        double y_;

    public:
        ~Vector2( ) { }
        Vector2( )
        {
            x_ = y_ = 0.;
        }
        Vector2(double x_arg, double y_arg)
        {
            x_ = x_arg;
            y_ = y_arg;
        }

        Vector2 & operator=(const Vector2 & vector);
        Vector2 operator+(const Vector2 & vector) const;
        Vector2 & operator+=(const Vector2 & vector);
        Vector2 operator-(const Vector2 & vector) const;
        Vector2 operator-(void) const;
        Vector2 & operator-=(const Vector2 & vector);
        Vector2 operator*(double k) const;
        Vector2 operator/(double k) const;
        double operator*(const Vector2 & vector) const;
        double operator^(const Vector2 & vector) const;

        double len(void) const;
        double square_len(void) const;
        void reset(double x_arg, double y_arg);
        Vector2 orthogonal(void) const;
        void rotate(double degree);
        Vector2 get_rotated(double degree) const;
        Vector2 norm(void);

        friend Vector2 operator*(double k, const Vector2 & vector);
        friend std::ostream & operator<<(std::ostream & os, const Vector2 & vector);

};
