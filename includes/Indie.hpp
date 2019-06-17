/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Indie
*/

#ifndef INDIE_HPP_
#define INDIE_HPP_

#include "IScene.hpp"
#include "MusicBomberMan.hpp"
#include "SoundGame.hpp"

class Indie {
	public:
		Indie();
		~Indie();

		void set_scene(IScene *scene) { _scene = scene; };
		void setStart(bool start) { _start = start; };

		IScene *get_scene() const { return _scene; };
		bool getStart() const { return _start; };
		MusicBomberMan *getMusicBomberMan() const { return _music; }
		SoundGame *getSounds() const { return _sound; }

	private:
		IScene *_scene;
		bool _start;
		MusicBomberMan *_music;
		SoundGame *_sound;
};

#endif /* !INDIE_HPP_ */
