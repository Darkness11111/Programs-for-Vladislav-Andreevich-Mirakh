#include <SFML/Graphics.hpp>
#include "atom.hpp"
#include <unistd.h>

const float SIZE_X = 1000.f;
const float SIZE_Y = 1000.f;


int add_molecule(const sf::RenderWindow & window, std::vector <Atom> & vect);
int draw_molecule(sf::RenderWindow & window, std::vector <Atom> & vect);

int main( )
{
    // Base classes.
    sf::RenderWindow window(sf::VideoMode(SIZE_X, SIZE_Y), "Distibution!");
	sf::Event event;


    std::vector <Atom> molecule_vect;


	while (window.isOpen( ))
	{
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close( );
            }
        }

        // Create charges. Mouse actions.
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            add_molecule(window, molecule_vect);     
        }

        window.clear(sf::Color::Black);
        draw_molecule(window, molecule_vect);
        window.display( );

    }
    
    return EXIT_SUCCESS;
}


int add_molecule(const sf::RenderWindow & window, std::vector <Atom> & vect)
{
    vect.push_back(Atom(window));
    return 0;
}

int draw_molecule(sf::RenderWindow & window, std::vector <Atom> & vect)
{
	    for (int ind = 0; ind < vect.size( ); ind++)
        {
            vect[ind].move( );
            sf::Vector2u uvect = vect[ind].molecule_texture_.getSize( );
            sf::Vector2f pos_now = vect[ind].molecule_sprite_.getPosition( );
            float right_side = pos_now.x + uvect.x;
            float left_side = pos_now.x - uvect.x;
            float top_side = pos_now.y - uvect.y;
            float bottom_side = pos_now.y + uvect.y;
            if (left_side <= 0 || right_side >= SIZE_X)
            {
                vect[ind].left_right_wall( );
            }
            else if (top_side <= 0 || bottom_side >= SIZE_Y)
            {
                vect[ind].top_bottom_wall( );
            } 
        	window.draw(vect[ind].molecule_sprite_);
        }

        return 0;
}
