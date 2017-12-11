#include "ofApp.h"
ofShader shader;
float bandsX;
float bandsY;
float bandsR;
float bandsG;
float bandsB;

//--------------------------------------------------------------
void ofApp::setup() {

	songButton.addListener(this, &ofApp::songPressed);
	song2Button.addListener(this, &ofApp::song2Pressed);
	song3Button.addListener(this, &ofApp::song3Pressed);
	song4Button.addListener(this, &ofApp::song4Pressed);


	gui.setup();
	gui.add(songButton.setup("Frequency Test"));
	gui.add(song2Button.setup("Clair de Lune"));
	gui.add(song3Button.setup("Maple Leaf Rag"));
	gui.add(song4Button.setup("In a Sentimental Mood"));


	ofSetBackgroundColor(ofColor::white);
	shader.load("shader");
	song.load("frequency.mp3");
	song2.load("clair.mp3");
	song3.load("mapleLeafRag.mp3");
	song4.load("sentimentalMood.mp3");
	fftSmooth = new float[8192];
	for (int i = 0; i < 8192; i++)
	{
		fftSmooth[i] = 0;
	}
	bands = 64;
	song.play();
	song.setLoop(false);
}

//--------------------------------------------------------------
void ofApp::update() {
	bandsX = 0;
	bandsY = 0;
	float * value = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++)
	{
		fftSmooth[i] *= .9f;
		if (fftSmooth[i] < value[i]) {
			fftSmooth[i] = value[i];
		}
	}
	for (int i = 0; i < bands / 2; i++)
	{
		bandsX += fftSmooth[i];
	}

	for (int i = bands / 2; i < bands; i++)
	{
		bandsY += fftSmooth[i];
	}
	for (int i = 0; i < 21; i++)
	{
		bandsR += fftSmooth[i];
	}
	for (int i = 21; i < 42; i++)
	{
		bandsG += fftSmooth[i];
	}
	for (int i = 42; i < 64; i++)
	{
		bandsB += fftSmooth[i];
	}


}

//--------------------------------------------------------------
void ofApp::draw() {
	gui.draw();
	ofSetColor(ofColor(bandsR * 100, bandsG * 100, bandsB * 100));

	shader.begin();
	shader.setUniform1f("timeValX", bandsX);
	shader.setUniform1f("timeValY", bandsY);
	ofDrawSphere(ofGetWidth() / 2, ofGetHeight() / 2, 150);
	
	shader.end();
}

void ofApp::songPressed() {
	song2.stop();
	song3.stop();
	song4.stop();
	if (!song.isPlaying()) {
		song.play();
	}

}

void ofApp::song2Pressed() {
	song.stop();
	song3.stop();
	song4.stop();
	if (!song2.isPlaying()) {
		song2.play();
	}

}

void ofApp::song3Pressed() {

	song2.stop();
	song.stop();
	song4.stop();
	if (!song3.isPlaying()) {
		song3.play();
	}
}

void ofApp::song4Pressed() {

	song2.stop();
	song3.stop();
	song.stop();
	if (!song4.isPlaying()) {
		song4.play();
	}
}

