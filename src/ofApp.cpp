#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    // init
    doFadeOut = false;
    drawAlpha = 0;
    fadeRate = 5;
    frameCount = 0;

    // load first random image:
    photoPath = "*";
    setNextPhotoPath();
    img.loadImage(photoPath);
    img.update();
    
    
    // go fullscreen, aw yeah
    ofToggleFullscreen();
}


void ofApp::setNextPhotoPath(){
    
    ofDirectory dir;
    int total = dir.listDir( ofFilePath::getUserHomeDir() + "/Desktop/photos" );
    
    string newPath = dir.getPath((int)ofRandom( total ));
    
    // run 'while' loop in case the path isn't different than the current one
    while( ofIsStringInString(newPath, photoPath) ){
        newPath = dir.getPath((int)ofRandom( total ));
    }
    
    photoPath = newPath;
//    cout << photoPath << " : " << total << endl;
}


//--------------------------------------------------------------
void ofApp::update(){
    
    if( doFadeOut && drawAlpha > 0 ){
        
        // fade out image
        drawAlpha -= fadeRate;
        
        // if fade is complete, load next image
        if( drawAlpha <= 0 ) {
            doFadeOut = false;
            drawAlpha = 0;
            
            // load new Image;
            setNextPhotoPath();
            img.loadImage(photoPath);
            img.update();
        }
    } else if( !fadeOut && drawAlpha < 255 ){
        
        // fade IN image
        drawAlpha += fadeRate;
        
        if( drawAlpha >= 255 ){
            drawAlpha = 255;
        }
        
    } else if( !doFadeOut && drawAlpha == 255 ){
        
        // frame counter to pause on current image
        frameCount++;
        
        // start fade OUT if it's time
        if( frameCount == WAIT_TIME ) {
            doFadeOut = true;
            frameCount = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draws the image centered on the screen. Add fancy resizing/responsive code here! ;)
    ofSetColor( 255,255,255,drawAlpha );
    img.draw( ofGetWidth()/2 - img.getWidth()/2, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch( key ){
        case 'f': ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

 
