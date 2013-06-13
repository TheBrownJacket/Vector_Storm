#ifndef STAR_H
#define STAR_H

#include "ofMain.h"

class Star
{
    public:
        Star();

        float speed;
        float xPos;
        float yPos;
        float alpha;

        ofImage sprite;

        void move();
        void reset();
		void draw();

    protected:
    private:
};

#endif // STAR_H
