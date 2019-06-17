/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Moving
*/

#include "Moving.hpp"
#include "IPower.hpp"
#include "PlayerAI.hpp"

Moving::Moving(Indie *game, Display *display):
_game(game), _display(display)
{
}

Moving::~Moving()
{
}

void Moving::move_player()
{
    if (_game->get_scene()->getGameOver())
        return;
    for (IObject *ob: _game->get_scene()->get_obj()) {
        if (ob && (ob->get_type() == BASIC_PLAYER || ob->get_type() == IA)
        && ob->getMoving() == true) {
            choose_direction(static_cast<IPlayer *>(ob));
            collisionPower(static_cast<IPlayer *>(ob));
        }
        if (ob && ob->get_type() == BOMB)
            checkBomb((Bomb *)ob);
    }
    majBomb();
    checkEnd();
}
void Moving::choose_direction(IPlayer *obj)
{
    std::vector<std::vector<IObject *>> map = _game->get_scene()->get_map();

    stop_moving(obj);
    map[obj->get_render()->getY()/100][obj->get_render()->getX()/100] = NULL;
    switch ((int)obj->get_render()->getRotation()) {
        case 180:   obj->get_render()->setY(obj->get_render()->getY() - obj->get_speed()); break;
        case 90:  obj->get_render()->setX(obj->get_render()->getX() + obj->get_speed()); break;
        case 0: obj->get_render()->setY(obj->get_render()->getY() + obj->get_speed()); break;
        case 270: obj->get_render()->setX(obj->get_render()->getX() - obj->get_speed()); break;
    }
    map[obj->get_render()->getY()/100][obj->get_render()->getX()/100] = obj;
    _game->get_scene()->set_map(map);
}

void Moving::stop_moving(IPlayer *obj)
{
    if (((obj->get_render()->getRotation() == 0 || obj->get_render()->getRotation() == 180)
    && (obj->get_render()->getY() == (float)obj->getEnd() - 5)
    || obj->get_render()->getY() == (float)obj->getEnd() + 5)
    || ((obj->get_render()->getRotation() == 90 || obj->get_render()->getRotation() == 270)
    && (obj->get_render()->getX() == (float)obj->getEnd() - 5)
    || obj->get_render()->getX() == (float)obj->getEnd() + 5)) {
        obj->setMoving(false);
        obj->get_render()->getRessource()->setStand();
        obj->setEnd(-1);
        if (obj->get_type() == BASIC_PLAYER)
            obj->getMusic()->stop();
    }
}

void Moving::checkBomb(Bomb *obj)
{
    int x = obj->get_render()->getX() / 100;
    int y = obj->get_render()->getY() / 100;
    std::vector<IObject *> temp;
    std::vector<std::vector<IObject *>> map = _game->get_scene()->get_map();

    if (obj->getTime() == 0)
        obj->setMusic(_game->getSounds()->playBombExplosion());
    if (obj->getTime() == 180) {
        temp = checkCollisionBomb(x, y);
        for (IObject *ob: temp) {
            if (ob && ob->get_type() == WALL_BREAK) {
                map[ob->get_render()->getY()/100][ob->get_render()->getX()/100] = NULL;
                if (ob->get_render()->getRessource())
                    ob->get_render()->getRessource()->setUnvisible();
                for (IObject *obje: _game->get_scene()->get_obj()) {
                    if ((obje->get_type() == BOMBUP || obje->get_type() == FIREUP
                    || obje->get_type() == WALLPASS || obje->get_type() == SPEEDUP)
                    && obje->get_render()->getX() == ob->get_render()->getX()
                    && obje->get_render()->getY() == ob->get_render()->getY())
                        map[ob->get_render()->getY()/100][ob->get_render()->getX()/100] = obje;
                }
            }
            if (ob && ob->get_type() == IA) {
                ob->get_render()->getRessource()->setUnvisible();
                static_cast<PlayerAI *>(ob)->set_alive(false);
            } else if (ob && ob->get_type() == BASIC_PLAYER) {
                _display->displayGameOver();
                ob->get_render()->getRessource()->setUnvisible();
                _game->getSounds()->playDead();
                _game->getSounds()->playGameOver();
                _game->get_scene()->setGameOver(true);
            }
        }
        map[y][x] = NULL;
        _game->get_scene()->set_map(map);
        if (obj && obj->get_render() && obj->get_render()->getRessource())
            obj->get_render()->getRessource()->setUnvisible();
    }
    if (obj->getMusic()->getStatus() == sf::Music::Stopped)
        obj->getMusic()->stop();
    obj->addTime(1);
}

std::vector<IObject *> Moving::checkCollisionBomb(int x, int y)
{
    std::vector<IObject *> temp;

    if (y + 1 < 12 && _game->get_scene()->get_map()[y+1][x] )
        temp.push_back(_game->get_scene()->get_map()[y+1][x]);
    else if (y + 2 < 12 && _game->get_scene()->get_map()[y+2][x])
        temp.push_back(_game->get_scene()->get_map()[y+2][x]);
    else if (y + 3 < 12 && _game->get_scene()->get_map()[y+3][x])
        temp.push_back(_game->get_scene()->get_map()[y+3][x]);
    if (y - 1 > 0 && _game->get_scene()->get_map()[y-1][x])
        temp.push_back(_game->get_scene()->get_map()[y-1][x]);
    else if (y - 2 > 0 && _game->get_scene()->get_map()[y-2][x])
        temp.push_back(_game->get_scene()->get_map()[y-2][x]);
    else if (y - 3 > 0 && _game->get_scene()->get_map()[y-3][x])
        temp.push_back(_game->get_scene()->get_map()[y-3][x]);
    if (x + 1 < 12 && _game->get_scene()->get_map()[y][x+1])
        temp.push_back(_game->get_scene()->get_map()[y][x+1]);
    else if (x + 2 < 12 && _game->get_scene()->get_map()[y][x+2])
        temp.push_back(_game->get_scene()->get_map()[y][x+2]);
    else if (x + 3 < 12 && _game->get_scene()->get_map()[y][x+3])
        temp.push_back(_game->get_scene()->get_map()[y][x+3]);
    if (x - 1 > 0 && _game->get_scene()->get_map()[y][x-1])
        temp.push_back(_game->get_scene()->get_map()[y][x-1]);
    else if (x - 2 > 0 && _game->get_scene()->get_map()[y][x-2])
        temp.push_back(_game->get_scene()->get_map()[y][x-2]);
    else if (x - 3 > 0 && _game->get_scene()->get_map()[y][x-3])
        temp.push_back(_game->get_scene()->get_map()[y][x-3]);
    for (IObject *obj: _game->get_scene()->get_obj()) {
        if ((obj->get_type() == BASIC_PLAYER || obj->get_type() == IA)
        && obj->get_render()->getX()/100 == x && obj->get_render()->getY()/100 == y)
            temp.push_back(obj);
    }
    return temp;
}

void Moving::collisionPower(IPlayer *obj)
{
    for (IObject *ob: _game->get_scene()->get_obj()) {
        if (ob->get_type() == BOMBUP && !static_cast<IPower *>(ob)->getEnd() && ob->get_render()->getX() == obj->get_render()->getX() && ob->get_render()->getY() == obj->get_render()->getY()) {
            obj->set_bombpass(true);
            ob->get_render()->getRessource()->setUnvisible();
            obj->setMusic(_game->getSounds()->playGetPowerUp());
            static_cast<IPower *>(ob)->setEnd(true);
        } else if (ob->get_type() == WALLPASS && !static_cast<IPower *>(ob)->getEnd() && ob->get_render()->getX() == obj->get_render()->getX() && ob->get_render()->getY() == obj->get_render()->getY()) {
            obj->set_wallpass(true);
            ob->get_render()->getRessource()->setUnvisible();
            obj->setMusic(_game->getSounds()->playGetPowerUp());
            static_cast<IPower *>(ob)->setEnd(true);
        } else if (ob->get_type() == FIREUP && !static_cast<IPower *>(ob)->getEnd() && ob->get_render()->getX() == obj->get_render()->getX() && ob->get_render()->getY() == obj->get_render()->getY()) {
            obj->set_fireup(true);
            ob->get_render()->getRessource()->setUnvisible();
            obj->setMusic(_game->getSounds()->playGetPowerUp());
            static_cast<IPower *>(ob)->setEnd(true);
        } else if (ob->get_type() == SPEEDUP && !static_cast<IPower *>(ob)->getEnd() && ob->get_render()->getX() == obj->get_render()->getX() && ob->get_render()->getY() == obj->get_render()->getY()) {
            obj->set_speedup(true);
            ob->get_render()->getRessource()->setUnvisible();
            obj->setMusic(_game->getSounds()->playGetPowerUp());
            static_cast<IPower *>(ob)->setEnd(true);
        }
    }
}

void Moving::majBomb()
{
    std::vector<std::vector<IObject *>> map = _game->get_scene()->get_map();

    for (IObject *obj: _game->get_scene()->get_obj()) {
        if (obj->get_type() == BOMB && static_cast<Bomb *>(obj)->getTime() < 180)
            map[obj->get_render()->getY()/100][obj->get_render()->getX()/100] = obj;
    }
    _game->get_scene()->set_map(map);
}

void Moving::checkEnd()
{
    int check = 0;

    for (IObject *obj: _game->get_scene()->get_obj()) {
        if (obj && obj->get_type() == IA && static_cast<PlayerAI *>(obj)->get_alive())
            check++;
    }
    if (check == 0) {
        _game->get_scene()->setGameOver(true);
        _display->displayWin();
        _game->getSounds()->playWin();
    }
}
