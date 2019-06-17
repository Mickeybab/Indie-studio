/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Game_multi
*/

#ifndef GAME_MULTI_HPP_
#define GAME_MULTI_HPP_

#include "AScene.hpp"
#include "Player.hpp"
#include "PlayerAI.hpp"

class Game_multi: public AScene {
	public:
		Game_multi();
		~Game_multi();

        typeScene getTypeScene() const override { return _type; }
    protected:
        typeScene _type;
};

#endif /* !GAME_MULTI_HPP_ */
