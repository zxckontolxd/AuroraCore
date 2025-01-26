#include <SFML/Graphics/Font.hpp>
#include <unordered_map>
#include <iostream>
#include"utils/logger/mainLogger.h"

class FontManager
{
private:
    static MainLogger *logger;
    static std::unordered_map<std::string, sf::Font*> fontMap;

    static FontManager *instance;

    FontManager();

    FontManager(const FontManager&) = delete;
    FontManager& operator=(const FontManager&) = delete;
public:
    static FontManager* get();
    static bool loadFont(std::string name, std::string path);
    static sf::Font* getFont(std::string name);
};
