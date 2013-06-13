#include "Ship.h"

Ship::Ship()
{
    bulletNum=0;
}

void Ship::shoot()
{
    if(fire)
    {
        bullets[bulletNum].frameNum=ofGetFrameNum();
        int x = bulletNum==0 ? sizeof(bullets)/sizeof(bullets[0])-1 : bulletNum-1; //Assign x
        if(bullets[bulletNum].frameNum>=bullets[x].frameNum+bulletFreq)
        {
            playerShoot.play();
            bullets[bulletNum].isFired=true;
            bullets[bulletNum].xPos=xPos;
            bullets[bulletNum].yPos=yPos-(sprite.getHeight()/2);
            bulletNum++;
        }
        if(bulletNum>=sizeof(bullets)/sizeof(bullets[0]))
        {
            bulletNum=0;
        }
    }
    //Bullet maintenance
    for(int i=0;i<sizeof(bullets)/sizeof(bullets[0]);i++)
    {
        bullets[i].move();
        bullets[i].reset();
    }
}

void Ship::accelerate()
{
    if(up)
    {
        if(ySpeed<maxSpeed) ySpeed+=accel;
    }
    else
    {
        if(ySpeed>0) ySpeed-=accel;
    }
    if(left)
    {
        if(xSpeed>-maxSpeed) xSpeed-=accel;
    }
    else
    {
        if(xSpeed<0) xSpeed+=accel;
    }
    if(down)
    {
        if(ySpeed>-maxSpeed) ySpeed-=accel;
    }
    else
    {
        if(ySpeed<0) ySpeed+=accel;
    }
    if(right)
    {
        if(xSpeed<maxSpeed) xSpeed+=accel;
    }
    else
    {
        if(xSpeed>0) xSpeed-=accel;
    }
}

void Ship::move()
{
    accelerate();
    xPos+=xSpeed;
    yPos-=ySpeed;
}

void Ship::boundary()
{
    if(xPos<=sprite.getWidth()/2)
    {
        xSpeed=0;
        xPos=sprite.getWidth()/2+1;
    }
    if(xPos>=ofGetWindowWidth()-sprite.getWidth()/2)
    {
        xSpeed=0;
        xPos=ofGetWindowWidth()-sprite.getWidth()/2-1;
    }
    if(yPos<=sprite.getHeight()/2)
    {
        ySpeed=0;
        yPos=sprite.getHeight()/2+1;
    }
    if(yPos>=ofGetWindowHeight()-sprite.getHeight()/2)
    {
        ySpeed=0;
        yPos=ofGetWindowHeight()-sprite.getHeight()/2-1;
    }
}

void Ship::draw()
{
    ofEnableAlphaBlending();
    sprite.draw(xPos,yPos);
    ofDisableAlphaBlending();
}

void Ship::print_info()
{
    if(ofGetFrameNum()%(int)ofGetFrameRate()==0)
    {
        cout << this << endl;
        cout << "xPos: ";
        cout << xPos << endl;
        cout << "yPos: ";
        cout << yPos << endl;
        cout << "xSpeed: ";
        cout << xSpeed << endl;
        cout << "ySpeed: ";
        cout << ySpeed << endl;
        cout << "\n";
    }
}
