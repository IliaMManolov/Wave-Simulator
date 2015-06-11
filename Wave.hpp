#ifndef WAVE_HPP
#define WAVE_HPP

#include <SFML/Graphics.hpp>

class Wave : public sf::Drawable, public sf::Transformable
{
    public:
        Wave();
        Wave(sf::Vector2f position, float s);
        Wave(sf::Vector2f position, float s, float thick, sf::Color outline);

        void update();

        float getRadius() const;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        float speed;
        sf::CircleShape ring;
        sf::Vector2f centre;
};


#endif // WAVE_HPP
