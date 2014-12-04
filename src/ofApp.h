#pragma once

#include "ofMain.h"

// number of frames to wait before fading out image
#define WAIT_TIME 120

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void windowResized(int w, int h);

    private:
        ofImage img;
    
        int drawAlpha;
        bool doFadeOut;
        int fadeRate;
        int frameCount;
    
        string photoPath;
        void setNextPhotoPath();
    
};
