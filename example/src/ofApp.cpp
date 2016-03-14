#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetVerticalSync(true);

	ofxCTPainting::GetInstance();
	ofSetCurveResolution(50);
	float fwidth_ = ofGetWidth() / 4;
	float fheight_ = ofGetHeight() / 4;
	
	//stGiraffeP
	_giraffe.drawPos.set(fwidth_ * 0 + fwidth_/2.0, fheight_ * 0 + fheight_/2.0);
	_giraffe.fsize = fwidth_/2;

	//stSwingGiraffeP
	_swingGiraffe.drawPos.set(fwidth_ * 1 + fwidth_/2.0, fheight_ * 0 + fheight_/2.0);
	_swingGiraffe.fsize = fwidth_/2;

	//stLongGiraffeP
	_longGiraffe.drawPos.set(fwidth_ * 2 + fwidth_/2.0, fheight_ * 0 + fheight_/2.0);
	_longGiraffe.fsize = fwidth_/2;
	
	//stOpenGiraffeP
	_openGiraffe.drawPos.set(fwidth_ * 3 + fwidth_/2.0, fheight_ * 0 + fheight_/2.0);
	_openGiraffe.fsize = fwidth_/2;

	//stThreeLevelFireworkP
	_threeLevelFirework.drawPos.set(fwidth_ * 0 + fwidth_/2.0, fheight_ * 1 + fheight_/2.0);
	_threeLevelFirework.fsize = fwidth_/4;
	_threeLevelFirework.levelNum[0] = 3;
	_threeLevelFirework.levelNum[1] = 3;
	_threeLevelFirework.levelNum[2] = 4;
	_threeLevelFirework.levelAlpha[0] = 255;
	_threeLevelFirework.levelAlpha[1] = 255;
	_threeLevelFirework.levelAlpha[2] = 255;

	//stElevatorP
	_elevator.drawPos.set(fwidth_ * 1 + fwidth_/2.0, fheight_ * 1 + fheight_/2.0);
	_elevator.fsize = fwidth_/2;

	//stBoxP
	_box.drawPos.set(fwidth_ * 2 + fwidth_/2.0, fheight_ * 1 + fheight_/2.0);
	_box.fsize = fwidth_/2;
	
	//stJetpackP
	_jetpack.drawPos.set(fwidth_ * 3 + fwidth_/2.0, fheight_ * 1 + fheight_/2.0);
	_jetpack.fsize = fwidth_/2;
	
	//stPipeP
	_pipe.drawPos.set(fwidth_ * 0 + fwidth_/2.0, fheight_ * 2 + fheight_/2.0);
	_pipe.fsize = fwidth_/4;
	_pipe.fPipeLength = fheight_/4;

	//stFireFlowerP
	_fireFlower.drawPos.set(fwidth_ * 1 + fwidth_/2.0, fheight_ * 2 + fheight_/2.0);
	_fireFlower.fsize = fwidth_/2;

	//stStarP
	_star.drawPos.set(fwidth_ * 2 + fwidth_/2.0, fheight_ * 2 + fheight_/2.0);
	_star.fsize = fwidth_/2;

	//stCactusP
	_cactus.drawPos.set(fwidth_ * 3 + fwidth_/2.0, fheight_ * 2 + fheight_/2.0);
	_cactus.fsize = fwidth_/2;
	
	//stPokeBallP
	_pokeBall.drawPos.set(fwidth_ * 0 + fwidth_/2.0, fheight_ * 3 + fheight_/2.0);
	_pokeBall.fsize = fwidth_/2;

	//stPACManP
	_pacman.drawPos.set(fwidth_ * 1 + fwidth_/2.0, fheight_ * 3 + fheight_/2.0);
	_pacman.fsize = fwidth_/2;

	//stGhostP
	_ghost.drawPos.set(fwidth_ * 2 + fwidth_/2.0, fheight_ * 3 + fheight_/2.0);
	_ghost.fsize = fwidth_/2;

	//stExclamationMarkP
	_exclamationMark.drawPos.set(fwidth_ * 3+ fwidth_/2.0, fheight_ * 3 + fheight_/2.0);
	_exclamationMark.fsize = fwidth_/2;
}

//--------------------------------------------------------------
void ofApp::update()
{
	float val_ = abs(std::sin( ((ofGetFrameNum() % 120)/ 120.0) * (PI)));

	//stSwingGiraffeP
	_swingGiraffe.fswingDegree = val_ * 120.0 - 60.0;

	//stLongGiraffeP
	_longGiraffe.fneckLength = val_ * _longGiraffe.fsize * 2.0;
	
	//stOpenGiraffeP
	_openGiraffe.openPerc = val_;

	//stThreeLevelFireworkP
	_threeLevelFirework.levelDist[0] = val_ * 20;
	_threeLevelFirework.levelDist[1] = val_ * 40;
	_threeLevelFirework.levelDist[2] = val_ * 60;

	//stElevatorP
	_elevator.upPerc = val_;
	_elevator.openPerc = val_;

	//stJetpackP
	_jetpack.fFireLength = 50 * val_;
	
	//stPipeP
	_pipe.fPipeLength = 50 * val_ + 50;

	//stFireFlowerP
	_fireFlower.fFlowerPrec = val_;
	_fireFlower.fLeafPrec = val_;

	//stStarP
	_star.InRadiusRate = val_;

	//stPokeBallP
	_pokeBall.openPerc = val_;

	//stPACManP
	_pacman.mouthPerc = val_;

	//stGhostP
	if(val_ == 0.0)
	{
		_ghost.scared ^= true;
	}

	//stExclamationMarkP
	_exclamationMark.scaleVec = ofVec2f(1.0, val_);
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	float fwidth_ = ofGetWidth() / 4;
	float fheight_ = ofGetHeight() / 4;

	ofPushMatrix();
	{
		ofSetColor(255);
		ofxCTPainting::GetInstance()->draw(_giraffe);		
		ofxCTPainting::GetInstance()->draw(_swingGiraffe);
		ofxCTPainting::GetInstance()->draw(_longGiraffe);
		ofxCTPainting::GetInstance()->draw(_openGiraffe);
		ofxCTPainting::GetInstance()->draw(_threeLevelFirework);
		ofxCTPainting::GetInstance()->draw(_elevator);
		ofxCTPainting::GetInstance()->draw(_box);
		ofxCTPainting::GetInstance()->draw(_jetpack);
		ofxCTPainting::GetInstance()->draw(_pipe);
		ofxCTPainting::GetInstance()->draw(_fireFlower);
		ofxCTPainting::GetInstance()->draw(_star);
		ofxCTPainting::GetInstance()->draw(_cactus);
		ofxCTPainting::GetInstance()->draw(_pokeBall);
		ofxCTPainting::GetInstance()->draw(_pacman);
		ofxCTPainting::GetInstance()->draw(_ghost);
		ofxCTPainting::GetInstance()->draw(_exclamationMark);

		ofSetColor(0);
		ofDrawBitmapStringHighlight("stGiraffeP", fwidth_ * 0 + 10, fheight_ * 0 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stSwingGiraffeP", fwidth_ * 1 + 10, fheight_ * 0 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stLongGiraffeP", fwidth_ * 2 + 10, fheight_ * 0 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stOpenGiraffeP", fwidth_ * 3 + 10, fheight_ * 0 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stThreeLevelFireworkP", fwidth_ * 0 + 10, fheight_ * 1 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stElevatorP", fwidth_ * 1 + 10, fheight_ * 1 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stBoxP", fwidth_ * 2 + 10, fheight_ * 1 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stJetpackP", fwidth_ * 3 + 10, fheight_ * 1 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stPipeP", fwidth_ * 0 + 10, fheight_ * 2 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stFireFlowerP", fwidth_ * 1 + 10, fheight_ * 2 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stStarP", fwidth_ * 2 + 10, fheight_ * 2 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stCactusP", fwidth_ * 3 + 10, fheight_ * 2 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stPokeBallP", fwidth_ * 0 + 10, fheight_ * 3 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stPACManP", fwidth_ * 1 + 10, fheight_ * 3 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stGhostP", fwidth_ * 2 + 10, fheight_ * 3 + fheight_ - 10);
		ofDrawBitmapStringHighlight("stExclamationMarkP", fwidth_ * 3 + 10, fheight_ * 3 + fheight_ - 10);
	}
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::exit()
{
	ofxCTPainting::Destroy();
}