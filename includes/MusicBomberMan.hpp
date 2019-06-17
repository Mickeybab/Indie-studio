/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** MusicBomberMan
*/

#ifndef MUSICBOMBERMAN_HPP_
#define MUSICBOMBERMAN_HPP_

#ifdef __linux__
    #include <SFML/Audio.hpp>
#elif _WIN32
	#include "Music.hpp"
#endif

#define MUSIC_MENU "../ressources/music/menu.ogg"
#define MUSIC_GAME "../ressources/music/game.ogg"
#define MUSIC_PAUSE "../ressources/music/pause.ogg"

class MusicBomberMan {
	public:
		MusicBomberMan();
        ~MusicBomberMan();

        void playMusicMenu();
        void playMusicGame();
        void playMusicPause();
        void mute();
        void unMute();
        void smoothVolumeUp();
        void smoothVolumeDown();
        void offMusic();

        sf::Music *getMenuMusic() const { return _menu; }
        sf::Music *getGameMusic() const { return _game; }
        sf::Music *getPauseMusic() const { return _pause; }

    private:
        sf::Music *_menu;
        sf::Music *_game;
        sf::Music *_pause;
};

#endif /* !MUSICBOMBERMAN_HPP_ */
