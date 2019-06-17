/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Event
*/

#include "Event.hpp"
#include "IPlayer.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "Game_multi.hpp"
#include "FactoryObject.hpp"

Event::Event(Indie *game):
_game(game),
_device(NULL)
{
}

Event::~Event()
{
}

bool Event::OnEvent(const irr::SEvent& event)
{
    if (!_game->getStart())
        return true;
    if (event.EventType == irr::EET_GUI_EVENT) {
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
            irr::s32 id = event.GUIEvent.Caller->getID();
            if (id == 101)
                changeToGame();
            if (id == 102)
                changeToMultiplayer();
            if (id == 103)
                _device->closeDevice();
            if (id == 104)
                changeToMenu();
        }
    }
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        return MovePlayer(event);
    return false;
}

bool Event::MovePlayer(const irr::SEvent& event)
{
    if (event.KeyInput.PressedDown && !_game->get_scene()->getGameOver()) {
        switch (event.KeyInput.Key) {
            case irr::KEY_UP: findAndMovePlayer(0, 1); break;
            case irr::KEY_DOWN: findAndMovePlayer(180, 1); break;
            case irr::KEY_LEFT: findAndMovePlayer(270, 1); break;
            case irr::KEY_RIGHT: findAndMovePlayer(90, 1); break;
            case irr::KEY_KEY_Z: findAndMovePlayer(0, 2); break;
            case irr::KEY_KEY_S: findAndMovePlayer(180, 2); break;
            case irr::KEY_KEY_Q: findAndMovePlayer(270, 2); break;
            case irr::KEY_KEY_D: findAndMovePlayer(90, 2); break;
            case irr::KEY_KEY_M: poseBomb(1); break;
            case irr::KEY_KEY_A: poseBomb(2); break;
        }
    }
    return true;
}

void Event::poseBomb(int id)
{
    FactoryObject fac;
    Bomb *bomb;

    for (IObject *obj: _game->get_scene()->get_obj()) {
        if (obj && obj->get_type() == BASIC_PLAYER
        && static_cast<IPlayer *>(obj)->get_id() == id
        &&(!static_cast<Player *>(obj)->get_bomb()
        || static_cast<Player *>(obj)->get_bomb()->getTime() > BOMB_TIME)) {
            bomb = (Bomb *)fac.getObject(BOMB, arroundPos(obj->get_render()->getX()), arroundPos(obj->get_render()->getY()));
            _game->get_scene()->addObject((IObject *)bomb);
            static_cast<Player *>(obj)->set_bomb(bomb);
        }
    }
}

void Event::findAndMovePlayer(int dir, int id)
{
    for (IObject *obj: _game->get_scene()->get_obj()) {
        if (obj && obj->get_type() == BASIC_PLAYER
        && static_cast<IPlayer *>(obj)->get_id() == id
        && obj->getMoving() == false
        && !collision(static_cast<Player *>(obj), dir)) {
            static_cast<IPlayer *>(obj)->move(dir);
            obj->setMusic(_game->getSounds()->playRun());
        }
    }
}

bool Event::collision(Player *obj, int dir)
{
    type_object_e type;
    int x = obj->get_render()->getX() / 100;
    int y = obj->get_render()->getY() / 100;

    switch (dir) {
        case 0: if (_game->get_scene()->get_map()[y+1][x] == NULL)
                return false;
            break;
        case 90: if (_game->get_scene()->get_map()[y][x+1] == NULL)
                return false;
            break;
        case 180:
            if (_game->get_scene()->get_map()[y-1][x] == NULL)
                return false;
            break;
        case 270:
            if (_game->get_scene()->get_map()[y][x-1] == NULL)
                return false;
            break;
    }
    switch (dir) {
        case 0: type = _game->get_scene()->get_map()[y+1][x]->get_type(); break;
        case 90: type = _game->get_scene()->get_map()[y][x+1]->get_type(); break;
        case 180: type = _game->get_scene()->get_map()[y-1][x]->get_type(); break;
        case 270: type = _game->get_scene()->get_map()[y][x-1]->get_type(); break;
    }
    if (type == WALL_BREAK || type == WALL_UNBREAK)
        return true;
    return false;
}

void Event::changeToGame()
{
    delete(_game->get_scene());
    _game->set_scene(new Game);
}

void Event::changeToMenu()
{
    delete(_game->get_scene());
    _game->set_scene(new Menu);
}

void Event::changeToMultiplayer()
{
    delete(_game->get_scene());
    _game->set_scene(new Game_multi);
}

int Event::arroundPos(int pos)
{
    return ((int)(pos/100))*100;
}