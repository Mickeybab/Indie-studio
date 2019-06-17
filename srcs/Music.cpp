/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Music
*/

#ifdef _WIN32

#include "Music.hpp"

sf::Music::Music()
{
    ;
}

sf::Music::~Music()
{
    ;
}

void sf::Music::play()
{
    ;

}

void sf::Music::stop()
{
    ;
}

void sf::Music::loop()
{
    ;
}

sf::Music *sf::Music::openFromFile(std::string)
{
    sf::Music *musicObject = new(sf::Music);

    return(musicObject);
}

#endif