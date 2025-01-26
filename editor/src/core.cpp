#include "core.h"

Core::Core()
{
    mainWindowState = new MainWindowState();

    //window = new sf::RenderWindow(sf::VideoMode(640, 640), "Aurora Core");
    stateManager = new StateManager("MainWindow", mainWindowState);
    fontManager = FontManager::get();
    fontManager->loadFont("dsa", "dsa");
    fontManager->getFont("safxzc");
}

Core::~Core()
{
    delete mainWindowState;
    delete stateManager;
}

void Core::start()
{
    while(stateManager->getWindow())
    {
        stateManager->update();
    }
}
