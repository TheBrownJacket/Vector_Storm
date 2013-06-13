#ifndef BULLET_H
#define BULLET_H

#include "ofMain.h"

class Bullet
{
    public:
        Bullet();

        float xPos;
        float yPos;
        float speed;

        int frameNum;

        bool isFired;

        ofImage sprite;

        void move();
        void reset();
        void draw();

    protected:
    private:
};

#endif // BULLET_H
