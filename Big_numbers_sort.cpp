#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 


using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::sort;
using std::endl;


bool compare_func(string str1, string str2);


int main( )
{
    cout << "Enter number of numbers))\n";
    int N = 0;
    cin >> N;
    cin.get( );
    vector<string> vect(N);
    for (int ind = 0; ind < N; ind++)
    {
    	cout << "Enter " << ind + 1 << " string\n";
        cin >> vect[ind];
    }
    

    
    sort(vect.begin( ), vect.end( ), compare_func);
    cout << "Sorted nubers:\n";
    for (int ind = 0; ind < N; ind++)
    {
        cout << vect[ind] << endl;
    }    


    return 0;
}


bool compare_func(string v1, string v2)
{
    int len1 = v1.size( ), len2 = v2.size( );
    return len1 != len2 ? len1 < len2 : v1 <= v2;
}
