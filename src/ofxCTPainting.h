#ifndef OFX_CT_PAINTING
#define OFX_CT_PAINTING

#include "DEParameter.h"

#include "DEGiraffe.h"
#include "DESwingGiraffe.h"
#include "DELongGiraffe.h"
#include "DEOpenGiraffe.h"
#include "DEThreeLevelFirework.h"
#include "DEElevator.h"
#include "DEBox.h"
#include "DEExclamationMark.h"
#include "DEJetpack.h"
#include "DEPipe.h"
#include "DEFireFlower.h"
#include "DEStar.h"
#include "DECactus.h"
#include "DEPokeBall.h"
#include "DEPACMan.h"
#include "DEGhost.h"

class ofxCTPainting
{
public:
	void draw(stGiraffeP& param);
	void draw(stSwingGiraffeP& param);
	void draw(stLongGiraffeP& param);
	void draw(stOpenGiraffeP& param);

	void draw(stThreeLevelFireworkP& param);
	void draw(stElevatorP& param);
	void draw(stBoxP& param);
	void draw(stJetpackP& param);
	void draw(stPipeP& param);
	void draw(stFireFlowerP& param);
	void draw(stStarP& param);
	void draw(stCactusP& param);
	void draw(stPokeBallP& param);
	void draw(stPACManP& param);
	void draw(stGhostP& param);

	void draw(stExclamationMarkP& param);
//-------------------
//Singleton
//-------------------
public:
	static ofxCTPainting* GetInstance();
	static void Destroy();

private:
	ofxCTPainting(){};
	ofxCTPainting(ofxCTPainting const&);
	void operator=(ofxCTPainting const&);
	static ofxCTPainting *pInstance;
};

#endif // !OFX_CT_PAINTING
