/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** main
*/

#include "main.hpp"

int main(void)
{
	return start_game();
}

int start_game(void)
{
	Indie *game = new Indie();
	Event *event = new Event(game);
	Display display(event, game->get_scene());
	Core core;
	Moving moving(game, &display);

	if (!display.getDevice())
		return 84;
	event->setDevice(display.getDevice());
	game->setStart(true);
	game->set_scene(new Menu);
	game->getMusicBomberMan()->playMusicMenu();
	while (display.getDevice()->run()) {
		if (game->get_scene()->getTypeScene() == GAME) {
			moving.move_player();
			core.updateIA(game->get_scene());
		}
		display.display_all(game->get_scene(), game->getMusicBomberMan());
	}
	game->getMusicBomberMan()->offMusic();
	return 0;
}