/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Render
*/

#include "Render.hpp"

Render::Render()
{
}

Render::~Render()
{
    if (_ressource)
        delete(_ressource);
}
