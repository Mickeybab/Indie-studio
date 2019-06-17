/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Core
*/

#include "Core.hpp"
#include "FactoryObject.hpp"

Core::Core()
{
    for (int y = 0; y < 13; y++)
        _danger_grid.push_back(std::vector<char>(13));
    for (int y = 0; y < 13; y++)
        _blocks_grid.push_back(std::vector<char>(13));
}

Core::~Core()
{
}

void Core::setDanger_grid(std::vector<std::vector<IObject *>> map)
{
    int bomb_radius = 0;

    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 13; x++)
            _danger_grid[y][x] = 0;
    }
    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 13; x++) {
            if (map[y][x] && map[y][x]->get_type() == BOMB) {
                bomb_radius = static_cast<Bomb *>(map[y][x])->getRadius();
                for (int i = 0; i < bomb_radius && x + i < 13 && (!map[y][x + i] || (map[y][x + i]->get_type() != WALL_UNBREAK && map[y][x + i]->get_type() != WALL_BREAK)); i++)
                    _danger_grid[y][x + i] = 1;
                for (int i = 1; i < bomb_radius && y + i < 13 && (!map[y + i][x] || (map[y + i][x]->get_type() != WALL_UNBREAK && map[y + i][x]->get_type() != WALL_BREAK)); i++)
                    _danger_grid[y + i][x] = 1;
                for (int i = 1; i < bomb_radius && x - i >= 0 && (!map[y][x - i] || (map[y][x - i]->get_type() != WALL_UNBREAK && map[y][x - i]->get_type() != WALL_BREAK)); i++)
                    _danger_grid[y][x - i] = 1;
                for (int i = 1; i < bomb_radius && y - i >= 0 && (!map[y - i][x] || (map[y - i][x]->get_type() != WALL_UNBREAK && map[y - i][x]->get_type() != WALL_BREAK)); i++)
                    _danger_grid[y - i][x] = 1;
            }
        }
    }
}

std::vector<std::vector<char>> Core::getDanger_grid() const
{
    return (_danger_grid);
}

void Core::setBlocks_grid(std::vector<std::vector<IObject *>> map)
{
    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 13; x++) {
            if (map[y][x] && (map[y][x]->get_type() == WALL_UNBREAK))
                _blocks_grid[y][x] = 1;
            else if (map[y][x] && map[y][x]->get_type() == WALL_BREAK)
                _blocks_grid[y][x] = 2;
            else if (map[y][x] && (map[y][x]->get_type() == BASIC_PLAYER || map[y][x]->get_type() == IA))
                _blocks_grid[y][x] = 3;
            else
                _blocks_grid[y][x] = 0;
        }
    }
}

std::vector<std::vector<char>> Core::getBlocks_grid() const
{
    return (_blocks_grid);
}

int Core::getShortestPath(PlayerAI *ai, int y, int x, int length)
{
    std::vector<int> dir_x {-1, 0, 1, 0};
    std::vector<int> dir_y {0, -1, 0, 1};
    int shortest = 0;
    int tmp = 0;

    if (_blocks_grid[y][x] || _danger_grid[y][x] || _blocks_grid[y][x] == 1 || _blocks_grid[y][x] == 2)
        return (0);
    else if (_danger_grid[y][x] == 0)
        return (length);
    else {
        for (int i = 0; i < 4; i++) {
            tmp = getShortestPath(ai, y + dir_y[i], x + dir_x[i], length + 1);
            if (tmp != 0 && (tmp < shortest || shortest == 0))
                shortest = tmp;
        }
    }
    return (shortest);
}

void Core::set_new_goal_defense(PlayerAI *ai, IScene *scene)
{
    std::vector<int> dir_x {-1, 0, 1, 0};
    std::vector<int> dir_y {0, -1, 0, 1};
    int shortest = 0;
    int tmp = 0;

    for (int i = 0; i < 4; i++) {
        tmp = getShortestPath(ai, (ai->get_render()->getY() / 100) + dir_y[i], (ai->get_render()->getX() / 100) + dir_x[i], 1);
        if (tmp != 0 && (tmp < shortest || shortest == 0)) {
            ai->set_idx_dir(i);
            shortest = tmp;
        }
    }
    if (tmp == 0 && shortest == 0)
        set_new_goal_offense(ai, scene);
}

void Core::set_new_goal_offense(PlayerAI *ai, IScene *scene)
{
    int n = std::rand()%4;
    ai->set_idx_dir(-1);
    std::vector<int> dir_x{-1, 0, 1, 0};
    std::vector<int> dir_y{0, -1, 0, 1};

    if (_danger_grid[((ai->get_render()->getY() / 100) + dir_y[n])][((ai->get_render()->getX() / 100) + dir_x[n])] == 0
    && (_blocks_grid[((ai->get_render()->getY() / 100) + dir_y[n])][((ai->get_render()->getX() / 100) + dir_x[n])] == 0
    || _blocks_grid[((ai->get_render()->getY() / 100) + dir_y[n])][((ai->get_render()->getX() / 100) + dir_x[n])] == 3)) {
        ai->set_idx_dir(n);
    }
}

void Core::updateIA(IScene *scene)
{
    setBlocks_grid(scene->get_map());
    setDanger_grid(scene->get_map());
    std::vector<int> dir_x{-1, 0, 1, 0};
    std::vector<int> dir_y{0, -1, 0, 1};
    std::vector<int> dir {270, 180, 90, 0};
    FactoryObject fac;
    IObject *bomb;

    for (int i = 2; i <= 4; i++) {
        for (IObject *ob: scene->get_obj()) {
            if (ob && (ob->get_type() == IA && static_cast<PlayerAI *>(ob)->get_id() == i)) {
                if (!static_cast<PlayerAI *>(ob)->get_alive())
                    continue;
                if (_danger_grid[(ob->get_render()->getY() / 100)][(ob->get_render()->getX() / 100)] == 1)
                    set_new_goal_defense(static_cast<PlayerAI *>(ob), scene);
                else
                    set_new_goal_offense(static_cast<PlayerAI *>(ob), scene);
                if (!collision(static_cast<PlayerAI *>(ob), dir[static_cast<PlayerAI *>(ob)->get_idx_dir()], scene))
                    static_cast<PlayerAI *>(ob)->move(dir[static_cast<PlayerAI *>(ob)->get_idx_dir()]);
                for (int n = 0; n < 4; n++) {
                    if ((_blocks_grid[((static_cast<PlayerAI *>(ob)->get_render()->getY() / 100) + dir_y[n])][((static_cast<PlayerAI *>(ob)->get_render()->getX() / 100) + dir_x[n])] == 2
                    || _blocks_grid[((static_cast<PlayerAI *>(ob)->get_render()->getY() / 100) + dir_y[n])][((static_cast<PlayerAI *>(ob)->get_render()->getX() / 100) + dir_x[n])] == 3)
                    && (!static_cast<PlayerAI *>(ob)->get_bomb() || static_cast<PlayerAI *>(ob)->get_bomb()->getTime() > 2000)) {
                        bomb = fac.getObject(BOMB, static_cast<PlayerAI *>(ob)->get_render()->getX(), static_cast<PlayerAI *>(ob)->get_render()->getY());
                        scene->addObject(bomb);
                        static_cast<PlayerAI *>(ob)->set_bomb((Bomb *)bomb);
                        return;
                    }
                }
            }
        }
    }
}

bool Core::collision(PlayerAI *obj, int dir, IScene *_scene)
{
    type_object_e type;
    int x = obj->get_render()->getX() / 100;
    int y = obj->get_render()->getY() / 100;

    if (x + 1 > 12 || x - 1 < 0 || y + 1 > 12 || y - 1 < 0)
        return true;
    switch (dir) {
        case 0: if (_scene->get_map()[y+1][x] == NULL)
                return false;
            break;
        case 90: if (_scene->get_map()[y][x+1] == NULL)
                return false;
            break;
        case 180:
            if (_scene->get_map()[y-1][x] == NULL)
                return false;
            break;
        case 270:
            if (_scene->get_map()[y][x-1] == NULL)
                return false;
            break;
    }
    switch (dir) {
        case 0: type = _scene->get_map()[y+1][x]->get_type(); break;
        case 90: type = _scene->get_map()[y][x+1]->get_type(); break;
        case 180: type = _scene->get_map()[y-1][x]->get_type(); break;
        case 270: type = _scene->get_map()[y][x-1]->get_type(); break;
    }
    if (type == WALL_BREAK || type == WALL_UNBREAK)
        return true;
    return false;
}