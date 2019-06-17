/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Gui
*/

#ifndef GUI_HPP_
#define GUI_HPP_

#include <irrlicht/IrrlichtDevice.h>
#include <irrlicht/IGUIEnvironment.h>
#include <irrlicht/IGUIFont.h>
#include <irrlicht/IGUIButton.h>
#include <irrlicht/IGUISpriteBank.h>
#include <vector>
#include <string>

class Gui {
    public:
        Gui(irr::IrrlichtDevice *device, const std::string &fontPath);
        ~Gui();

        // void setSkin(irr::gui::IGUISkin *skin) {_skin = skin;}
        void setFont(irr::gui::IGUIFont *font) {_font = font;}


        irr::gui::IGUIEnvironment *getEnv() const {return _env;}
        // irr::gui::IGUISkin *getSkin() const {return _skin;}
        irr::gui::IGUIFont *getFont() const {return _font;}
        std::vector<irr::gui::IGUIButton *> getButtons() const { return _vecButton; }

    private:
        irr::gui::IGUIEnvironment *_env;
        // irr::gui::IGUISkin *_skin;
        irr::gui::IGUIFont *_font;
		std::vector<irr::gui::IGUIButton *> _vecButton;
};

#endif /* !GUI_HPP_ */
