/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** APower
*/

#ifndef APOWER_HPP_
#define APOWER_HPP_

#include "IPower.hpp"

class APower: public IPower {
	public:
		APower();
		virtual ~APower() = default;

        virtual type_object_e get_type() const = 0;
		void setEnd(bool end) override { _end = end;}
		bool getEnd() const override { return _end;}
	protected:
		type_object_e _type;
		bool _end;
};

#endif /* !APOWER_HPP_ */
