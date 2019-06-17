/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** AObject
*/

#ifndef AOBJECT_HPP_
#define AOBJECT_HPP_

#include "IObject.hpp"

class AObject: public IObject {
	public:
		AObject(): _render(new Render()), _moving(false) {};
		virtual ~AObject() = default;

        bool getMoving() const override { return _moving; };
        void setMoving(bool moving) override { _moving = moving; };
        Render *get_render() const override { return _render; };
        void setMusic(sf::Music *music) override { _music = music; };
        sf::Music *getMusic() const override { return _music; };

    protected:
		Render *_render;
        bool _moving;
        sf::Music *_music;
};

#endif /* !AOBJECT_HPP_ */
