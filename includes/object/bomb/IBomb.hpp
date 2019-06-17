/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** IBomb
*/

#ifndef IBOMB_HPP_
#define IBOMB_HPP_

#include "AObject.hpp"

class IBomb: public AObject {
	public:
		virtual ~IBomb() = default;
		virtual type_object_e get_type() const = 0;
		virtual int getRadius() const = 0;
		virtual int getTime() const = 0;
		virtual void addTime(int time) = 0;

	protected:
		type_object_e _type;
		int _radius;
		int _time;
};

#endif /* !IBOMB_HPP_ */
