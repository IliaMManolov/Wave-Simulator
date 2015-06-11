#ifndef APP_HPP
#define APP_HPP

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Wave.hpp"
#include "Emitter.hpp"
//#include "Receiver.hpp"

//#include "UI.hpp"


class App
{
    public:
        App();
        void run();


    private:

        void handleEvents();
        void update();
        void draw();


        sf::RenderWindow mWindow;

        //UserInterface mUI;

        std::vector<Wave> mWaves;
        std::vector<Emitter> mEmitters;
        //std::vector<Receiver> mReceivers;
};


#endif // APP_HPP
