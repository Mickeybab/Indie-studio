/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** FactoryObject
*/

#ifndef FACTORYOBJECT_HPP_
#define FACTORYOBJECT_HPP_

#include "Wall_unbreak.hpp"
#include "Wall_break.hpp"
#include "Player.hpp"
#include "PlayerAI.hpp"
#include "Bombup.hpp"
#include "Fireup.hpp"
#include "Speedup.hpp"
#include "Wallpass.hpp"
#include "Floor.hpp"
#include "IObject.hpp"

class FactoryObject {
	public:
		FactoryObject();
		~FactoryObject();

        IObject *getObject(enum type_all_object type, int x, int y);
    private:
        unsigned int _player_id;
};

#endif /* !FACTORYOBJECT_HPP_ */
