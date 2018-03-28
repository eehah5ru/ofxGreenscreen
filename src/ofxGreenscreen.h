#ifndef OFXGREENSCREEN_H
#define OFXGREENSCREEN_H

#include "ofMain.h"
#include <opencv2/opencv.hpp>

typedef cv::Ptr<cv::Mat> cvImg;

class ofxGreenscreen: public ofImage {

public:
	ofxGreenscreen();
	~ofxGreenscreen();
	void setPixels(ofPixels pixels);
	void setPixels(unsigned char*, int w, int h);
	void setBgColor(ofColor col);
	ofColor getBgColor();
	void drawBgColor(int x=0, int y=0, int w=10, int h=10);
	void draw(int x, int y, int w, int h, bool checkers=false);
	void learnBgColor(ofPixels pixels);
	void learnBgColor(ofPixels pixels, int x, int y, int w, int h);

	ofPixels getBaseMask();
	ofPixels getDetailMask();
	ofPixels getChromaMask();
	ofPixels getMask();

	ofPixels getRedSub();
	ofPixels getBlueSub();
	ofPixels getGreenSub();

    ofParameterGroup parameters_chroma;
	//ALL THE FOLLOWING VALUES ARE IN A RANGE 0 - 1
	ofParameter<float> clipBlackBaseMask, clipWhiteBaseMask;
	ofParameter<float> clipBlackDetailMask, clipWhiteDetailMask;
	ofParameter<float> clipBlackEndMask, clipWhiteEndMask;
	ofParameter<float> clipBlackChromaMask, clipWhiteChromaMask;
	ofParameter<float> strengthBaseMask;
	ofParameter<float> strengthChromaMask;
	ofParameter<float> strengthGreenSpill;
 ofParameter<ofColor> bgColor;
    
	void setCropLeft(float val);
	void setCropRight(float val);

	//values from 0 - 1
	float cropTop;
	float cropBottom;
	float cropLeft;
	float cropRight;

	//enable masks and steps
	ofParameter<bool> doBaseMask;
	ofParameter<bool> doDetailMask;
	ofParameter<bool> doChromaMask;
	ofParameter<bool> doGreenSpill;

private:
	void update();
	void drawCheckers(int x, int y, int w, int h);

	//private
	int width;
	int height;

	//cv Mats
	cv::Mat mask;
	cv::Mat maskDetail;
	cv::Mat maskBase;
	cv::Mat maskChroma;
	cv::Mat red;
	cv::Mat green;
	cv::Mat blue;
	cv::Mat redSub;
	cv::Mat greenSub;
	cv::Mat blueSub;

	//greenkey color
//    ofColor bgColor;

	//raw input data
	cv::Mat input;
};

#endif // OFXGREENSCREEN_H
