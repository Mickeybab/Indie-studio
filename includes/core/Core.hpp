/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "IScene.hpp"
#include "IObject.hpp"
#include "Bomb.hpp"
#include "PlayerAI.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <random>

class Core {
	public:
		Core();
		~Core();
		void updateIA(IScene *scene);

        void setDanger_grid(std::vector<std::vector<IObject *>> map);
        std::vector<std::vector<char>> getDanger_grid() const;

        void setBlocks_grid(std::vector<std::vector<IObject *>> map);
        std::vector<std::vector<char>> getBlocks_grid() const;

        void set_new_goal_offense(PlayerAI *ai, IScene *scene);
        void set_new_goal_defense(PlayerAI *ai, IScene *scene);
        int getShortestPath(PlayerAI *ai, int y, int x, int length);

    private:
        std::vector<std::vector<char>> _danger_grid;
        std::vector<std::vector<char>> _blocks_grid;
        bool collision(PlayerAI *obj, int dir, IScene *_scene);
};

#endif /* !CORE_HPP_ */
