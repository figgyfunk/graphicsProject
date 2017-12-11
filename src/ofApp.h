#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void songPressed();
	void song2Pressed();
	void song3Pressed();
	void song4Pressed();


	ofSoundPlayer song;
	ofSoundPlayer song2; 
	ofSoundPlayer song3; 
	ofSoundPlayer song4;

	float * fftSmooth;
	int bands;

	ofxPanel gui; 
	ofxButton songButton;
	ofxButton song2Button; 
	ofxButton song3Button; 
	ofxButton song4Button;

	

};
