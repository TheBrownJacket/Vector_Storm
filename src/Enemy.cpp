#include "Enemy.h"

Enemy::Enemy(int id)
{
    enemyID=id;
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
