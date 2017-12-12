#include "ofApp.h"
ofShader shader;
<<<<<<< HEAD
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
=======
float bandsX; 
float bandsY;
float bandsR; 
float bandsG; 
float bandsB;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(ofColor().white);

	shader.load("shader");
	song.load("yesterday.mp3");
>>>>>>> a4c6c43ed7978561fd8f10a2999e14ae941b8a77
	fftSmooth = new float[8192];
	for (int i = 0; i < 8192; i++)
	{
		fftSmooth[i] = 0;
	}
	bands = 64;
	song.play();
<<<<<<< HEAD
	song.setLoop(false);
}

//--------------------------------------------------------------
void ofApp::update() {
=======
	song.setLoop(true);
}

//--------------------------------------------------------------
void ofApp::update(){
>>>>>>> a4c6c43ed7978561fd8f10a2999e14ae941b8a77
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
<<<<<<< HEAD
	for (int i = 0; i < bands / 2; i++)
=======
	for (int i = 0; i < bands/2; i++)
>>>>>>> a4c6c43ed7978561fd8f10a2999e14ae941b8a77
	{
		bandsX += fftSmooth[i];
	}

<<<<<<< HEAD
	for (int i = bands / 2; i < bands; i++)
	{
		bandsY += fftSmooth[i];
	}
	for (int i = 0; i < 21; i++)
=======
	for (int i = bands/2; i < bands; i++)
	{
		bandsY += fftSmooth[i];
	}
	for (int i =0 ; i < 21; i++)
>>>>>>> a4c6c43ed7978561fd8f10a2999e14ae941b8a77
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
<<<<<<< HEAD
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

=======
void ofApp::draw(){
	ofSetColor(ofColor(bandsR*100,bandsG*100,bandsB*100));

	shader.begin();
	shader.setUniform1f("timeValX", bandsX);
	shader.setUniform1f("timeValY", bandsY );
	ofDrawSphere(ofGetWidth()/2, ofGetHeight()/2, 150);
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
>>>>>>> a4c6c43ed7978561fd8f10a2999e14ae941b8a77
