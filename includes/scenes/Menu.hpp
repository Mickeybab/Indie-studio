/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "AScene.hpp"

class Menu : public AScene {
    public:
        Menu();
        ~Menu();

        typeScene getTypeScene() const override { return _type; }
    protected:
        typeScene _type;
};

#endif /* !MENU_HPP_ */