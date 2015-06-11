#include "Emitter.hpp"
#include <iostream>


Emitter::Emitter (sf::Time p, sf::Vector2f position, sf::Color color, float speed, float circleRadius)
: period(p)
, waveSpeed(speed)
{
    this->setPosition(position);
    circle.setFillColor(color);
    circle.setRadius(circleRadius);
    circle.setPosition(-circleRadius, -circleRadius);
    timer.restart();
    //std::cout<<this->getPosition().x<<' '<<this->getPosition().y<<std::endl;
}

void Emitter::update(std::vector<Wave> &waves)
{
    if (timer.getElapsedTime()>period)
    {
        waves.push_back(Wave(this->getPosition(), waveSpeed));
        timer.restart();
    }

    //std::cout<<this->getPosition().x<<' '<<this->getPosition().y<<std::endl;
}

void Emitter::setPeriod(sf::Time p)
{
    period = p;
}

sf::Time Emitter::getPeriod() const
{
    return period;
}


void Emitter::setColor(sf::Color color)
{
    circle.setFillColor(color);
}

sf::Color Emitter::getColor() const
{
    return circle.getFillColor();
}


void Emitter::setWaveSpeed(float speed)
{
    waveSpeed = speed;
}

float Emitter::getWaveSpeed() const
{
    return waveSpeed;
}


void Emitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();

    target.draw(circle, states);
}
