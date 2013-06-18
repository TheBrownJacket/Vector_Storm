#pragma once

#include "ofMain.h"

#include "Ship.h"
#include "Star.h"
#include "Background.h"

#define NUM_OF_STARS 150

class testApp : public ofBaseApp
{
	public:
    //Logistics
        bool pause;
        ofImage pausescreen;
        bool nightsky;
        ofImage splash;

    //Enemies
        enum enemyID {
            BOX_ENEMY = 0,
        };

    //Ships
		Ship blueship;
		Ship redship;

    //Stars
        Star stars[NUM_OF_STARS];

    //Backgrounds
        Background lvlone;
    //Audio
		ofSoundPlayer ignition;

	//ofBaseApp funtions
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void exit();
};
