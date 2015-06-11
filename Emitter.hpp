#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "SFML/Graphics.hpp"
#include "Wave.hpp"

#include <vector>

class Emitter : public sf::Drawable, public sf::Transformable
{
    public:
        Emitter(sf::Time p = sf::seconds(1.f), sf::Vector2f position = sf::Vector2f(0, 0), sf::Color color = sf::Color::Red, float speed = 1.f, float circleRadius = 50.f);

        void update(std::vector<Wave> &waves);

        void setPeriod(sf::Time p);
        sf::Time getPeriod() const;

        void setColor(sf::Color color);
        sf::Color getColor() const;

        void setWaveSpeed(float speed);
        float getWaveSpeed() const;

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::Time period;
        sf::Clock timer;
        float waveSpeed;

        sf::CircleShape circle;

        //Add a textbox for the number of the emitter or other info
};


#endif // EMITTERS_HPP
