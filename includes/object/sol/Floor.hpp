/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Sol
*/

#ifndef SOL_HPP_
#define SOL_HPP_

#include "IFloor.hpp"

class Floor: public IFloor {
	public:
		Floor(int x, int y);
		~Floor();
		type_object_e get_type() const { return _type; };

    protected:
		type_object_e _type;
};

#endif /* !SOL_HPP_ */
