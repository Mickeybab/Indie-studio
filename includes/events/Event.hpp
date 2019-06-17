/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "Indie.hpp"
#include "IEventReceiver.h"
#include "Player.hpp"
#include <irrlicht.h>

class Event: public irr::IEventReceiver {
	public:
		Event(Indie *game);
		~Event();
		bool OnEvent(const irr::SEvent& event);
		bool MovePlayer(const irr::SEvent& event);

		void findAndMovePlayer(int dir, int id);
		void setDevice(irr::IrrlichtDevice *device) { _device = device; };
		void changeToGame();
		void changeToMenu();
		void changeToMultiplayer();
		void poseBomb(int id);

	private:
		Indie *_game;
		irr::IrrlichtDevice *_device;
		bool collision(Player *obj, int dir);
		int arroundPos(int pos);
};

#endif /* !EVENT_HPP_ */