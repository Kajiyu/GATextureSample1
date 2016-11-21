#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(10);
    ans.load("ans.jpg");
    ga.initialize(ans);
    
    title.load("font.otf", 40);
    age.load("font.otf", 30);
    index.load("font.otf", 20);
    
    for (int i = 0; i < 10; i++) {
        textures[i].allocate(100, 100, GL_RGBA);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ga.currentAge++;
    if (ga.currentAge < ga.maxAge) {
        ga.evaluate();
        ga.selection();
        ga.mutation();
        for (int i = 0; i < 10; i++) {
            textures[i].loadData(ga.pixels[i]);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    ofSetColor(255, 255, 0);
    title.drawString("Gene Algorism Simulator", ofGetWidth()/10, ofGetHeight()/10);
    ofSetColor(255, 255);
    age.drawString(ofToString(ga.currentAge), ofGetWidth()-100, ofGetHeight()/10);
    ans.draw(ofGetWidth()/2 -50, 200);
    
    for (int i = 0; i < 10; i++) {
        textures[i].draw(ofGetWidth() * i / 10, ofGetHeight()*3/4);
    }
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
