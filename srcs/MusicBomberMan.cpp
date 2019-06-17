/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** MusicBomberMan
*/

#include "MusicBomberMan.hpp"

MusicBomberMan::MusicBomberMan() :
_menu(new sf::Music()),
_game(new sf::Music()),
_pause(new sf::Music())
{
    _menu->openFromFile(MUSIC_MENU);
    _menu->setLoop(true);
    _game->openFromFile(MUSIC_GAME);
    _game->setLoop(true);
    _pause->openFromFile(MUSIC_PAUSE);
    _pause->setLoop(true);
    _menu->setVolume(50);
}

MusicBomberMan::~MusicBomberMan()
{
    delete(_menu);
    delete(_game);
    delete(_pause);
}

void MusicBomberMan::playMusicMenu()
{
    _menu->setRelativeToListener(true);
    _menu->play();
}

void MusicBomberMan::playMusicGame()
{
    _game->play();
}

void MusicBomberMan::playMusicPause()
{
    _pause->play();
}

void MusicBomberMan::mute()
{
    _menu->setVolume(0);
    _game->setVolume(0);
    _pause->setVolume(0);
}

void MusicBomberMan::unMute()
{
    _menu->setVolume(100);
    _game->setVolume(100);
    _pause->setVolume(100);
}

void MusicBomberMan::offMusic()
{
    #ifdef __linux__
    if (_menu->getStatus() == sf::Music::Playing)
        _menu->stop();
    if (_game->getStatus() == sf::Music::Playing)
        _game->stop();
    if (_pause->getStatus() == sf::Music::Playing)
        _pause->stop();
    #endif
}