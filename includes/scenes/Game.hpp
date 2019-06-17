/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "AScene.hpp"
#include "Player.hpp"
#include "PlayerAI.hpp"

class Game: public AScene {
    public:
        Game();
        ~Game();

        typeScene getTypeScene() const override { return _type; }
    protected:
        typeScene _type;
};

#endif /* !GAME_HPP_ */