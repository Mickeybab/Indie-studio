/*
** EPITECH PROJECT, 2019
** Tech2
** File description:
** Speedup
*/

#ifndef SPEEDUP_HPP_
#define SPEEDUP_HPP_

#include "APower.hpp"

class Speedup: public APower {
	public:
		Speedup(int x, int y);
		~Speedup() override;
		type_object_e get_type() const override { return _type; };
	protected:
		type_object_e _type;
};

#endif /* !SPEEDUP_HPP_ */