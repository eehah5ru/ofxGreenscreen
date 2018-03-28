#pragma once

#include "ofMain.h"
#include "ofxGreenscreen.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofxGreenscreen greenscreen;
	ofVideoGrabber grabber;

	ofImage mask;
	ofImage baseMask;
	ofImage detailMask;
	ofImage chromaMask;

	ofImage redSub;
	ofImage greenSub;
	ofImage blueSub;

	ofPoint dragStart;
	ofPoint greenPixelPos;
    
    ofxPanel gui_main;
//    float bgColor[4];
   
     ofParameter<bool> saveImgs;
    
    ofParameter<bool> bShowGui;
    ofParameter<int> fps;
};
