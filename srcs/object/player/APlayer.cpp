/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** APlayer
*/

#include "APlayer.hpp"

APlayer::APlayer():
_score(0),
_alive(true), _bomb(NULL),
_fire_radius(1), _bombs_nb(1), _speed(5),
_wallpass(false), _bombpass(false), _fireup(false),
_speedup(false), _flamepass(false),
_detonator(false), _invincible(false),
_end(-1)
{
}

void APlayer::brakeMove()
{
    _end = -1;
    _moving = false;
    _render->getRessource()->setStand();
}

void APlayer::drop_bomb(int x, int y)
{
}

void APlayer::set_bomb(Bomb *bomb)
{
    _bomb = bomb;
}

Bomb *APlayer::get_bomb() const
{
    return (_bomb);
}

void APlayer::set_score(int score)
{
    _score = score;
}

int APlayer::get_score() const
{
    return (_score);
}

bool APlayer::get_alive() const
{
    return (_alive);
}

void APlayer::set_fire_radius(int radius)
{
    _fire_radius = radius;
}

int APlayer::get_fire_radius() const
{
    return (_fire_radius);
}

void APlayer::set_bombs_number(int bombs)
{
    _bombs_nb = bombs;
}

int APlayer::get_bombs_number() const
{
    return (_bombs_nb);
}

void APlayer::set_speed(float speed)
{
    _speed = speed;
}

float APlayer::get_speed() const
{
    return (_speed);
}

void APlayer::set_wallpass(bool wallpass)
{
    _wallpass = wallpass;
}

bool APlayer::get_wallpass() const
{
    return (_wallpass);
}

void APlayer::set_bombpass(bool bombpass)
{
    _bombpass = bombpass;
}

bool APlayer::get_bombpass() const
{
    return (_bombpass);
}

void APlayer::set_fireup(bool fireup)
{
    _fireup = fireup;
}

bool APlayer::get_fireup() const
{
    return _fireup;
}

void APlayer::set_speedup(bool speedup)
{
    _speedup = speedup;
}

bool APlayer::get_speedup() const
{
    return _speedup;
}

void APlayer::set_flamepass(bool flamepass)
{
    _flamepass = flamepass;
}

bool APlayer::get_flamepass() const
{
    return (_flamepass);
}

void APlayer::set_detonator(bool detonator)
{
    _detonator = detonator;
}

bool APlayer::get_detonator() const
{
    return (_detonator);
}

void APlayer::set_invincible(bool invincible)
{
    _invincible = invincible;
}

bool APlayer::get_invincible() const
{
    return (_invincible);
}
