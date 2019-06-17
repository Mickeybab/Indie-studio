/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Gui
*/

#include "Gui.hpp"
#include "pathRessources.hpp"

Gui::Gui(irr::IrrlichtDevice *device, const std::string &fontPath):
_env(device->getGUIEnvironment()),
_font(_env->getFont(irr::io::path(fontPath.c_str())))
{
    _vecButton.push_back(_env->addButton(irr::core::rect<irr::s32>(1920 / 2 - 500 / 2, 350, 1920 / 2 + 500 / 2, 450), 0, 101, L"Play"));
    _vecButton.push_back(_env->addButton(irr::core::rect<irr::s32>(1920 / 2 - 500 / 2, 550, 1920 / 2 + 500 / 2, 650), 0, 102, L"Multiplayer"));
    _vecButton.push_back(_env->addButton(irr::core::rect<irr::s32>(1920 / 2 - 500 / 2, 750, 1920 / 2 + 500 / 2, 850), 0, 103, L"Quit"));
    _vecButton.push_back(_env->addButton(irr::core::rect<irr::s32>(0, 0, 200, 50), 0, 103, L"Quit game"));
    _vecButton.push_back(_env->addButton(irr::core::rect<irr::s32>(1720, 0, 1920, 50), 0, 104, L"Menu"));
    if (_font) {
        for (irr::gui::IGUIButton *button : _vecButton) {
            button->setOverrideFont(_font);
            button->setDrawBorder(true);
        }
    }
}

Gui::~Gui()
{
}