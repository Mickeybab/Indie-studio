/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "pathRessources.hpp"

Bomb::Bomb(int x, int y):
_type(BOMB),
_radius(3),
_time(0)
{
    _render->setX(x);
    _render->setY(y);
    _render->setZ(1);
    _render->setSizeX(500);
    _render->setSizeY(500);
    _render->setSizeZ(500);
    _render->setRotation(0);
    _render->setPath(BOMB_PATH);
    _render->setTexture(BOMB_TEXTURE);
    _render->setRessource(NULL);
}

Bomb::~Bomb()
{
    delete(_render);
}