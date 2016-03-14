#ifndef OFX_CT_PAINTING_DEPACMAN
#define OFX_CT_PAINTING_DEPACMAN

#include "DEParameter.h"

class DEPACMan : public DEBasic<stPACManP>
{
public:
	static void draw(const stPACManP& param)
	{
		beginDraw(param);
		{
			float fR_ = param.fsize * 0.5;
			float fDegree_ = param.mouthPerc * 90.0 * 0.5;
			ofPath path_;
			path_.clear();
			path_.setFillColor(ofColor(param.fillcolor, param.falpha));
			path_.setFilled(true);
			path_.setStrokeWidth(param.flineWidth);
			path_.setStrokeColor(ofColor(param.linecolor, param.falpha));
			path_.setArcResolution(50);

			ofVec2f s_;
			s_ = ofVec2f(-1, 0).rotate(fDegree_) * fR_;
			
			path_.moveTo(0, 0);
			path_.lineTo(s_);
			path_.arc(0, 0, fR_, fR_, 180.0 + fDegree_, 180.0 - fDegree_);
			path_.close();
			
			path_.draw();
		}
		endDraw();
	}
};

#endif // !OFX_CT_PAINTING_DEPACMAN
