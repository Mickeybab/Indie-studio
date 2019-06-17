/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Mur_destructible
*/

#include "Wall_break.hpp"
#include "pathRessources.hpp"

Wall_break::Wall_break(int x, int y):
_type(WALL_BREAK)
{
    _render->setX(x);
    _render->setY(y);
    _render->setZ(1);
    _render->setSizeX(3000);
    _render->setSizeY(3000);
    _render->setSizeZ(3000);
    _render->setPath(WALL_BREACKABLE_PATH);
    _render->setTexture(WALL_BREACKABLE_TEXTURE);
}

Wall_break::~Wall_break()
{
}
