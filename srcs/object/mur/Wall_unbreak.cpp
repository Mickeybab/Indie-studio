/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Mur_indestructible
*/

#include "Wall_unbreak.hpp"
#include "pathRessources.hpp"

Wall_unbreak::Wall_unbreak(int x, int y):
_type(WALL_UNBREAK)
{
    _render->setX(x);
    _render->setY(y);
    _render->setZ(1);
    _render->setSizeX(3000);
    _render->setSizeY(3000);
    _render->setSizeZ(3000);
    _render->setPath(WALL_UNBREACKABLE_PATH);
    _render->setTexture(WALL_BREACKABLE_TEXTURE);
}

Wall_unbreak::~Wall_unbreak()
{
    delete(_render);
}
