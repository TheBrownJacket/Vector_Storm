#ifndef SHIP_H
#define SHIP_H

#include "ofMain.h"

#include "Bullet.h"

class Ship
{
    public:
        Ship();

        float xPos;
        float yPos;
        float accel;
        float maxSpeed;
        float xSpeed;
        float ySpeed;

        bool up;
        bool left;
        bool down;
        bool right;
        bool fire;

        ofImage sprite;

		ofSoundPlayer playerShoot;

        Bullet bullets[100];

        int bulletNum;
        int bulletFreq;

        void shoot();
		void accelerate();
		void move();
		void boundary();
		void draw();

        void print_info();

    protected:
    private:
};

#endif // SHIP_H
