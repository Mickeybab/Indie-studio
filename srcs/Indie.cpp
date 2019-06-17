/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Indie
*/

#include "Indie.hpp"

Indie::Indie():
_start(false),
_music(new MusicBomberMan()),
_sound(new SoundGame())
{
}

Indie::~Indie()
{
    delete(_scene);
    delete(_music);
    delete(_sound);
}