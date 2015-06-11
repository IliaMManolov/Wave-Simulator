#include "App.hpp"

sf::ContextSettings settings(0, 0, 4, 2, 0);
sf::Time timePerFrame(sf::seconds(1.f/60.f));

App::App()
: mWindow(sf::VideoMode(800, 600), "Wave simulator", sf::Style::Default, settings)
//, mUI()
{
    mWindow.setVerticalSyncEnabled(true);
}

void App::run()
{
    sf::Clock timer;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;




    mEmitters.push_back(Emitter(sf::seconds(2.f), sf::Vector2f(100, 200)));

    while (mWindow.isOpen())
    {
        sf::Time elapsedTime = timer.restart();
		timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate>timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            handleEvents();
            update();
        }
        draw();
    }
}

void App::handleEvents()
{
    //Add runtime events here

    //Add stacked events here
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                mWindow.close();
                break;

            default:
                break;
        }
    }
}

void App::update()
{
    if (!mWaves.empty())
    {
        if (mWaves[0].getRadius()>2000.f) mWaves.erase(mWaves.begin());
    }

    for (unsigned int i=0;i<mWaves.size();i++)
        mWaves[i].update();

    for (unsigned int i=0;i<mEmitters.size();i++)
        mEmitters[i].update(mWaves);

    //for (int i=0;i<mReceivers.size();i++)
    //    mReceivers[i].update(mWaves);

    //mUI.update();
}

void App::draw()
{
    mWindow.clear();


    for (unsigned int i=0;i<mWaves.size();i++)
        mWindow.draw(mWaves[i]);

    for (unsigned int i=0;i<mEmitters.size();i++)
        mWindow.draw(mEmitters[i]);

    //for (int i=0;i<mReceivers.size();i++)
    //    mWindow.draw(mReceivers[i]);

    //mWindow.draw(mUI);

    mWindow.display();
}
