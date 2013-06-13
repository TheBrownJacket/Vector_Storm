#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
}

void Enemy::move()
{

}

void Enemy::draw()
{
    ofEnableAlphaBlending();
    sprite.draw(xPos,yPos);
    ofDisableAlphaBlending();
}
