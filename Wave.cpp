#include "Wave.hpp"
#include <iostream>

Wave::Wave()
: speed (1.f)
{
    this->setPosition(0, 0);

    ring.setRadius(0);
    ring.setFillColor(sf::Color::Transparent);

    ring.setPointCount(9001);

    ring.setOutlineThickness(5.f);
    ring.setOutlineColor(sf::Color::Blue);       //Add RNGesus here
}

Wave::Wave(sf::Vector2f position, float s)
: speed (s)
{
    centre = position;
    this->setPosition(position);

    ring.setRadius(0);
    ring.setFillColor(sf::Color::Transparent);

    ring.setPointCount(128);

    ring.setOutlineThickness(5.f);
    ring.setOutlineColor(sf::Color::Blue);        //Add RNGesus here


    std::cout<<centre.x<<' '<<centre.y<<std::endl;
}

Wave::Wave(sf::Vector2f position, float s, float thick, sf::Color outline)
: speed (s)
{
    this->setPosition(position);

    ring.setRadius(0.f);
    ring.setFillColor(sf::Color::Transparent);

    ring.setPointCount(9001);

    ring.setOutlineThickness(thick);
    ring.setOutlineColor(outline);
}

void Wave::update()
{
    ring.setRadius(ring.getRadius()+speed);
    ring.setPosition(-ring.getRadius(), -ring.getRadius());
}

void Wave::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();

    target.draw(ring, states);
}

float Wave::getRadius() const
{
    return ring.getRadius();
}

