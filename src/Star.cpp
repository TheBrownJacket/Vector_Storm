#include "Star.h"

#define MAX_STAR_SPEED 10
#define MIN_STAR_SPEED 1
#define MAX_STAR_BRIGHTNESS 30

Star::Star()
{
    xPos=ofRandom(ofGetWindowWidth());
    yPos=ofGetWindowHeight()-2*ofRandom(ofGetWindowHeight());
    speed=ofRandom(MAX_STAR_SPEED-MIN_STAR_SPEED)+MIN_STAR_SPEED;
    alpha=MAX_STAR_BRIGHTNESS*(speed/MAX_STAR_SPEED);
}

void Star::move()
{
    yPos+=speed;
}

void Star::reset()
{
    if (yPos>ofGetWindowHeight()+sprite.getHeight()/2)
    {
        xPos = ofRandom(ofGetWindowWidth());
        speed=ofRandom(MAX_STAR_SPEED-MIN_STAR_SPEED)+MIN_STAR_SPEED;
        alpha=MAX_STAR_BRIGHTNESS*(speed/MAX_STAR_SPEED);
        yPos=-ofGetWindowHeight()*(alpha/MAX_STAR_BRIGHTNESS)-ofRandom(ofGetWindowHeight());
        //yPos=-ofGetWindowHeight()*pow(speed,2)-ofRandom(ofGetWindowHeight()*speed);
    }
}

void Star::draw()
{
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,alpha);
    sprite.draw(xPos,yPos);
    ofSetColor(255,255,255,255);
    ofDisableAlphaBlending();
}
