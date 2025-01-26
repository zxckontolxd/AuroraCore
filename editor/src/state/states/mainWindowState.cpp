#include "state/states/mainWindowState.h"

MainWindowState::MainWindowState()
{
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Aurora Core");
}

MainWindowState::~MainWindowState()
{
    delete window;
}

void MainWindowState::update()
{
    while(window->isOpen())
    {
        window->clear();
        window->display();
        sf::Event ev;
        while(window->pollEvent(ev))
        {
            if(ev.type == sf::Event::Closed)
            {
                window->close();
            }
        }
    }
}
