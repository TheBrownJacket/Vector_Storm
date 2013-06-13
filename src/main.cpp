#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
int main()
{
	ofAppGlutWindow window; //Create a window.
	ofSetupOpenGL(&window, 800, 600, OF_WINDOW); //Set width, height, mode (OF_WINDOW or OF_FULLSCREEN).
	ofRunApp(new testApp()); //Start the app.
}
