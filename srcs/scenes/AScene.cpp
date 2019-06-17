/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** AScene
*/

#include "AScene.hpp"

AScene::AScene():
_new(true), _gameOver(false)
{
}

void AScene::addObject(IObject *obj)
{
    _map[obj->get_render()->getY()/100][obj->get_render()->getX()/100] = obj;
    _obj.push_back(obj);
}
