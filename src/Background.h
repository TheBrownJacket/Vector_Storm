#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "ofMain.h"

class Background
{
    public:
        Background();

        float xPos;
        float yPos;
        float panSpeed;

        ofImage sprite;

        void pan();
        void draw();

    protected:
    private:
};

#endif // BACKGROUND_H
