/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Sol
*/

#include "Floor.hpp"
#include "pathRessources.hpp"

Floor::Floor(int x, int y):
_type(FLOOR)
{
    _render->setX(x);
    _render->setY(y);
    _render->setZ(-30);
    _render->setSizeX(3000);
    _render->setSizeY(3000);
    _render->setSizeZ(3000);
    _render->setPath(FLOOR_PATH);
    _render->setTexture(FLOOR_TEXTURE);
}

Floor::~Floor()
{
    delete(_render);
}