/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Moving
*/

#ifndef MOVING_HPP_
#define MOVING_HPP_

#include "Player.hpp"
#include "Indie.hpp"
#include "Display.hpp"
#include <vector>

class Moving {
	public:
		Moving(Indie *game, Display *display);
		~Moving();
        void move_player();
    private:
        void choose_direction(IPlayer *obj);
        void stop_moving(IPlayer *obj);
        void checkBomb(Bomb *obj);
        std::vector<IObject *> checkCollisionBomb(int x, int y);
        void collisionPower(IPlayer *obj);
        void majBomb();
        void checkEnd();
        Indie *_game;
        Display *_display;
};

#endif /* !MOVING_HPP_ */
