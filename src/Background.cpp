#include "Background.h"

Background::Background()
{
    panSpeed = .5;
}

void Background::pan()
{
    yPos+=panSpeed;
    if (yPos>=sprite.getHeight())
    {
        panSpeed = 0;
    }
}

void Background::draw()
{
    ofSetColor(255,255,255,127);
    sprite.draw(xPos,yPos);
    ofSetColor(255,255,255,255);
}
