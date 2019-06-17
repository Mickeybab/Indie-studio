/*
** EPITECH PROJECT, 2019
** Tech2
** File description:
** Fireup
*/

#ifndef FIREUP_HPP_
#define FIREUP_HPP_

#include "APower.hpp"

class Fireup: public APower {
	public:
		Fireup(int x, int y);
		~Fireup() override;
		type_object_e get_type() const override { return _type; };
	protected:
		type_object_e _type;
};

#endif /* !FIREUP_HPP_ */
