/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** FactoryObject
*/

#include "FactoryObject.hpp"

FactoryObject::FactoryObject():
_player_id(1)
{
}

FactoryObject::~FactoryObject()
{
}

IObject *FactoryObject::getObject(type_object_e type, int x, int y)
{
    switch (type) {
        case WALL_BREAK: return new Wall_break(x * 100, y * 100); break;
        case WALL_UNBREAK: return new Wall_unbreak(x * 100, y * 100); break;
        case FLOOR: return new Floor(x * 100, y * 100); break;
        case BASIC_PLAYER: return new Player(1, x * 100, y * 100); break;
        case IA: _player_id++;
            return new PlayerAI(_player_id, x * 100, y * 100); break;
        case BOMBUP: return new Bombup(x * 100, y * 100); break;
        case FIREUP: return new Fireup(x * 100, y * 100); break;
        case SPEEDUP: return new Speedup(x * 100, y * 100); break;
        case WALLPASS: return new Wallpass(x * 100, y * 100); break;
        case BOMB: return new Bomb(x, y); break;
        default: return NULL; break;
    }
}