/*
** EPITECH PROJECT, 2019
** Tech2
** File description:
** Wallpass
*/

#ifndef WALLPASS_HPP_
#define WALLPASS_HPP_

#include "APower.hpp"

class Wallpass: public APower {
	public:
		Wallpass(int x, int y);
		~Wallpass() override;
		type_object_e get_type() const { return _type; };
	protected:
		type_object_e _type;
};

#endif /* !WALLPASS_HPP_ */