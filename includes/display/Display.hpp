/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "IScene.hpp"
#include "Event.hpp"
#include "Gui.hpp"
#include "Bomb.hpp"
#include "MusicBomberMan.hpp"
#include <irrlicht/irrlicht.h>
#include <irrlicht/driverChoice.h>
#include <vector>

class Display {
	public:
		Display(Event *recevier, IScene *scene);
		~Display();
		void display_all(IScene *scene, MusicBomberMan *music);

		void setReceiver(Event *event);
		void updatePosGame(IScene *scene);
		irr::core::vector3df intToVector3df(int x, int y, int z) const { return irr::core::vector3df(x, y, z); }
		void displayWin() { _win->setVisible(true); }
		void hideWin() { _win->setVisible(false); }
		void displayGameOver() { _gameOver->setVisible(true); }
		void hideGameOver() { _gameOver->setVisible(false); }

		irr::IrrlichtDevice *getDevice() const { return _device; }
		irr::scene::ISceneManager *getSceneManager() const { return _sceneManager; }
		irr::video::IVideoDriver *getDriver() const { return _driver; }
		Gui *getGui() const { return _gui; }
		std::vector<irr::f32> getRGB() { return _rgb; }

	private:
		irr::IrrlichtDevice *_device;
		irr::scene::ISceneManager *_sceneManager;
		irr::video::IVideoDriver *_driver;
		irr::scene::ICameraSceneNode *_camera;
		std::vector<Ressource *> _vecRessources;
		std::vector<irr::f32> _rgb;
		irr::gui::IGUIStaticText *_win;
		irr::gui::IGUIStaticText *_gameOver;
		irr::video::ITexture *_menuBackground;
		irr::video::ITexture *_gameBackground;
		Gui *_gui;

	protected:
		void createRessourcesByDevice();
		void createButton();
		void transitionMenuToGame(MusicBomberMan *music);
		void transitionGameToMenu(MusicBomberMan *music);
		void displayMenu(MusicBomberMan *music);
		void displayGame(IScene *scene, MusicBomberMan *music);
		void createCamera();
		void createTextEnd();
		void initRessources(IScene *scene);
		Ressource *createRessource(IObject *obj);
};

#endif /* !DISPLAY_HPP_ */