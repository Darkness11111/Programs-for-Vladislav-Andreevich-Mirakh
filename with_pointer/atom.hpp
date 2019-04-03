#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

const int SPEED = 11;

class Atom
{
    private:
    	sf::Vector2f velocity_;
    public:
    	sf::Texture molecule_texture_;
    	sf::Sprite* molecule_sprite_;

    	Atom(const sf::RenderWindow & window);
        ~Atom(void);
        Atom(const Atom & atm);

        Atom(void) = delete;
        Atom & operator=(const Atom &) = delete;

        void top_bottom_wall(void);
        void left_right_wall(void);
        sf::Vector2f get_velocity(void) const;

        void move(void);
};
