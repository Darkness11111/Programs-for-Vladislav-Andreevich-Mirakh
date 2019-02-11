#include <iostream>
#include <cstdlib>
#include "book.h"
#include "book_func.cpp"


enum errors
{
	SUCCESS = 0
};


int error_func(int code_error);


using std::cout;
using std::cin;
using std::endl;
int main(int argc, char* argv[ ])
{
    using std::cout;
    using std::cin;
    using std::endl;


	if (argc <= 1)
	{
        cout << "You should enter names of files to read!!!\n";
        return 0;
	}


    for (int ind = 1; ind < argc; ind++)
    {
    	Book book_count;
    	cout << ind << " book:\n";
    	int code_error = book_count.get_book(argv[ind]);
        if (code_error)
        {
    	    return error_func(code_error);
    	}
    	code_error = book_count.write_book( );
        if (code_error)
        {
    	    return error_func(code_error);
    	}
    	cout << "\n\n\n\n\n";
    }


    return error_func(SUCCESS);
}


int error_func(int code_error)
{
	switch (code_error)
    {
        case SUCCESS:
            return EXIT_SUCCESS;
        default:
            cout << "Strange error!!!\n";
            return EXIT_FAILURE;
    }
}
