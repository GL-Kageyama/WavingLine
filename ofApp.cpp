#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("WavingLine");
    
    ofBackground(255, 236, 186);
    ofSetColor(186, 33, 66, 100);
    ofSetLineWidth(3);
    ofEnableDepthTest();
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    this->cam.begin();
    
    for(int deg = 0; deg < 360; deg += 1){
        auto noise_point = glm::vec2(cos(deg * DEG_TO_RAD), sin(deg * DEG_TO_RAD));
        int u = ofMap(ofNoise(noise_point.x * 0.5, noise_point.y * 0.5, ofGetFrameNum() * 0.008), 0, 1, 0, 360);
        
        auto start = this->make_point(180, 170, (u) * DEG_TO_RAD, deg * DEG_TO_RAD);
        auto end = this->make_point(180, 170, (u + 180) * DEG_TO_RAD, deg * DEG_TO_RAD);
        
        ofDrawSphere(start, 10);
        ofDrawSphere(end, 25);
        
        ofDrawLine(start, end);
    }
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v){
    float x = (R + r * cos(u)) * cos(v);
    float y = (R + r * cos(u)) * sin(v);
    float z = r * sin(u);
    
    return glm::vec3(x, y, z);
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



