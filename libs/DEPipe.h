#ifndef OFX_CT_PAINTING_DEPIPE
#define OFX_CT_PAINTING_DEPIPE

#include "DEParameter.h"

class DEPipe : public DEBasic<stPipeP>
{
public:
	static void draw(const stPipeP& param)
	{
		beginDraw(param);
		{
			float fHeadH_ = param.fsize;
			float fHeadW_ = param.fsize * 2.214;
			float fBodyW_ = fHeadW_ * 0.9;
			float fTotalLength_ = fHeadH_ + param.fPipeLength;
			ofSetLineWidth(param.flineWidth);
			
			//pipe body			
			ofFill();
			ofSetColor(param.fillcolor);
			ofRect(-fBodyW_/2, -(fTotalLength_/2 - fHeadH_), fBodyW_, param.fPipeLength);
			ofNoFill();
			ofSetColor(param.linecolor);
			ofRect(-fBodyW_/2, -(fTotalLength_/2 - fHeadH_), fBodyW_, param.fPipeLength);

			//pipe head
			ofFill();
			ofSetColor(param.fillcolor);
			ofRect(-fHeadW_/2, -fTotalLength_/2, fHeadW_, fHeadH_);
			ofNoFill();
			ofSetColor(param.linecolor);
			ofRect(-fHeadW_/2, -fTotalLength_/2, fHeadW_, fHeadH_);
		}
		endDraw();
	}

};


#endif // !OFX_CT_PAINTING_DEPIPE
