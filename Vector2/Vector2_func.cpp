// Vector2_func.cpp - VT_0.0
#pragma once
#include "class_Vector2.h"


int Vector2::operator=(const Vector2 & vector)
{
    x = vector.x;
	y = vector.y;
	z = vector.z;
    

	if (x || y || z)
	{
		return 1;
	}
    return 0;
}


Vector2 Vector2::operator+(const Vector2 & vector)
{
    Vector2 sum;
	sum.x = x + vector.x;
	sum.y = y + vector.y;
	sum.z = z + vector.z;	


	return sum;
}


Vector2 Vector2::operator-(const Vector2 & vector)
{
    Vector2 difference;
	difference.x = x - vector.x;
	difference.y = y - vector.y;
	difference.z = z - vector.z;	


	return difference;
}


Vector2 Vector2::operator*(double k) const
{
    Vector2 composition;
	composition.x = x * k;
	composition.y = y * k;
	composition.z = z * k;


	return composition;
}


double Vector2::operator*(const Vector2 & vector)
{
    double scalar;
	scalar = x * vector.x + y * vector.y + z * vector.z;


    return scalar;
}


Vector2 Vector2::operator^(const Vector2 & vector)
{
	Vector2 vect_composition;
	vect_composition.x = y * vector.z - z * vector.y;
	vect_composition.y = z * vector.x - x * vector.z;
	vect_composition.z = x * vector.y - y * vector.x;


    return vect_composition;
}


double Vector2::len(void)
{
    double len;
	len = sqrt(x * x + y * y + z * z);


	return len;
}


void Vector2::reset(double x_arg, double y_arg, double z_arg)
{
    x = x_arg;
	y = y_arg;
	z = z_arg;


	return;
}


Vector2 operator*(double k, const Vector2 & vector)
{
    return vector * k;
}


std::ostream & operator<<(std::ostream & os, const Vector2 & vector)
{
    os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";


	return os; 
}
