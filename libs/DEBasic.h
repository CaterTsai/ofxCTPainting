#ifndef OFX_CT_PAINTING_DEBASIC
#define OFX_CT_PAINTING_DEBASIC

#include "ofMain.h"

template<class T>
class DEBasic
{
protected:	
	static void beginDraw(T param)
	{
		ofPushStyle();
		ofPushMatrix();

		ofTranslate(param.drawPos + param.rotateAxis);
		ofRotateZ(param.fdegree);
		ofTranslate(-(param.drawPos + param.rotateAxis));
		ofTranslate(param.drawPos + param.offsetPos);
		if(param.bflip)
		{
			ofScale(-1, 1);
		}
		ofScale(param.scaleVec.x, param.scaleVec.y);
	}
	
	static void endDraw()
	{		
		ofPopMatrix();
		ofPopStyle();
	}
};

#endif // !OFX_CT_PAINTING_DEBASIC
