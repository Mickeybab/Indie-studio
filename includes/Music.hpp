/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Music
*/

#ifdef _WIN32

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <string>

namespace sf {
	class Music;
}

class sf::Music {
	public:
	enum Status {
		Stopped,
		Paused,
		Playing
	};
		Music();
		~Music();
		void play();
		void stop();
		void loop();
		void loop(bool loop);
		void setLoop(bool loop){};
		void setVolume(int v){};
		void setRelativeToListener(bool relative){};
		enum Status getStatus(){return Playing;};
		Music *openFromFile(std::string);
	protected:
	private:
};

#endif /* !MUSIC_HPP_ */

#endif