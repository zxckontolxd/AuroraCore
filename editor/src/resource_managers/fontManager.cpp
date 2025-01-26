#include "resourceManagers/fontManager.h"

FontManager* FontManager::instance = nullptr;
MainLogger* FontManager::logger = nullptr;
std::unordered_map<std::string, sf::Font*> FontManager::fontMap;

FontManager::FontManager()
{
    logger = MainLogger::get();
}

FontManager* FontManager::get()
{
    if(instance == nullptr)
        instance = new FontManager();
    return instance;
}

bool FontManager::loadFont(std::string name, std::string path)
{
    if(fontMap.find(name) != fontMap.end())
    {
        //fix it with errorf
        std::string str = "Font with name " + name + " already exist: " + path;
        logger->error(str);
        return false;
    }

    std::string str = "Loading font " + name + ": " + path;
    logger->info(str);

    sf::Font *font = new sf::Font;
    if(!font->loadFromFile(path))
    {
        std::string str = "Cannot load font: " + path;
        logger->error(str);
        return false;
    }

    fontMap[name] = font;

    str = "Loaded font " + name + ": " + path;
    logger->info(str);

    return true;
}

sf::Font* FontManager::getFont(std::string name)
{
    auto it = fontMap.find(name);
    if(it == fontMap.end())
    {
        logger->error("Can't find font: " + name);
        return nullptr;
    }
    return it->second;
}
