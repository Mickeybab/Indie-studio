/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** PlayerAI
*/

#ifndef PLAYERAI_HPP_
    #define PLAYERAI_HPP_

    #include "APlayer.hpp"

    class PlayerAI: public APlayer {
	    public:
		    PlayerAI(int id, float x, float y);
		    ~PlayerAI() override;

            void move(int dir) override;
            void stopMove() override;

            type_object_e get_type() const override { return _type; };
            int get_id() const override { return _id; };

            void set_idx_dir(int idx) { _idx_dir = idx; }
            int get_idx_dir() const { return (_idx_dir); }

            void set_alive(bool alive) { _alive = alive; }
            bool get_alive() { return (_alive); }
        protected:
		    type_object_e _type;
            int _id;
            int _idx_dir;
            bool _alive;
};

#endif /* !PLAYERAI_HPP_ */
