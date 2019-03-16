#include <cmath>
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <vector>
#include <assert.h>
#include <unistd.h> 


const float SIZE_X = 1000.f;
const float SIZE_Y = 1000.f;
const float ELEMENTARY_SIZE = 4.f;
const int PLUS = 1;
const int MINUS = 0;
const float CRITICAL_DIST = 5.f;
const float ELEM_LEN = 5.;
sf::Vector2i mouse_position;

void norm_vect(sf::Vector2f & vect);
int draw_vect(sf::RenderWindow & window, const std::vector <sf::Sprite> & vect);
int add_charge(const sf::RenderWindow & window, std::vector <sf::Sprite> & vect, const sf::Texture & texture);
sf::Vector2f calculate_E_i(const sf::Sprite & sprite, sf::Vector2f & pos_now, int sign);
sf::Vector2f claculate_E(const sf::RenderWindow & window, const std::vector <sf::Sprite> & minus_vect,
                         const std::vector <sf::Sprite> & plus_vect, sf::Vector2f & pos_now);
void create_lines(sf::RenderWindow & window, const std::vector <sf::Sprite> & minus_vect, 
	       const std::vector <sf::Sprite> & plus_vect, std::vector <sf::Vertex> & lines);
void draw_lines(sf::RenderWindow & window, const std::vector <sf::Vertex> & lines);


int main( )
{
    sf::RenderWindow window(sf::VideoMode(SIZE_X, SIZE_Y), "Distibution!");
	sf::Event event;
    std::vector <sf::Vertex> lines;

    // Create sprite for plus and minus
    sf::Texture plus_tex;
    sf::Texture minus_tex;
    plus_tex.loadFromFile("plus.png");
    minus_tex.loadFromFile("minus.png");

    // vector of charges
    std::vector <sf::Sprite> plus_vect;
    std::vector <sf::Sprite> minus_vect;    


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
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            add_charge(window, plus_vect, plus_tex); 
            lines.clear( );
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            add_charge(window, minus_vect, minus_tex);
            lines.clear( );           
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            create_lines(window, minus_vect, plus_vect, lines);
        }


        window.clear(sf::Color::Black);
        draw_lines(window, lines);
        draw_vect(window, minus_vect);
        draw_vect(window, plus_vect);
        window.display( );

    }
    
    return EXIT_SUCCESS;
}


int draw_vect(sf::RenderWindow & window, const std::vector <sf::Sprite> & vect)
{
	    for (int ind = 0; ind < vect.size( ); ind++)
        {
        	window.draw(vect[ind]);
        }

        return 0;
}

int add_charge(const sf::RenderWindow & window, std::vector <sf::Sprite> & vect, const sf::Texture & texture)
{
	mouse_position = sf::Mouse::getPosition(window);
    vect.push_back(sf::Sprite(texture));
    vect[vect.size( ) - 1].setPosition(mouse_position.x, mouse_position.y);
    sf::Vector2u texture_size = vect[vect.size( ) - 1].getTexture( ) -> getSize( );
    vect[vect.size( ) - 1].setOrigin(texture_size.x / 2, texture_size.y / 2);

    return 0;
}


sf::Vector2f claculate_E(const sf::RenderWindow & window, const std::vector <sf::Sprite> & minus_vect,
                         const std::vector <sf::Sprite> & plus_vect, sf::Vector2f & pos_now)
{
    mouse_position = sf::Mouse::getPosition(window);
    float x = pos_now.x;
    float y = pos_now.y;
    sf::Vector2f E;

	for (int ind = 0; ind < minus_vect.size( ); ind++)
    {
        E += calculate_E_i(minus_vect[ind], pos_now, MINUS);
    }
	for (int ind = 0; ind < plus_vect.size( ); ind++)
    {
        E += calculate_E_i(plus_vect[ind], pos_now, PLUS);
    }
    norm_vect(E);
    return E;
}


sf::Vector2f calculate_E_i(const sf::Sprite & sprite, sf::Vector2f & pos_now, int sign)
{
	assert(sign == PLUS || sign == MINUS);
    
    sf::Vector2f sprite_pos = sprite.getPosition( );
    float x_pos = sprite_pos.x;
    float y_pos = sprite_pos.y;    
    float r = sqrt(pow(x_pos - pos_now.x, 2) + pow(y_pos - pos_now.y, 2));
    sf::Vector2f E_i = (sf::Vector2f(x_pos - pos_now.x, y_pos - pos_now.y) * 5000.f) / float(pow(r, 3));
    if (sign == PLUS)
    {
    	E_i *= (-1.f);
    }

    return E_i;
}


void norm_vect(sf::Vector2f & vect)
{
    float r = sqrt(pow(vect.x, 2) + pow(vect.y, 2));
    vect *= (ELEMENTARY_SIZE / r);
    return;
}


void create_lines(sf::RenderWindow & window, const std::vector <sf::Sprite> & minus_vect, 
	       const std::vector <sf::Sprite> & plus_vect, std::vector <sf::Vertex> & lines)
{
    mouse_position = sf::Mouse::getPosition(window);
    sf::Vector2f pos_now = sf::Vector2f(mouse_position.x, mouse_position.y);
    sf::Vector2f E;
    sf::Vector2f end_pos;
    lines.push_back(sf::Vertex(pos_now, sf::Color::Yellow));
    while (int(pos_now.x) < SIZE_X && int(pos_now.x) > 0 && int(pos_now.y) < SIZE_Y && int(pos_now.y) > 0)
    {
        for (int ind = 0; ind < minus_vect.size( ); ind++)
        {
            if (std::abs(pos_now.x - minus_vect[ind].getPosition( ).x) < CRITICAL_DIST &&
                std::abs(pos_now.y - minus_vect[ind].getPosition( ).y) < CRITICAL_DIST)
            {
                lines.back( ).color = sf::Color::Red;
                return;
            }
        }

        E = claculate_E(window, minus_vect, plus_vect, pos_now);
        end_pos = sf::Vector2f(E.x + pos_now.x, E.y + pos_now.y);
        lines.push_back(sf::Vertex(end_pos, sf::Color::Yellow));
        pos_now += E;
    }
    lines.back( ).color = sf::Color::Red;
    return;

}


void draw_lines(sf::RenderWindow & window, const std::vector <sf::Vertex> & lines)
{
	for (int ind = 0; ind < int(lines.size( )) - 1; ind++)
    { 
        if (lines[ind].color != sf::Color::Red)
        {
            window.draw(&lines[ind], 2, sf::Lines);
        }
    }

    return;
}
