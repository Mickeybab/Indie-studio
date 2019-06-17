/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Player
*/

#include "Player.hpp"
#include "pathRessources.hpp"

Player::Player(int id, float x, float y):
_type(BASIC_PLAYER), _id(id)
{
    _render->setX(x);
    _render->setY(y);
    _render->setZ(15);
    _render->setSizeX(100);
    _render->setSizeY(100);
    _render->setSizeZ(100);
    _render->setPath(CHARA_PATH);
    _render->setTexture(CHARA_TEXTURE);
}

Player::~Player()
{
    delete(_render);
}

void Player::move(int dir)
{
    if (_moving == false && _end == -1) {
        switch(dir) {
            case 0: _end = _render->getY() + 100; break;
            case 180: _end = _render->getY() - 100; break;
            case 90: _end = _render->getX() + 100; break;
            case 270: _end = _render->getX() - 100; break;
        }
        _render->getRessource()->setRun();
        _moving = true;
        _render->setRotation(dir);
    }
}
void Player::stopMove()
{
    return;
}
