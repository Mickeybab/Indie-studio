/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** IPower
*/

#ifndef IPOWER_HPP_
#define IPOWER_HPP_

#include "AObject.hpp"

class IPower: public AObject {
	public:
		virtual ~IPower() = default;
		virtual type_object_e get_type() const = 0;
		virtual void setEnd(bool end) = 0;
		virtual bool getEnd() const = 0;

	protected:
		type_object_e _type;
		bool _end;
};

#endif /* !IPOWER_HPP_ */
