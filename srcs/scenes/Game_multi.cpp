/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Game_multi
*/

#include "Game_multi.hpp"
#include "Map.hpp"
#include "Player.hpp"

Game_multi::Game_multi() : _type(GAME)
{
    Map map;
    FactoryObject fac;
    IObject *player = fac.getObject(BASIC_PLAYER, 1, 1);
    IObject *player2 = new Player(2, 1100, 1100);
    IObject *ia3 = fac.getObject(IA, 1, 11);
    IObject *ia4 = fac.getObject(IA, 11, 1);

    _map = map.GetMap();
    _obj = map.getSceneList();
    _obj.push_back(player);
    _obj.push_back(player2);
    _obj.push_back(ia3);
    _obj.push_back(ia4);
    _map[1][1] = player;
    _map[11][11] = player2;
    _map[1][11] = ia3;
    _map[11][1] = ia4;
}

Game_multi::~Game_multi()
{
    for (IObject *obj: _obj) {
        if (obj) {
            obj->get_render()->getRessource()->setUnvisible();
            delete(obj);
        }
    }
}
