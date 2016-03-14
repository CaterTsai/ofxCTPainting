#ifndef OFX_CT_PAINTING_DEPARAMETER
#define OFX_CT_PAINTING_DEPARAMETER

#include "ofMain.h"
#include "DEBasic.h"
//-----------------------------------
//Basic Parameter
typedef struct _stBasicP
{
	_stBasicP()
		:fsize(100)
		,fdegree(0)
		,drawPos(0, 0)
		,offsetPos(0, 0)
		,rotateAxis(drawPos)
		,scaleVec(1, 1)
		,bflip(false)
	{}

	bool bflip;
	float fsize, fdegree;
	ofVec2f drawPos, offsetPos;
	ofVec2f rotateAxis, scaleVec;
	
}stBasicP;

typedef struct _stBasicColorP
{
	_stBasicColorP()
		:flineWidth(2.0)
		,linecolor(ofColor(0))
		,fillcolor(ofColor(255))
		,falpha(255)
		,bFill(false)
	{}

	bool bFill;
	float flineWidth;
	ofColor	linecolor, fillcolor;
	float falpha;
}stBasicColorP;

#pragma region Giraffe
//-----------------------------------
//Normal Giraffe
typedef struct _stGiraffeP : public stBasicP, public stBasicColorP
{
	_stGiraffeP()
		:stBasicP()
		,stBasicColorP()
		,tongueD(-34.0)
		,tongueL(fsize * 0.1)
	{}

	float	tongueD, tongueL;
}stGiraffeP;

//-----------------------------------
//Swing Giraffe
typedef struct _stSwingGiraffeP : public stGiraffeP
{
	_stSwingGiraffeP()
		:stGiraffeP()
		,fswingDegree(0.0)
	{}
	float fswingDegree;
}stSwingGiraffeP;

//-----------------------------------
//Long Giraffe
typedef struct _stLongGiraffeP : public stGiraffeP
{
	_stLongGiraffeP()
		:stGiraffeP()
		,fneckLength(100.0)
	{}
	float fneckLength;
}stLongGiraffeP;

//-----------------------------------
//Open Giraffe
typedef struct _stOpenGiraffeP : public stGiraffeP
{
	_stOpenGiraffeP()
		:stGiraffeP()
		,openPerc(0.0)
	{}

	float openPerc; // 0~1
}stOpenGiraffeP;
#pragma endregion

//----------------------------------

#pragma region Firework
//-----------------------------------
//Three Level firework
typedef struct _stThreeLevelFireworkP : public stBasicP
{
	_stThreeLevelFireworkP()
		:stBasicP()
	{
		ZeroMemory(levelNum, sizeof(UINT8) * 3);
		ZeroMemory(levelAlpha, sizeof(UINT8) * 3);
		ZeroMemory(levelDegree, sizeof(float) * 3);
		ZeroMemory(levelDist, sizeof(float) * 3);

		levelColor[0] = ofColor(0);
		levelColor[1] = ofColor(0);
		levelColor[2] = ofColor(0);
	}

	UINT8 levelNum[3];
	UINT8 levelAlpha[3];
	float levelDegree[3], levelDist[3];
	ofColor levelColor[3];
}stThreeLevelFireworkP;

#pragma endregion

#pragma region Elevator
typedef struct _stElevatorP : public _stBasicP, public stBasicColorP
{
	_stElevatorP()
		:stBasicP()
		,stBasicColorP()
		,upPerc(0)
		,openPerc(0)
	{}

	float	upPerc, openPerc; //0~1
}stElevatorP;
#pragma endregion

#pragma region Box
typedef struct _stBoxP : public _stBasicP, public stBasicColorP
{
	_stBoxP()
		:stBasicP()
		,stBasicColorP()
	{}

}stBoxP;
#pragma endregion

#pragma region Jetpack
typedef struct _stJetpackP : public stBasicP, public stBasicColorP
{
	_stJetpackP()
		:stBasicP()
		,stBasicColorP()
		,fBeltLength(fsize * 0.5)
		,fFireLength(fsize * 0.5)
	{}

	float fBeltLength;
	float fFireLength;
}stJetpackP;
#pragma endregion

#pragma region Pipe
typedef struct _stPipeP: public stBasicP, public stBasicColorP
{
	_stPipeP()
		:stBasicP()
		,stBasicColorP()
		,fPipeLength(fsize * 3)
	{
	}

	float fPipeLength;
}stPipeP;
#pragma endregion

#pragma region Fire Flower
typedef struct _stFireFlowerP: public stBasicP, public stBasicColorP
{
	_stFireFlowerP()
		:stBasicP()
		,stBasicColorP()
		,fFlowerPrec(0.0)
		,fLeafPrec(0.0)
	{}

	float fFlowerPrec, fLeafPrec; //0.0~1.0
}stFireFlowerP;
#pragma endregion

#pragma region Star
typedef struct _stStarP : public stBasicP, public stBasicColorP
{
	_stStarP()
		:stBasicP()
		,stBasicColorP()
		,InRadiusRate(0.5)
	{}

	float InRadiusRate; // 0~1
}stStarP;
#pragma endregion

#pragma region Cactus
typedef struct _stCactusP : public stBasicP, public stBasicColorP
{
	_stCactusP()
		:stBasicP()
		,stBasicColorP()
	{};

}stCactusP;
#pragma endregion

#pragma region PokeBall
typedef struct _stPokeBallP : public stBasicP, public stBasicColorP
{
	_stPokeBallP()
		:stBasicP()
		,stBasicColorP()
		,openPerc(0.0)
	{};

	float openPerc; //0~1
}stPokeBallP;
#pragma endregion

#pragma region PAC-Man
typedef struct _stPACManP : public stBasicP, public stBasicColorP
{
	_stPACManP()
		:stBasicP()
		,stBasicColorP()
		,mouthPerc()
	{};

	float mouthPerc; //0~1
}stPACManP;
#pragma endregion

#pragma region Ghost
typedef struct _stGhostP : public stBasicP, public stBasicColorP
{
	_stGhostP()
		:stBasicP()
		,stBasicColorP()
		,scared(false)
	{};

	bool scared;
}stGhostP;
#pragma endregion

//-----------------------------------

#pragma region Mark
typedef struct _stExclamationMarkP : public stBasicP, public stBasicColorP
{
	_stExclamationMarkP()
		:stBasicP()
		,stBasicColorP()
		,alpha(255.0)
	{}

	float	alpha;
}stExclamationMarkP;
#pragma endregion

#endif // !OFX_CT_PAINTING_DEPARAMETER