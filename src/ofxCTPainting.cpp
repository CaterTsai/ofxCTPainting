#include "ofxCTPainting.h"

//--------------------------------------------------------------
void ofxCTPainting::draw(stGiraffeP& param)
{
	DEGiraffe::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stSwingGiraffeP& param)
{
	DESwingGiraffe::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stLongGiraffeP& param)
{
	DELongGiraffe::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stOpenGiraffeP& param)
{
	DEOpenGiraffe::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stThreeLevelFireworkP& param)
{
	DEThreeLevelFirework::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stElevatorP& param)
{
	DEElevator::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stBoxP& param)
{
	DEBox::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stJetpackP& param)
{
	DEJetpack::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stPipeP& param)
{
	DEPipe::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stFireFlowerP& param)
{
	DEFireFlower::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stStarP& param)
{
	DEStar::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stCactusP& param)
{
	DECacuts::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stPokeBallP& param)
{
	DEPokeBall::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stPACManP& param)
{
	DEPACMan::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stGhostP& param)
{
	DEGhost::draw(param);
}

//--------------------------------------------------------------
void ofxCTPainting::draw(stExclamationMarkP& param)
{
	DEExclamation::draw(param);
}

#pragma region Singleton
//--------------------------------------------------------------
ofxCTPainting* ofxCTPainting::pInstance = 0;
ofxCTPainting* ofxCTPainting::GetInstance()
{
	if(pInstance == 0)
	{
		pInstance = new ofxCTPainting();
	}
	return pInstance;
}

//--------------------------------------------------------------
void ofxCTPainting::Destroy()
{
	if(pInstance != 0)
	{
		delete pInstance;
	}
}
#pragma endregion

