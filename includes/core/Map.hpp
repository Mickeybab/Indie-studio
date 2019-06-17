/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "Generator.hpp"
#include "FactoryObject.hpp"
#include "IObject.hpp"
#include <vector>
#include <ctime>

class Map {
    public:
        Map();
        char                    **Get_maze();
        void                    InitMap();
        std::vector<std::vector<IObject *>>    GetMap();
        ~Map();
        std::vector<IObject *>  &getSceneList();
        void                    createFloor();
    private:
        IObject                 *createNdLinkObj(type_object_e type, int x, int y);
        void                    createNdLinkBonuses();
        void                    CreateWall();
        type_object_e           ChooseBonus();
        bool                    CreateBonus();

        std::vector<IObject *>                  _sceneList;
        FactoryObject                           _fac;
        std::vector<std::vector<IObject *>>     _map;
};

#endif /* !MAP_HPP_ */