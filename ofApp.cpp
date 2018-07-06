#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofBackground(39);
	ofSetLineWidth(3);
	ofSetColor(239);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	int min_radius = 35;
	int max_radius = 110;
	int half_radius = (min_radius + max_radius) * 0.5;
	ofColor line_color;
	
	for (int x = -1; x <= 1; x++) {

		for (int y = -1; y <= 1; y++) {

			ofPoint location = ofPoint(x * 240, y * 240);

			for (int deg = 0; deg < 360; deg += 12) {

				ofPoint min_point = ofPoint(min_radius * cos(deg * DEG_TO_RAD), min_radius * sin(deg * DEG_TO_RAD)) + location;
				ofPoint max_point = ofPoint(max_radius * cos(deg * DEG_TO_RAD), max_radius * sin(deg * DEG_TO_RAD)) + location;
				ofPoint half_point = ofPoint(half_radius * cos(deg * DEG_TO_RAD), half_radius * sin(deg * DEG_TO_RAD)) + location;

				float noise_value = ofNoise(half_point.x * 0.01, half_point.y * 0.01, ofGetFrameNum() * 0.01);
				float noise_radius = ofMap(noise_value, 0, 1, min_radius, max_radius);

				ofPoint noise_point = ofPoint(noise_radius * cos(deg * DEG_TO_RAD), noise_radius * sin(deg * DEG_TO_RAD)) + location;
				ofPoint min_noise_point = ofPoint((noise_radius - 10) * cos(deg * DEG_TO_RAD), (noise_radius - 10) * sin(deg * DEG_TO_RAD)) + location;
				ofPoint max_noise_point = ofPoint((noise_radius + 10) * cos(deg * DEG_TO_RAD), (noise_radius + 10) * sin(deg * DEG_TO_RAD)) + location;

				ofDrawCircle(noise_point, 2.5);
				ofDrawLine(min_point, min_noise_point);
				ofDrawLine(max_point, max_noise_point);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}