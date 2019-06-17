/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Display
*/

#include "Display.hpp"
#include "pathRessources.hpp"
#include <fstream>

Display::Display(Event *recevier, IScene *scene) //: _recevier(recevier)
{
    _device = irr::createDevice(irr::video::EDT_OPENGL,
                                irr::core::dimension2d<irr::u32>(1920, 1080),
                                32, true, true, false, recevier);
    if (!_device)
        return;
    createRessourcesByDevice();
    createCamera();
    _gui = new Gui(_device, FONT);
    createButton();
    createTextEnd();
    _rgb.push_back(0);
    _rgb.push_back(0);
    _rgb.push_back(0);
    _menuBackground = _driver->getTexture(MENU_BACKGROUND);
    _gameBackground = _driver->getTexture(GAME_BACKGROUND);
}

Display::~Display()
{
    if (_device)
	    _driver->drop();
}

void Display::display_all(IScene *scene, MusicBomberMan *music)
{
    if (_device->isWindowActive()) {
        if (scene->getTypeScene() == MENU)
            displayMenu(music);
        else
            displayGame(scene, music);
    }
}

void Display::displayMenu(MusicBomberMan *music)
{
    transitionGameToMenu(music);
    _driver->beginScene(true, true, irr::video::SColor(0, _rgb[0], _rgb[1], _rgb[2]));
    _driver->draw2DImage(_menuBackground, irr::core::position2d<irr::s32>(0, 0));

    if (_rgb[0] == 255 && _rgb[1] == 255 && _rgb[2] == 255)
        _gui->getEnv()->drawAll();
    else {
        _rgb[0] += 1;
        _rgb[1] += 1;
        _rgb[2] += 1;
        _driver->makeColorKeyTexture(_menuBackground, irr::video::SColor(0, _rgb[0], _rgb[1], _rgb[2]));
    }
    _driver->endScene();
}

void Display::displayGame(IScene *scene, MusicBomberMan *music)
{
    if (scene->getNew()) {
        initRessources(scene);
        transitionMenuToGame(music);
    }
    for (IObject *obj: scene->get_obj()) {
        if (obj->get_type() == BOMB && !obj->get_render()->getRessource())
            obj->get_render()->setRessource(createRessource(obj));
    }
    scene->setNew(false);
    updatePosGame(scene);
    _driver->beginScene(true, true, irr::video::SColor(0,_rgb[0], _rgb[1], _rgb[2]));
    _driver->draw2DImage(_gameBackground, irr::core::position2d<irr::s32>(0, 0));
    if (_rgb[0] == 255 && _rgb[1] == 255 && _rgb[2] == 255) {
        _sceneManager->drawAll();
        _gui->getEnv()->drawAll();
    }
    _driver->endScene();
}

void Display::createButton()
{
    _gui->getButtons()[3]->setVisible(false);
    _gui->getButtons()[4]->setVisible(false);
}

void Display::transitionMenuToGame(MusicBomberMan *music)
{
    if (music->getGameMusic()->getStatus() == sf::Music::Playing)
        music->getGameMusic()->stop();
    if (music->getMenuMusic()->getStatus() == sf::Music::Stopped)
        music->getMenuMusic()->play();
    if (_gui->getButtons()[0]->isVisible()) {
        _gui->getButtons()[0]->setVisible(false);
        _gui->getButtons()[1]->setVisible(false);
        _gui->getButtons()[2]->setVisible(false);
        _gui->getButtons()[3]->setVisible(true);
        _gui->getButtons()[4]->setVisible(true);
    }
}

void Display::transitionGameToMenu(MusicBomberMan *music)
{
    if (music->getMenuMusic()->getStatus() == sf::Music::Playing)
        music->getMenuMusic()->stop();
    if (music->getGameMusic()->getStatus() == sf::Music::Stopped)
        music->getGameMusic()->play();
    if (_gui->getButtons()[3]->isVisible()) {
        _gui->getButtons()[0]->setVisible(true);
        _gui->getButtons()[1]->setVisible(true);
        _gui->getButtons()[2]->setVisible(true);
        _gui->getButtons()[3]->setVisible(false);
        _gui->getButtons()[4]->setVisible(false);
        hideGameOver();
        hideWin();
    }
}

void Display::createCamera()
{
    _camera = _sceneManager->addCameraSceneNode(0, irr::core::vector3df(180, 300, 50), irr::core::vector3df(180, 0.0f, 180));
}

void Display::initRessources(IScene *scene)
{
    _vecRessources.clear();
    for (IObject *obj : scene->get_obj()) {
        if (!obj)
            continue;
        obj->get_render()->setRessource(createRessource(obj));
    }
}

Ressource *Display::createRessource(IObject *obj)
{
    std::ifstream file(obj->get_render()->getPath());
    irr::scene::IAnimatedMeshSceneNode *node;
    irr::video::ITexture *texture;
    if (file.good()) {
        node = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh(obj->get_render()->getPath().c_str()));
        texture = _driver->getTexture(obj->get_render()->getTexture().c_str());
    } else {
        node = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh(std::string("../" + obj->get_render()->getPath()).c_str()));
        texture = _driver->getTexture(std::string("../" + obj->get_render()->getPath()).c_str());
    }
    file.close();
    irr::core::vector3df pos = intToVector3df(obj->get_render()->getX()/100*30, obj->get_render()->getZ(), obj->get_render()->getY()/100*30);
    irr::core::vector3df scale = intToVector3df(obj->get_render()->getSizeX(), obj->get_render()->getSizeY(), obj->get_render()->getSizeZ());
    std::string path = obj->get_render()->getPath();

    Ressource *new_res = new Ressource(path, node, texture, pos, scale);
    new_res->getNode()->setMD2Animation(irr::scene::EMAT_STAND);
    _vecRessources.push_back(new_res);
    return new_res;
}

void Display::createRessourcesByDevice()
{
    _driver = _device->getVideoDriver();
    _sceneManager = _device->getSceneManager();
}

void Display::updatePosGame(IScene *scene)
{
    irr::core::vector3df pos;
    irr::core::vector3df rot;

    for (IObject *obj: scene->get_obj()) {
        if (obj && obj->getMoving() == true && obj->get_render()->getRessource()) {
            pos = {(float)obj->get_render()->getX()/100*30, (float)obj->get_render()->getZ(), (float)obj->get_render()->getY()/100*30};
            rot = {0, (float)obj->get_render()->getRotation() - 90, 0};
            obj->get_render()->getRessource()->getNode()->setPosition(pos);
            obj->get_render()->getRessource()->getNode()->setRotation(rot);
        }
    }
}

void Display::createTextEnd()
{
    _win = _gui->getEnv()->addStaticText(L"Win", irr::core::rect<irr::s32>(1920 / 2 - 66 / 2, 1080 / 2 - 30, 1920 / 2 + 60 / 2, 1080 / 2), true, true, 0, -1, true);
    _gameOver = _gui->getEnv()->addStaticText(L"Game over", irr::core::rect<irr::s32>(1920 / 2 - 85 / 2, 1080 / 2 - 50, 1920 / 2 + 87 / 2, 1080 / 2 + 15), true, true, 0, -1, true);
    _win->setOverrideFont(_gui->getFont());
    _gameOver->setOverrideFont(_gui->getFont());
    _win->setVisible(false);
    _gameOver->setVisible(false);
    _win->setBackgroundColor(irr::video::SColor(255, 255, 255, 255));
    _gameOver->setBackgroundColor(irr::video::SColor(255, 255, 255, 255));
}