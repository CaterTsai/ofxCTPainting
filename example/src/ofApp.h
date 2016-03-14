#pragma once

#include "ofMain.h"
#include "ofxCTPainting.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void exit();

private:

	stGiraffeP _giraffe;
	stSwingGiraffeP	_swingGiraffe;
	stLongGiraffeP	_longGiraffe;
	stOpenGiraffeP	_openGiraffe;
	stThreeLevelFireworkP _threeLevelFirework;
	stElevatorP _elevator;
	stBoxP _box;
	stJetpackP _jetpack;
	stPipeP _pipe;
	stFireFlowerP _fireFlower;
	stStarP _star;
	stCactusP _cactus;
	stPokeBallP _pokeBall;
	stPACManP _pacman;
	stGhostP _ghost;
	stExclamationMarkP _exclamationMark;
};
