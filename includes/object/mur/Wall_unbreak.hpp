/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Mur_indestructible
*/

#ifndef MUR_INDESTRUCTIBLE_HPP_
#define MUR_INDESTRUCTIBLE_HPP_

#include "IWall.hpp"

class Wall_unbreak: public IWall {
	public:
		Wall_unbreak(int, int);
		~Wall_unbreak();
		type_object_e get_type() const { return _type; };

    protected:
		type_object_e _type;
};

#endif /* !MUR_INDESTRUCTIBLE_HPP_ */