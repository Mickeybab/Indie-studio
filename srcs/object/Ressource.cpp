/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Ressource
*/

#include "Ressource.hpp"
#include <irrlicht/irrlicht.h>

Ressource::Ressource(std::string path, irr::scene::IAnimatedMeshSceneNode *node, irr::video::ITexture *texture, irr::core::vector3df pos, irr::core::vector3df scale) : 
_path(path),
_node(node)
{
    if (node && texture) {
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMaterialTexture(0, texture);
        _node->setPosition(pos);
        _node->setScale({scale.X/100, scale.Y/100, scale.Z/100});
    }
}

Ressource::~Ressource()
{
    this->setUnvisible();
}

void Ressource::setRun()
{
    _node->setMD2Animation(irr::scene::EMAT_RUN);
}

void Ressource::setStand()
{
    _node->setMD2Animation(irr::scene::EMAT_STAND);
}