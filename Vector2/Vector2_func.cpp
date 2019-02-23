// Vector2_func.cpp - VT_1.0
#include "class_Vector2.h"


Vector2 & Vector2::operator=(const Vector2 & vector) 
{
    x_ = vector.x_;
	y_ = vector.y_;
    

	return *this;
}


Vector2 Vector2::operator+(const Vector2 & vector) const
{
    Vector2 sum;
	sum.x_ = x_ + vector.x_;
	sum.y_ = y_ + vector.y_;	


	return sum;
}


Vector2 & Vector2::operator+=(const Vector2 & vector)
{
	x_ += vector.x_;
	y_ += vector.y_;


	return *this;
}


Vector2 Vector2::operator-(const Vector2 & vector) const
{
    Vector2 difference;
	difference.x_ = x_ - vector.x_;
	difference.y_ = y_ - vector.y_;


	return difference;
}


Vector2 Vector2::operator-(void) const
{
    return Vector2(-x_, -y_);
}


Vector2 & Vector2::operator-=(const Vector2 & vector)
{
	x_ -= vector.x_;
	y_ -= vector.y_;	


	return *this;
}


Vector2 Vector2::operator*(double k) const
{
    Vector2 composition;
	composition.x_ = x_ * k;
	composition.y_ = y_ * k;


	return composition;
}


Vector2 Vector2::operator/(double k) const
{
	assert(k != 0);


    Vector2 division;
	division.x_ = x_ / k;
	division.y_ = y_ / k;


	return division;
}


double Vector2::operator*(const Vector2 & vector) const
{
    double scalar;
	scalar = x_ * vector.x_ + y_ * vector.y_;


    return scalar;
}


double Vector2::operator^(const Vector2 & vector) const
{
	double vect_comp_len;
	vect_comp_len = x_ * vector.y_ - y_ * vector.x_;


    return vect_comp_len;
}


double Vector2::len(void) const
{
    double len;
	len = sqrt(x_ * x_ + y_ * y_);


	return len;
}


double Vector2::square_len(void) const
{
    double sqr_len;
	sqr_len = x_ * x_ + y_ * y_;


	return sqr_len;
}


void Vector2::reset(double x_arg, double y_arg)
{
    x_ = x_arg;
	y_ = y_arg;


	return;
}


Vector2 Vector2::orthogonal(void) const
{
    Vector2 orthgnl = Vector2(y_, -x_);
    return orthgnl;
}


void Vector2::rotate(double degree)
{
	double angle;
	if (!x_ && !y_)
	{
        return;
	}

    angle = atan2(y_, x_);
    angle += (degree * PI) / 180;

    double len = this -> len( );
    x_ = len * cos(angle);
    y_ = len * sin(angle);
    return;
}


Vector2 Vector2::get_rotated(double degree) const
{
	double angle;
	if (!x_ && !y_)
	{
        return *this;
	}

    angle = atan2(y_, x_);
    angle += (degree * PI) / 180;

    double len = this -> len( );
    return  Vector2(len * cos(angle), len * sin(angle));
}


Vector2 Vector2::norm(void)
{
	if (!x_ && !y_)
	{
		return Vector2(0., 0.);
	}

    double len = this -> len( );
    return Vector2(x_ / len, y_ / len);
}


Vector2 operator*(double k, const Vector2 & vector)
{
    return vector * k;
}


std::ostream & operator<<(std::ostream & os, const Vector2 & vector)
{
    os << "(" << vector.x_ << ", " << vector.y_ << ")";


	return os; 
}
