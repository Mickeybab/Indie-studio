/*
** EPITECH PROJECT, 2019
** Tech2
** File description:
** Wallpass
*/

#include "Wallpass.hpp"
#include "pathRessources.hpp"

Wallpass::Wallpass(int x, int y):
_type(WALLPASS)
{
    _render->setX(x);
    _render->setY(y);
    _render->setZ(10);
    _render->setSizeX(100);
    _render->setSizeY(100);
    _render->setSizeZ(100);
    _render->setPath(WALL_PASS_PATH);
    _render->setTexture(WALL_PASS_TEXTURE);
}

Wallpass::~Wallpass()
{
    delete(_render);
}
