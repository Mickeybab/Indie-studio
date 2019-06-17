/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** PlayerAIAI
*/

#include "PlayerAI.hpp"
#include "pathRessources.hpp"

PlayerAI::PlayerAI(int id, float x, float y):
_type(IA), _id(id),
_alive(true)
{
    _render->setX(x);
    _render->setY(y);
    _render->setZ(3);
    _render->setSizeX(100);
    _render->setSizeY(100);
    _render->setSizeZ(100);
    _render->setPath(IA_PATH);
    _render->setTexture(IA_TEXTURE);
}

PlayerAI::~PlayerAI()
{
    delete(_render);
}

void PlayerAI::move(int dir)
{
    if (_moving == false && _end == -1) {
        switch(dir) {
            case 0: _end = _render->getY() + 100; break;
            case 180: _end = _render->getY() - 100; break;
            case 90: _end = _render->getX() + 100; break;
            case 270: _end = _render->getX() - 100; break;
        }
//        _render->getRessource()->setRun();
        _moving = true;
        _render->setRotation(dir);
    }
}

void PlayerAI::stopMove()
{
    return;
}
