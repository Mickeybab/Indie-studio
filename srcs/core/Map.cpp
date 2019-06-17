/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
    std::srand(std::time(nullptr));
    InitMap();
    createNdLinkBonuses();
}

char    **Map::Get_maze()
{
    return(generator(3,
    (char *)"13",
    (char *)"13",
    (char *)"perfect"));
}

std::vector<std::vector<IObject *>> Map::GetMap()
{
    return (_map);
}

IObject *Map::createNdLinkObj(enum type_all_object type, int x, int y)
{
    IObject *obj =  _fac.getObject(type, x, y);
    _sceneList.push_back(obj);
    return (obj);
}

type_object_e Map::ChooseBonus()
{
    int bonus = std::rand() % 4;

    switch (bonus)
    {
    case 0:
        return (BOMBUP);
    case 1:
        return (FIREUP);
    case 2:
        return (SPEEDUP);
    case 3:
        return (WALLPASS);
    }
    return (NEIN);
}

bool    Map::CreateBonus()
{
    return (std::rand() % 2) == 0 ? false : true;
}

void    Map::createNdLinkBonuses()
{
    type_object_e bonusType;

    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 13; x ++) {
            if (_map[y][x] && _map[y][x]->get_type() == WALL_BREAK
            && CreateBonus() == true) {
                bonusType = ChooseBonus();
                createNdLinkObj(bonusType, x, y);
            }
        }
    }
}

void    Map::createFloor()
{
    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 13; x ++) {
            createNdLinkObj(FLOOR, x, y);
        }
    }
}

void    Map::InitMap()
{
    char **maze = Get_maze();

    CreateWall();
    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 13; x++) {
            if (!_map[y][x] &&
            (y != 1 && (x != 1 || x != 2 || x != 10 || x != 11)) &&
            (y != 2 && (x != 1 || x != 11)) &&
            (y != 10 && (x != 1 || x != 11)) &&
            (y != 11 && (x != 1 || x != 2 || x != 10 || x != 11)))
                _map[y][x] = (maze[y][x] == 'X') ? (createNdLinkObj(WALL_BREAK, x, y)) : (NULL);
        }
    }
    createFloor();
}

std::vector<IObject *> &Map::getSceneList()
{
    return (_sceneList);
}

void Map::CreateWall()
{
    std::vector<IObject *> temp;

    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 13; x++)
            temp.push_back(NULL);
        _map.push_back(temp);
        temp.clear();
    }
    for (int i = 0; i < 13; i++) {
        _map[0][i] = createNdLinkObj(WALL_UNBREAK, 0, i);
        _map[12][i] = createNdLinkObj(WALL_UNBREAK, 12, i);
        _map[i][0] = createNdLinkObj(WALL_UNBREAK, i, 0);
        _map[i][12] = createNdLinkObj(WALL_UNBREAK, i, 12);
    }
    for (int y = 2; y < 13; y+=2) {
        for (int x = 2; x < 13; x+=2)
            _map[y][x] = createNdLinkObj(WALL_UNBREAK, x, y);
    }
}

Map::~Map()
{
    _sceneList.clear();
    for (std::vector<IObject *> obj: _map)
        obj.clear();
    _map.clear();
}