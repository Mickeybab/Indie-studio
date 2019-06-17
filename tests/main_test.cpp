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
	Indie *game = new Indie;
	Event *event = new Event(game);
	//Display display(event, game->get_scene());
	Core core;

	game->setStart(true);
	//event->setDevice(display.getDevice());
	//if (!display.getDevice())
	//	return 84;
	game->set_scene(new Game);
	//while (display.getDevice()->run()) {
	core.updateIA(game->get_scene());
	//	display.display_all(game->get_scene());
	//}
	return 0;
}