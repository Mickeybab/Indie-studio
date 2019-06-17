/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** IPlayer
*/

#ifndef IPLAYER_HPP_
    #define IPLAYER_HPP_

    #include "AObject.hpp"
    #include "Bomb.hpp"
    #include "Render.hpp"

    #define BOMB_TIME 300

    class IPlayer: public AObject {
        public:
            virtual ~IPlayer() = default;

            virtual void move(int dir) = 0;
            virtual void stopMove() = 0;

            virtual void drop_bomb(int x, int y) = 0;
            virtual void set_bomb(Bomb *bomb) = 0;
            virtual Bomb *get_bomb() const = 0;

            virtual int get_id() const = 0;

            virtual void set_score(int score) = 0;
            virtual int get_score() const = 0;

            virtual bool get_alive() const = 0;

            virtual void set_fire_radius(int radius) = 0;
            virtual int get_fire_radius() const = 0;

            virtual void set_bombs_number(int bombs) = 0;
            virtual int get_bombs_number() const = 0;

            virtual void set_speed(float speed) = 0;
            virtual float get_speed() const = 0;

            virtual void set_wallpass(bool wallpass) = 0;
            virtual bool get_wallpass() const = 0;

            virtual void set_bombpass(bool bombpass) = 0;
            virtual bool get_bombpass() const = 0;

            virtual void set_fireup(bool fireup) = 0;
            virtual bool get_fireup() const = 0;

            virtual void set_speedup(bool speed) = 0;
            virtual bool get_speedup() const = 0;

            virtual void set_flamepass(bool flamepass) = 0;
            virtual bool get_flamepass() const = 0;

            virtual void set_detonator(bool detonator) = 0;
            virtual bool get_detonator() const = 0;

            virtual void set_invincible(bool wallpass) = 0;
            virtual bool get_invincible() const = 0;

            virtual int getEnd() const = 0;
            virtual void brakeMove() = 0;
            virtual void setEnd(int end) = 0;

        protected:
            type_object_e _type;
            int _id;
            int _score;
            bool _alive;
            Bomb *_bomb;
            int _fire_radius;
            int _bombs_nb;
            float _speed;
            bool _wallpass;
            bool _bombpass;
            bool _fireup;
            bool _speedup;
            bool _flamepass;
            bool _detonator;
            bool _invincible;
            int _end;
    };

#endif /* !IPLAYER_HPP_ */
