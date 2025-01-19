#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(640, 640), "test");
    while(window->isOpen()) {
        sf::Event ev;
        while(window->pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                window->close();
            window->clear();
            window->display();
        }
    }
    cout << "Hello World!" << endl;
    return 0;
}
