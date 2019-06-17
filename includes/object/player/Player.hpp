/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "APlayer.hpp"

    class Player: public APlayer {
	    public:
		    Player(int id, float x, float y);
		    ~Player() override;

            void move(int dir) override;
            void stopMove() override;

            type_object_e get_type() const override { return _type; };
            int get_id() const override { return _id; };

        protected:
		    type_object_e _type;
            int _id;
};

#endif /* !PLAYER_HPP_ */