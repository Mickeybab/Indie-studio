/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "IBomb.hpp"

class Bomb: public IBomb {
	public:
		Bomb(int x, int y);
		~Bomb();
		type_object_e get_type() const override { return _type; };
		int getRadius() const override { return _radius; };
		int getTime() const override { return _time; }
		void addTime(int time) override { _time += time;}

	protected:
		type_object_e _type;
		int _radius;
		int _time;
};

#endif /* !BOMB_HPP_ */