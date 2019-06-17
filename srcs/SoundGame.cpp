/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** SoundGame
*/

#include "SoundGame.hpp"

SoundGame::SoundGame()
{
}

SoundGame::~SoundGame()
{
}

sf::Music *SoundGame::createMusic(std::string path)
{
    sf::Music *music = new sf::Music();

    music->openFromFile(path);
    music->play();
    return music;
}