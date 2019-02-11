#ifndef BOOK_FUNC_CPP_CLASS
#define BOOK_FUNC_CPP_CLASS


Book::Book( )
{
	std::map <std::string, int> dict;
	num_words = 0;
}


Book::~Book( )
{

}


int Book::get_book(char* file_name)
{
    assert(file_name);


    std::ifstream fin(file_name);
    std::string str;
    bool fail = false;
    while (fin >> str)
    {
        dict[str] += 1;
        ++num_words;
    }   
    fin.close( );


    return 0;
}


int Book::write_book(void)
{
	int max_num = 0;
	int count = 0;
    for (auto it = dict.begin( ); it != dict.end( ); ++it)
    {
    	if (it -> second > max_num)
    	{
    		max_num = it -> second;
    	}
        std::cout << "Number of word \"" << it -> first << "\" = " << it -> second << std::endl; 
    }


    std::cout << "List of the most frequent words:\n";
    for (auto it = dict.begin( ); it != dict.end( ); ++it)
    {
        if (it -> second == max_num)
        {
            std::cout << "Number of word \"" << it -> first << "\" = " << it -> second << std::endl; 
        }
    }    
    std::cout << "Number of words = " << num_words;
    

    return 0;
}
#endif
