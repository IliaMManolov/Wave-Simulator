#ifndef RECEIVER_HPP
#define RECEIVER_HPP

#include "SFML/Graphics.hpp"
#include "Wave.hpp"
#include <vector>

//Unfinished


class Receiver
{
    public:
        Receiver();

    private:
        update(const std::vector<Wave> &waves)

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif // RECEIVER_HPP
