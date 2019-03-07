#include <cmath>
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

const float SIZE_X = 1000.;
const float SIZE_Y = 1000.;
const float RADIUS = 200.;
const float CIRCLE_POS = 300.;
const float PI = 3.141592;
const float ALL_DEGREE = 360.;
const float THICKNESS = 3.;
const sf::Color ENV_COLOR = sf::Color::Green;


int main(int argc, char* argv[ ])
{
	if (argc <= 1)
	{
		std::cout << "Too few arguments for this function!!!\n";
		return EXIT_FAILURE;
	}
	int n = atoi(argv[1]);
    if (n <= 2)
    {
        std::cout << "I can't draw this figure!!!\n";
        return EXIT_FAILURE;
    }

    float one_degree = ALL_DEGREE / n;
    float r = RADIUS * cos(PI / n);

	sf::RenderWindow window(sf::VideoMode(SIZE_X, SIZE_Y), "Easy katka!");
	sf::Event event;

    sf::CircleShape circle1(RADIUS);
    circle1.setFillColor(ENV_COLOR);
    circle1.setPosition(CIRCLE_POS, CIRCLE_POS);
    circle1.setOutlineThickness(THICKNESS);
    circle1.setOutlineColor(sf::Color::Black);

    sf::CircleShape circle2(r);
    circle2.setFillColor(ENV_COLOR);
    circle2.setPosition(CIRCLE_POS + RADIUS - r, CIRCLE_POS + RADIUS - r);
    circle2.setOutlineThickness(THICKNESS);
    circle2.setOutlineColor(sf::Color::Black);


	while (window.isOpen( ))
	{
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close( );
            }
        }
        window.clear(ENV_COLOR);
	    window.draw(circle1);
	    window.draw(circle2);
	    for (int ind = 0; ind < n; ind++)
	    {
	    	sf::Vertex line[2] = 
            { 
    	        sf::Vertex(sf::Vector2f(CIRCLE_POS + RADIUS * (1 + sin((2 * PI * one_degree * ind) / ALL_DEGREE)),
    	        CIRCLE_POS + RADIUS * (1 - cos((2 * PI * one_degree * ind) / ALL_DEGREE))), sf::Color( )),
    	        sf::Vertex(sf::Vector2f(CIRCLE_POS + RADIUS * (1 + sin((2 * PI * one_degree * (ind + 1)) / ALL_DEGREE)),
    	        CIRCLE_POS + RADIUS * (1 - cos((2 * PI * one_degree * (ind + 1)) / ALL_DEGREE))), sf::Color( ))
            };
            window.draw(line, 2, sf::Lines);
	    }
        window.display( );
	}

	return EXIT_SUCCESS;
}
