/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Power
*/

#ifndef POWER_HPP_
#define POWER_HPP_

#include "APower.hpp"

class Bombup: public APower {
	public:
		Bombup(int x, int y);
		~Bombup() override;
		type_object_e get_type() const override { return _type; };
    protected:
		type_object_e _type;
};

#endif /* !POWER_HPP_ */
