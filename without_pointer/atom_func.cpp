// atom_func.cpp VT 0.0
#include "atom.hpp"

Atom::Atom(const sf::RenderWindow & window)
{
	// Create texture 
    if (!molecule_texture_.loadFromFile("atom.png"))
    {
    	std::cout << "Can't load from file!\n";
    	return;
    }

    // Create position
    molecule_sprite_ = sf::Sprite(molecule_texture_);
    sf::Vector2u texture_size = molecule_texture_.getSize( );
    molecule_sprite_.setOrigin(texture_size.x / 2, texture_size.y / 2);
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);	
    molecule_sprite_.setPosition(mouse_position.x, mouse_position.y);

    // Create velocity
    srand(unsigned(time(0)));
    velocity_.x = (rand( ) % SPEED - 5) * 0.1;
    velocity_.y = (rand( ) % SPEED - 5) * 0.1;
    if (velocity_.x == 0. && velocity_.y == 0.)
    {
        velocity_.x += 1;
    }
    return;
}

Atom::~Atom(void)
{
}

Atom::Atom(const Atom & atm)
{
    molecule_texture_ = atm.molecule_texture_;
    velocity_ = atm.velocity_;
    molecule_sprite_ = atm.molecule_sprite_;
    return;
}

void Atom::move(void)
{
    sf::Vector2f pos_now = molecule_sprite_.getPosition( );
    pos_now.x += velocity_.x;
    pos_now.y += velocity_.y;
    molecule_sprite_.setPosition(pos_now.x, pos_now.y);

    return;
}

void Atom::top_bottom_wall(void)
{
    velocity_.y = -velocity_.y; 
    return;
}

void Atom::left_right_wall(void)
{
    velocity_.x = -velocity_.x; 
    return;
}

sf::Vector2f Atom::get_velocity(void) const
{
    return velocity_;
}
