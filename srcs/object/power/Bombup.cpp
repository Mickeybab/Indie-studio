/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Power
*/

#include "Bombup.hpp"
#include "pathRessources.hpp"

Bombup::Bombup(int x, int y):
_type(BOMBUP)
{
    _render->setX(x);
    _render->setY(y);
    _render->setZ(4);
    _render->setSizeX(10);
    _render->setSizeY(10);
    _render->setSizeZ(10);
    _render->setPath(BOMB_UP_PATH);
    _render->setTexture(BOMB_UP_TEXTURE);
}

Bombup::~Bombup()
{
    delete(_render);
}