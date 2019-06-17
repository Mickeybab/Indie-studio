/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Ressource
*/

#ifndef RESSOURCE_HPP_
#define RESSOURCE_HPP_

#include <irrlicht/IAnimatedMesh.h>
#include <irrlicht/IAnimatedMeshSceneNode.h>
#include <irrlicht/ITexture.h>
#include <string>

class Ressource {
	public:
		Ressource(std::string path, irr::scene::IAnimatedMeshSceneNode *node, irr::video::ITexture *texture, irr::core::vector3df pos, irr::core::vector3df scale);
		~Ressource();

        void setPath(const std::string &path) { _path = path; }
        void setVisible() { _node->setVisible(true); }
        void setUnvisible() { _node->setVisible(false); }

        std::string getPath() const {return _path; }
        irr::scene::IAnimatedMeshSceneNode *getNode() const { return _node;}

        void setRun();
        void setStand();
        void setVisible(bool vis) { _node->setVisible(vis); };

    private:
        std::string _path;
        irr::scene::IAnimatedMeshSceneNode *_node;
};

#endif /* !RESSOURCE_HPP_ */
