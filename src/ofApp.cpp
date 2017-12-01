#include "ofApp.h"
ofShader shader;
float bandsX; 
float bandsY;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(ofColor().white);

	shader.load("shader");
	song.load("yesterday.mp3");
	fftSmooth = new float[8192];
	for (int i = 0; i < 8192; i++)
	{
		fftSmooth[i] = 0;
	}
	bands = 64;
	song.play();
	song.setLoop(true);
}

//--------------------------------------------------------------
void ofApp::update(){
	float * value = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++)
	{
		fftSmooth[i] *= .9f;
		if (fftSmooth[i] < value[i]) {
			fftSmooth[i] = value[i];
		}
	}
	for (int i = 0; i < bands/2; i++)
	{
		bandsX += fftSmooth[i];
	}

	for (int i = bands/2; i < bands; i++)
	{
		bandsY += fftSmooth[i];
	}

	std::cout << bandsX << std::endl;
	std::cout << bandsY << std::endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor().black);

	shader.begin();
	shader.setUniform1f("timeValX", bandsX);
	shader.setUniform1f("timeValY", bandsY );
	ofDrawSphere(ofGetWidth()/2, ofGetHeight()/2, 100);
	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
