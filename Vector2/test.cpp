#include <iostream>
#include "class_Vector2.h"


int main( )
{
	using std::endl;
	using std::atan2;
	using std::cout;


    cout << "Assign vector:\n";
    Vector2 vector1 = Vector2(3.4, 5.6);
    cout << "vector1 == " << vector1 << endl;
    Vector2 vector2 = vector1;
    cout << "vector2 = vector1 =  " << vector2 << endl;
    cout << "\n\n\n";

    cout << "Operator +:\n";
    cout << "vector1 = " << vector1 << endl;
    Vector2 vector3 = Vector2(7.5, 6);
    cout << "vector3 = " << vector3 << endl;
    cout << "vector1 + vector3 = " << (vector1 + vector3) << endl;
    cout << "\n\n\n";

    cout << "Operator -:\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "vector3 = " << vector3 << endl;
    cout << "vector1 - vector3 = " << (vector1 - vector3) << endl;
    cout << "\n\n\n";

    cout << "Operator +=:\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "vector3 = " << vector3 << endl;
    vector1 += vector3;
    cout << "vector1 += vector3; vector1 =  " << vector1 << endl;   
    cout << "\n\n\n";

    cout << "Operator -=:\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "vector3 = " << vector3 << endl;
    vector1 -= vector3;
    cout << "vector1 -= vector3; vector1 =  " << vector1 << endl; 
    cout << "\n\n\n";

    cout << "Operator -(unary):\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "-vector1 = " << -vector1 << endl;       
    cout << "\n\n\n";
    
    cout << "Operator *(on digit):\n";
    cout << "vector1 = " << vector1 << endl;
    double k = 3.5;
    cout << "k = " << k << endl;
    cout << "vector1 * k = " << vector1 * k << endl; 
    cout << "k * vector1 = " << k * vector1 << endl;      
    cout << "\n\n\n"; 

    cout << "Operator /:\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "k = " << k << endl;
    cout << "vector1 / k = " << vector1 / k << endl;       
    cout << "\n\n\n";

    cout << "Operator *(scalar):\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "vector2 = " << vector2 << endl;
    cout << "vector1 * vector2 = " << vector1 * vector2 << endl;       
    cout << "\n\n\n";  

    cout << "Operator ^:\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "vector3 = " << vector3 << endl;
    cout << "vector1 ^ vector2 = " << (vector1 ^ vector3) << endl;       
    cout << "\n\n\n";  

    cout << "len( ):\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "vector1.len( ) = " << vector1.len( ) << endl;       
    cout << "\n\n\n";    

    cout << "square_len( ):\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "vector1.square_len( ) = " << vector1.square_len( ) << endl;       
    cout << "\n\n\n";    

    cout << "reset( ):\n";
    cout << "vector1 = " << vector1 << endl;
    vector1.reset(1., 0.);
    cout << "vector1.reset(1., 0.). vector1 = " << vector1 << endl;       
    cout << "\n\n\n"; 

    cout << "orthogonal( ):\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "vector1.orthogonal( ) = " << vector1.orthogonal( ) << endl;       
    cout << "\n\n\n"; 

    cout << "rotate( ):\n";
    cout << "vector1 = " << vector1 << endl;
    vector1.rotate(45);
    cout << "vector1.rotate(45). vector1 = " << vector1 << endl;       
    cout << "\n\n\n"; 

    cout << "get_rotated( ):\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "vector1.get_rotated(45) = " << vector1.get_rotated(45) << endl;       
    cout << "\n\n\n"; 

    cout << "norm( ):\n";
    cout << "vector1 = " << vector1 << endl;
    cout << "vector1.norm( ) = " << vector1.norm( ) << endl;       
    cout << "\n\n\n"; 

    return 0;
}
