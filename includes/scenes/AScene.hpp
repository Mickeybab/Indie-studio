/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include "IScene.hpp"

class AScene: public IScene {
	public:
        AScene();
        virtual ~AScene() = default;
        std::vector<IObject *> get_obj() const override { return _obj;};
        void set_obj(std::vector<IObject *> obj) override { _obj = obj;};
        void set_map(std::vector<std::vector<IObject *>> map) override {_map = map;}
        std::vector<std::vector<IObject *>> get_map() const override {return _map;}
        bool getNew() const override {return _new;}
        void setNew(bool n) override {_new = n;}
        void addObject(IObject *obj) override;
        void setGameOver(bool end) override {_gameOver = end;}
        bool getGameOver() const override {return _gameOver;}

        virtual typeScene getTypeScene() const = 0;
    protected:
        std::vector<IObject *> _obj;
        typeScene _type;
        std::vector<std::vector<IObject *>> _map;
        bool _new;
        bool _gameOver;
};

#endif /* !ASCENE_HPP_ */
