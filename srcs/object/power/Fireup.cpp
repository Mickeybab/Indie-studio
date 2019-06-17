/*
** EPITECH PROJECT, 2019
** Tech2
** File description:
** Fireup
*/

#include "Fireup.hpp"
#include "pathRessources.hpp"

Fireup::Fireup(int x, int y):
_type(FIREUP)
{
    _render->setX(x);
    _render->setY(y);
    _render->setZ(10);
    _render->setSizeX(65);
    _render->setSizeY(65);
    _render->setSizeZ(65);
    _render->setPath(FIRE_UP_PATH);
    _render->setTexture(FIRE_UP_TEXTURE);
}

Fireup::~Fireup()
{
    delete(_render);
}
