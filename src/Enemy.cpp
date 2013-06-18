#include "Enemy.h"

Enemy::Enemy()
{

}

void Enemy::shoot()
{

}

void Enemy::move()
{
    if(enemyID==SWEEPER)
    {
        if (xPos>ofGetWindowWidth()-sprite.getWidth() || xPos<sprite.getWidth())
        {
            xSpeed = -xSpeed;
            if(xPos>ofGetWindowWidth()-sprite.getWidth())
            {
                xPos = ofGetWindowWidth()-sprite.getWidth()-1;
            }
            else if(xPos<sprite.getWidth())
            {
                xPos = sprite.getWidth()+1;
            }
        }
        xPos += xSpeed;
    }
}

void Enemy::draw()
{
    ofEnableAlphaBlending();
    sprite.draw(xPos,yPos);
    ofDisableAlphaBlending();
}
