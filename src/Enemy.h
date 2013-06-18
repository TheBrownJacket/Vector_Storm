#ifndef ENEMY_H
#define ENEMY_H

#include "ofMain.h"

#include "Bullet.h"

class Enemy
{
    public:
        Enemy();

        unsigned int enemyID;

        enum ID{
            SWEEPER=0,
            BOMBER,
            FIGHTER,
            STRIKER,
            DOUBLE,
            DUALWING,
            DRONE,
            HUB,
            DUALBEAM,
            CRESCENT,
            FOURWAY,
        };

        float xPos;
        float yPos;
        float xSpeed;
        float ySpeed;

        bool assault;

        ofImage sprite;

        Bullet bullets[100];

        int bulletNum;
        int bulletFreq;

        void shoot();
		void move();
		void draw();

    protected:
    private:
};

#endif // ENEMY_H
