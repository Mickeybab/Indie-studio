/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** IRender
*/

#ifndef IRENDER_HPP_
#define IRENDER_HPP_

#include "Ressource.hpp"
#include <string>

class Render {
	public:
		Render();
		~Render();
		void setX(int x) {_x = x;}
		void setY(int y) {_y = y;}
		void setZ(int z) {_z = z;}
		void setSizeX(float size_x) {_size_x = size_x;}
		void setSizeY(float size_y) {_size_y = size_y;}
		void setSizeZ(float size_z) {_size_z = size_z;}
		void setPath(std::string path) {_path_ressource = path;}
		void setTexture(std::string texture) {_path_texture = texture;}
		void setRotation(int rotation) {_rotation = rotation;}
		void setRessource(Ressource *res) {_ressource = res;}
		int getX() const {return (_x);}
		int getY() const {return (_y);}
		int getZ() const {return (_z);}
		float getSizeX() const {return (_size_x);}
		float getSizeY() const {return (_size_y);}
		float getSizeZ() const {return (_size_z);}
		std::string getPath() const {return (_path_ressource);}
		std::string getTexture() const {return (_path_texture);}
		int getRotation() const {return _rotation;}
		Ressource *getRessource() const {return _ressource;}

	private:
		int _x;
		int _y;
		int _z;
		float _size_x;
		float _size_y;
		float _size_z;
		int _rotation;
		std::string _path_ressource;
		std::string _path_texture;
		Ressource *_ressource;
};

#endif /* !IRENDER_HPP_ */
