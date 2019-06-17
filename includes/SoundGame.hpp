/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** SoundGame
*/

#ifndef SOUNDGAME_HPP_
#define SOUNDGAME_HPP_

#include "pathRessources.hpp"

#ifdef __linux__
    #include <SFML/Audio.hpp>
#elif _WIN32
	#include "Music.hpp"
#endif

#include <map>

class SoundGame {
	public:
		SoundGame();
        ~SoundGame();

        sf::Music *playBomPut() {return createMusic(BOMBPUT_SOUND);};
        sf::Music *playBombExplosion() { return createMusic(BOMBEXPLOSION_SOUND); };
        sf::Music *playGetPowerUp() {return createMusic(GETPOWERUP_SOUND);};
        sf::Music *playRun() {return createMusic(RUN_SOUND);};
        sf::Music *playDead() {return createMusic(DEAD_SOUND);};
        sf::Music *playWin() {return createMusic(WIN_SOUND);};
        sf::Music *playGameOver() {return createMusic(GAMEOVER_SOUND);};

    private:
        sf::Music *createMusic(std::string path);
};

#endif /* !SOUNDGAME_HPP_ */
