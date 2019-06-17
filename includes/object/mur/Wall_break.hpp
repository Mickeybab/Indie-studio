/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Mur_drestructible
*/

#ifndef MUR_DRESTRUCTIBLE_HPP_
#define MUR_DRESTRUCTIBLE_HPP_

#include "IWall.hpp"

class Wall_break: public IWall {
	public:
		Wall_break(int, int);
		~Wall_break();
		type_object_e get_type() const { return _type; };

	protected:
		type_object_e _type;
};

#endif /* !Mur_destructible_hpp */
