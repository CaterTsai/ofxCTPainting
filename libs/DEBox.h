#ifndef OFX_CT_PAINTING_DEBOX
#define OFX_CT_PAINTING_DEBOX

#include "DEParameter.h"

class DEBox : public DEBasic<stBoxP>
{
public:
	static void draw(const stBoxP& param)
	{
		beginDraw(param);
		{
			float fBase_ = (param.fsize / 3.5);
			float fBoxH_ = fBase_ * 2.5;
			float fBoxW_ = fBoxH_ * 1.6;

			ofSetLineWidth(param.flineWidth);

			//Box body
			ofFill();
			ofSetColor(param.fillcolor);
			ofRect( fBoxW_ * -0.5, param.fsize  * -0.5, fBoxW_, fBoxH_);

			ofNoFill();
			ofSetColor(param.linecolor);
			ofRect( fBoxW_ * -0.5, param.fsize  * -0.5, fBoxW_, fBoxH_);

			//Cover
			ofFill();
			ofSetColor(param.fillcolor);
			ofRect(fBoxW_ * -0.5, param.fsize/2 - fBase_, fBoxW_, fBase_);

			ofNoFill();
			ofSetColor(param.linecolor);
			ofRect(fBoxW_ * -0.5, param.fsize/2- fBase_, fBoxW_, fBase_);

			ofVec2f LStart_, LEnd_, RStart_, REnd_;
			LStart_.set(fBoxW_ * -0.5, param.fsize/2 - fBase_);
			LEnd_ = LStart_ + ofVec2f(0, 1).rotate(45) * (fBase_) * 0.7;

			RStart_.set(fBoxW_ * 0.5, param.fsize/2 - fBase_);
			REnd_ = RStart_ + ofVec2f(0, 1).rotate(-45) * (fBase_) * 0.7;

			ofSetColor(param.linecolor);
			ofLine(LStart_, LEnd_);
			ofLine(RStart_, REnd_);

			//Hold
			ofFill();
			ofSetColor(param.linecolor);
			
			float fHoldW_ = fBoxW_ * 0.25;
			float fHoldH_ = fBase_ * 0.3;
			ofRect(fHoldW_ * -0.5, param.fsize  * -0.5 + fBoxH_ / 3 - fHoldH_ * 0.5, fHoldW_, fHoldH_);

		}
		endDraw();
	}
};

#endif // !OFX_CT_PAINTING_DEBOX
