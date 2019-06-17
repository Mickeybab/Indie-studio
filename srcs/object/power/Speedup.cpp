/*
** EPITECH PROJECT, 2019
** Tech2
** File description:
** Speedup
*/

#include "Speedup.hpp"
#include "pathRessources.hpp"

Speedup::Speedup(int x, int y):
_type(SPEEDUP)
{
    _render->setX(x);
    _render->setY(y);
    _render->setZ(-10);
    _render->setSizeX(40);
    _render->setSizeY(40);
    _render->setSizeZ(40);
    _render->setPath(SPEED_UP_PATH);
    _render->setTexture(SPEED_UP_TEXTURE);
}

Speedup::~Speedup()
{
    delete(_render);
}
