/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** APlayer
*/

#ifndef APLAYER_HPP_
#define APLAYER_HPP_

#include "IPlayer.hpp"

class APlayer: public IPlayer {
	public:
        APlayer();
        virtual ~APlayer() = default;

        virtual void move(int dir) = 0;
        virtual void stopMove() = 0;

        void drop_bomb(int x, int y) override;
        void set_bomb(Bomb *bomb) override;
        Bomb *get_bomb() const override;

        virtual int get_id() const = 0;

        void set_score(int score) override;
        int get_score() const override;

        bool get_alive() const override;

        void set_fire_radius(int radius) override;
        int get_fire_radius() const override;

        void set_bombs_number(int bombs) override;
        int get_bombs_number() const override;

        void set_speed(float speed) override;
        float get_speed() const override;

        void set_wallpass(bool wallpass) override;
        bool get_wallpass() const override;

        void set_bombpass(bool bombpass) override;
        bool get_bombpass() const override;

        void set_fireup(bool fireup) override;
        bool get_fireup() const override;

        void set_speedup(bool speed) override;
        bool get_speedup() const override;

        void set_flamepass(bool flamepass) override;
        bool get_flamepass() const override;

        void set_detonator(bool detonator) override;
        bool get_detonator() const override;

        void set_invincible(bool invincible) override;
        bool get_invincible() const override;

        virtual type_object_e get_type() const = 0;

        int getEnd() const override { return _end; }
        void brakeMove() override;
        void setEnd(int end) override { _end = end;}

    protected:
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

#endif /* !APLAYER_HPP_ */
