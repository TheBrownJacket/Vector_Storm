#include "Bullet.h"

Bullet::Bullet()
{
    isFired=false;
}

void Bullet::move()
{
    if(isFired)
    {
        yPos-=speed;
    }
}

void Bullet::reset()
{
    if(yPos<-sprite.getHeight()/2)
    {
        isFired=false;
    }
}

void Bullet::draw()
{
    if(isFired)
    {
        ofEnableAlphaBlending();
        sprite.draw(xPos,yPos);
        ofDisableAlphaBlending();
    }
}
