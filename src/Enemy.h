#ifndef ENEMY_H
#define ENEMY_H

#include "ofMain.h"

#include "Bullet.h"

class Enemy
{
    public:
        Enemy();

        unsigned int enemy_id;

        float xPos;
        float yPos;
        float xSpeed;
        float ySpeed;

        bool assault;

        ofImage sprite;

        Bullet bullets[100];

        int bulletNum;
        int bulletFreq;

		void move();
		void draw();

    protected:
    private:
};

#endif // ENEMY_H
