/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** IObject
*/

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_

#include "Render.hpp"

#ifdef __linux__
    #include <SFML/Audio.hpp>
#elif _WIN32
	#include "Music.hpp"
#endif

typedef enum type_all_object {
    NEIN = - 1,
    WALL_BREAK = 0,
    WALL_UNBREAK = 1,
    FLOOR = 2,
    BASIC_PLAYER = 3,
    IA = 4,
    BOMBUP = 5,
    FIREUP = 6,
    SPEEDUP = 7,
    WALLPASS = 8,
	BOMB = 9,
}	type_object_e;

class IObject {
	public:
		virtual ~IObject() = default;
		virtual Render *get_render() const = 0;
        virtual type_object_e get_type() const = 0;
        virtual bool getMoving() const = 0;
        virtual void setMoving(bool moving) = 0;
        virtual void setMusic(sf::Music *music) = 0;
        virtual sf::Music *getMusic() const = 0;

	protected:
		Render *_render;
        type_object_e _type;
        bool _moving;
};

#endif /* !IOBJECT_HPP_ */
