#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//grabber.listDevices();
	grabber.setDeviceID(0);
	grabber.setup(640, 480);
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofSeedRandom(mouseX);
	//grabber.draw(grabber.getWidth(),0);
	cam.begin();
	cam.enableOrtho();
	for (int y = 0; y < grabber.getHeight(); y += 10) {
		ofPolyline line;
		ofSetLineWidth(2);
		float noiseFactor = ofNoise(-30, 50);
		for (int x = 0; x < grabber.getWidth(); x+= 6) {
			float brightness = grabber.getPixels().getColor(x, y).getBrightness();
			float brightnessAdjusted = ofMap(brightness*x, 0, 255 * grabber.getWidth(), 0, 255);
			float brightnessZ = (brightnessAdjusted);
			//line.addVertex(x, y + ofMap(brightness, 0, 255, 0, mouseX));
			line.addVertex(x - grabber.getWidth()/2,(grabber.getHeight()-y-1) - grabber.getHeight()/2+ ofMap(brightnessZ, 0, 255, -mouseX, 60), ofMap(brightnessZ, 0, 255, -mouseX,100)+ ofRandom(-.5* x , .5*x));


		}
		line = line.getSmoothed(10);
		line.draw();
	}
	cam.end();
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
