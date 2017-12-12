#pragma once

#include "ofMain.h"
<<<<<<< HEAD
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

	

=======

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofSoundPlayer song;
		float * fftSmooth;
		int bands;
		
>>>>>>> a4c6c43ed7978561fd8f10a2999e14ae941b8a77
};
