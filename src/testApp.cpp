#include "testApp.h"
#include <unistd.h> // for Sleep()
//Frame rate
#define FRAMESRATE 60 //Do not tamper!!!
//Ships
#define BLUE_SHIP_ACCEL .5
#define BLUE_SHIP_MAXSPEED 5
#define BLUE_SHIP_BPS 5
#define BLUE_SHIP_BULLET_SPEED 15
#define RED_SHIP_ACCEL .25
#define RED_SHIP_MAXSPEED 10
#define RED_SHIP_BPS 5
#define RED_SHIP_BULLET_SPEED 30
//ENEMIES
#define SWEEPER_MAXPAN 5
#define SWEEPER_MINPAN 1

//--------------------------------------------------------------
void testApp::setup()
{
//Splash screen test
    splash.loadImage("images/logo_transparent.png");
    splash.resize(100,100*((float)splash.getHeight()/splash.getWidth()));

//Basic setup
    ofSetWindowTitle("Vector Storm Beta");
	ofHideCursor();
	ofBackground(0,0,0);
    ofSetFrameRate(FRAMESRATE);

//Logistics
    pause=false;
    pausescreen.loadImage("images/pause.png");
    pausescreen.setAnchorPoint(pausescreen.getWidth()/2,pausescreen.getHeight()/2);
    nightsky=false;

//Ships + Bullets
    //Blueship
    blueship.sprite.loadImage("images/player_1.png");
    blueship.sprite.setAnchorPoint(blueship.sprite.getWidth()/2,blueship.sprite.getHeight()/2);

    blueship.playerShoot.loadSound("audio/PlayerShoot.wav");
    blueship.playerShoot.setVolume(0.2);

    blueship.xPos=ofGetWindowWidth()/3;
    blueship.yPos=ofGetWindowHeight()/5*4;

    blueship.accel=BLUE_SHIP_ACCEL;
    blueship.maxSpeed=BLUE_SHIP_MAXSPEED;

    blueship.bulletFreq=(int)ofGetFrameRate()/BLUE_SHIP_BPS;
    for(int i=0;i<sizeof(blueship.bullets)/sizeof(blueship.bullets[0]);i++)
    {
        blueship.bullets[i].sprite.loadImage("images/player_1_bullet.png");
        blueship.bullets[i].sprite.setAnchorPoint(blueship.bullets[i].sprite.getWidth()/2,blueship.bullets[i].sprite.getHeight()/2);
        blueship.bullets[i].speed=BLUE_SHIP_BULLET_SPEED;
    }

    //Redship
    redship.sprite.loadImage("images/player_2.png");
    redship.sprite.setAnchorPoint(redship.sprite.getWidth()/2,redship.sprite.getHeight()/2);

    redship.playerShoot.loadSound("audio/PlayerShoot.wav");
    redship.playerShoot.setVolume(0.2);

    redship.xPos=ofGetWindowWidth()/3*2;
    redship.yPos=ofGetWindowHeight()/5*4;

    redship.accel=RED_SHIP_ACCEL;
    redship.maxSpeed=RED_SHIP_MAXSPEED;

    redship.bulletFreq=ofGetFrameRate()/RED_SHIP_BPS;
    for(int i=0;i<sizeof(redship.bullets)/sizeof(redship.bullets[0]);i++)
    {
        redship.bullets[i].sprite.loadImage("images/player_2_bullet.png");
        redship.bullets[i].sprite.setAnchorPoint(redship.bullets[i].sprite.getWidth()/2,redship.bullets[i].sprite.getHeight()/2);
        redship.bullets[i].speed=RED_SHIP_BULLET_SPEED;
    }

//Stars
    for(int i=0;i<sizeof(stars)/sizeof(stars[0]);i++)
    {
        stars[i].sprite.loadImage("images/star.png");
        stars[i].sprite.setAnchorPoint(stars[i].sprite.getWidth()/2,stars[i].sprite.getHeight()/2);
    }

//Backgrounds
    lvlone.sprite.loadImage("images/lvl_1_bg.png");
    lvlone.sprite.setAnchorPoint(lvlone.sprite.getWidth()/2,lvlone.sprite.getHeight());
    lvlone.xPos=ofGetWindowWidth()/2;
    lvlone.yPos=ofGetWindowHeight();

//Enemies
    for (int i=0;i<sizeof(sweepers)/sizeof(sweepers[0]);i++)
    {
        sweepers[i].enemyID=0;
        sweepers[i].sprite.loadImage("images/enemies/Sweeper.png");
        sweepers[i].sprite.setAnchorPoint(sweepers[i].sprite.getWidth()/2,sweepers[i].sprite.getHeight()/2);
        sweepers[i].xPos=ofRandom(sweepers[i].sprite.getWidth(),ofGetWindowWidth()-sweepers[i].sprite.getWidth());
        sweepers[i].yPos=ofRandom(sweepers[i].sprite.getHeight(),ofGetWindowHeight()/2);
        sweepers[i].xSpeed=ofRandomf()*SWEEPER_MAXPAN;
    }

//Audio (problem with loading ignition.mp3)
//    ignition.loadSound("audio/ignition.mp3");
//    ignition.setVolume(0.05);
//    ignition.setLoop(true);
//    ignition.play();
}
//--------------------------------------------------------------
void testApp::update()
{
    if(!pause)
    {
    //Stars
        for(int i=0;i<sizeof(stars)/sizeof(stars[0]);i++)
        {
            stars[i].move();
            if(!nightsky)
            {
                stars[i].reset();
            }
        }

    //Ships + Bullets
        //Blueship
        blueship.move();
        blueship.boundary();
        blueship.shoot();
        //Redship
        redship.move();
        redship.boundary();
        redship.shoot();
    //Enemies
    for (int i=0;i<sizeof(sweepers)/sizeof(sweepers[0]);i++)
    {
        sweepers[i].move();
    }

    //Backgrounds
        lvlone.pan();

    //Data
        redship.print_info();
        blueship.print_info();
    }
}
//--------------------------------------------------------------
void testApp::draw()
{
//Backgrounds
    lvlone.draw();

//Stars
    for(int i=0;i<sizeof(stars)/sizeof(stars[0]);i++)
    {
        stars[i].draw();
    }

//Ships + Bullets
    blueship.draw();
    for(int i=0;i<sizeof(blueship.bullets)/sizeof(blueship.bullets[0]);i++)
    {
        blueship.bullets[i].draw();
    }

    redship.draw();
    for(int i=0;i<sizeof(redship.bullets)/sizeof(redship.bullets[0]);i++)
    {
        redship.bullets[i].draw();
    }

	ofEnableAlphaBlending();
    splash.draw(ofGetWindowWidth()-splash.getWidth(),ofGetWindowHeight()-splash.getHeight());
    ofDrawBitmapString("BETA",ofGetWindowWidth()-40,ofGetWindowHeight()-10);
    ofDisableAlphaBlending();

//Enemies
    for (int i=0;i<sizeof(sweepers)/sizeof(sweepers[0]);i++)
    {
        sweepers[i].draw();
    }

//Pause screen
    if(pause)
    {
        pausescreen.draw(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    }
}
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    switch(key)
    {
    //Blueship controls
        case 'w':
            blueship.up = true;
            break;
        case 'a':
            blueship.left = true;
            break;
        case 's':
            blueship.down = true;
            break;
        case 'd':
            blueship.right = true;
            break;
        case 'f':
            blueship.fire = true;
            break;
    //Redship controls
        case OF_KEY_UP:
            redship.up = true;
            break;
        case OF_KEY_LEFT:
            redship.left = true;
            break;
        case OF_KEY_DOWN:
            redship.down = true;
            break;
        case OF_KEY_RIGHT:
            redship.right = true;
            break;
        case '/':
            redship.fire = true;
            break;
    }
}
//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
    switch(key)
    {
    //Blueship controls
        case 'w':
            blueship.up = false;
            break;
        case 'a':
            blueship.left = false;
            break;
        case 's':
            blueship.down = false;
            break;
        case 'd':
            blueship.right = false;
            break;
        case 'f':
            blueship.fire = false;
            break;
    //Redship controls
        case OF_KEY_UP:
            redship.up = false;
            break;
        case OF_KEY_LEFT:
            redship.left = false;
            break;
        case OF_KEY_DOWN:
            redship.down = false;
            break;
        case OF_KEY_RIGHT:
            redship.right = false;
            break;
        case '/':
            redship.fire = false;
            break;
    //Logistic controls
        case 'p':
            pause=!pause;
            break;
        case '0':
            if(!pause)
            {
                nightsky=!nightsky;
            }
            break;
//        case '2':
//            if(pause)
//            {
//                ofToggleFullscreen();
//            }
//            break;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

void testApp::exit()
{
    cout << "Vector Storm Beta terminated!\n";
}
