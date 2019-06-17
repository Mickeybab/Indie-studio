/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** ISol
*/

#ifndef ISOL_HPP_
#define ISOL_HPP_

#include "AObject.hpp"

class IFloor: public AObject {
	public:
		virtual ~IFloor() = default;
		virtual type_object_e get_type() const = 0;

    protected:
		type_object_e _type;
};

#endif /* !ISOL_HPP_ */
