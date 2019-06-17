/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** IScenes
*/

#ifndef ISCENES_HPP_
#define ISCENES_HPP_

#include "IObject.hpp"
#include <vector>

enum typeScene {
    MENU,
    GAME
};

class IScene {
    public:
        virtual ~IScene() = default;
        virtual std::vector<IObject *> get_obj() const = 0;
        virtual void set_obj(std::vector<IObject *> obj) = 0;
        virtual void set_map(std::vector<std::vector<IObject *>> map) = 0;
        virtual std::vector<std::vector<IObject *>> get_map() const = 0;
        virtual bool getNew() const = 0;
        virtual void setNew(bool n) = 0;
        virtual void addObject(IObject *obj) = 0;
        virtual void setGameOver(bool end) = 0;
        virtual bool getGameOver() const = 0;

        virtual typeScene getTypeScene() const = 0;
    protected:
        std::vector<IObject *> _obj;
        typeScene _type;
        std::vector<std::vector<IObject *>> _map;
        bool _new;
        bool _gameOver;
};

#endif /* !ISCENES_HPP_ */