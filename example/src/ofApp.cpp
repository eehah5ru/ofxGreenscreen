#include "ofApp.h"





//--------------------------------------------------------------
void ofApp::setup() {
    
    ofBackground(0,0,255);
    grabber.setDeviceID(1);
	grabber.setup(640, 480);
	greenscreen.setCropLeft(0);
	greenscreen.setCropRight(0);

	//gui.addTitle("SETTINGS");
     gui_main.setup("chromaKey");


	//gui.addTitle("OUTPUT");
//    gui.addFPSCounter();
      gui_main.add(saveImgs.set("saveImgs",false));
    gui_main.add(greenscreen.parameters_chroma);
//    gui.addContent("camera", grabber);
//    gui.addContent("base mask", baseMask);
//    gui.addContent("detail mask", detailMask);
//    gui.addContent("chroma mask", chromaMask);
//    gui.addContent("mask", mask);

//    gui.addContent("red sub", redSub);
//    gui.addContent("green sub", greenSub);
//    gui.addContent("blue sub", blueSub);
	//gui.addContent("keyed", greenscreen);

     gui_main.loadFromFile("gui_main.xml");

}

//--------------------------------------------------------------
void ofApp::update() {
    
    fps = ofGetFrameRate();
    
    grabber.update();
    if(grabber.isFrameNew()){
        greenscreen.setPixels(grabber.getPixels());
        
        
        //THIS PART IS REALLY SLOW!!!
        mask.setFromPixels(greenscreen.getMask());
        detailMask.setFromPixels(greenscreen.getDetailMask());
        baseMask.setFromPixels(greenscreen.getBaseMask());
        chromaMask.setFromPixels(greenscreen.getChromaMask());
        
        redSub.setFromPixels(greenscreen.getRedSub());
        greenSub.setFromPixels(greenscreen.getGreenSub());
        blueSub.setFromPixels(greenscreen.getBlueSub());
        
        
        if(saveImgs){
            mask.save("save/mask.jpg");
            detailMask.save("save/detailMask.jpg");
            baseMask.save("save/baseMask.png");
            redSub.save("save/redSub.png");
            greenSub.save("save/greenSub.png");
            blueSub.save("save/blueSub.png");
            greenscreen.save("save/composition.png");
            saveImgs = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableAlphaBlending();
	greenscreen.draw(0, 0, greenscreen.getWidth(), greenscreen.getHeight());
	
    ofPushMatrix();
    ofTranslate(0, 500);
    grabber.draw(0, 0, 240, 160);
    baseMask.draw(240, 0, 240, 160);
    detailMask.draw(480, 0, 240, 160);
    chromaMask.draw(720, 0, 240, 160);
    mask.draw(960,0, 240, 160);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(0, 500+160);
    redSub.draw(0, 0, 240, 160);
    greenSub.draw(240, 0, 240, 160);
    blueSub.draw(480, 0, 240, 160);
      greenscreen.draw(720, 0, 240, 160);
    ofPopMatrix();
    
    //    gui.addContent("red sub", redSub);
    //    gui.addContent("green sub", greenSub);
    //    gui.addContent("blue sub", blueSub);
    //gui.addContent("keyed", greenscreen);
	greenscreen.drawBgColor();
	
    ofSetColor(0);
	ofDrawBitmapString("FPS "+ofToString(ofGetFrameRate()), 5, greenscreen.getHeight()+20);
   
    if(bShowGui){
        gui_main.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	/*if(key == OF_KEY_DOWN)
		greenscreen.clipBlackEndMask -= .01;
	if(key == OF_KEY_UP)
		greenscreen.clipBlackEndMask += .01;
	if(key == OF_KEY_LEFT)
		greenscreen.clipWhiteEndMask -= .01;
	if(key == OF_KEY_RIGHT)
		greenscreen.clipWhiteEndMask += .01;
	*/

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

    if(key == 'g'){
        bShowGui = !bShowGui;

        if(bShowGui == false){
             gui_main.saveToFile("gui_main.xml");
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	/*
	if(x== dragStart.x || y==dragStart.y)
		return;
	greenscreen.learnBgColor(grabber.getPixelsRef(), dragStart.x, dragStart.y, x-dragStart.x, y-dragStart.y);
	*/
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
//#ifdef USE_GUI
//    if(!gui.isOn())
//#endif
//        greenscreen.setBgColor(grabber.getPixelsRef().getColor(x, y));
//#ifdef USE_GUI
//    ofColor c = greenscreen.getBgColor();
//    bgColor[0] = c.r/255.;
//    bgColor[1] = c.g/255.;
//    bgColor[2] = c.b/255.;
//#endif
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
