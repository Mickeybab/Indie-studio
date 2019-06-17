/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** IMur
*/

#ifndef IMUR_HPP_
#define IMUR_HPP_

#include "AObject.hpp"

class IWall: public AObject {
	public:
		virtual ~IWall() = default;
		virtual type_object_e get_type() const = 0;

	protected:
		type_object_e _type;
};

#endif /* !IMUR_HPP_ */