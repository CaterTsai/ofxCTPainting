#ifndef OFX_CT_PAINTING_DEEXCLAMATION
#define OFX_CT_PAINTING_DEEXCLAMATION

#include "DEParameter.h"


class DEExclamation : public DEBasic<stExclamationMarkP> 
{
public:
	static void draw(const stExclamationMarkP& param)
	{
		beginDraw(param);
		{
			float baseHeight_ = param.fsize / 8.5;
			float baseWidth_ = baseHeight_ * 1.5;
			ofRectangle	bottom_;
			bottom_.setFromCenter(0, 0, baseWidth_, baseHeight_);

			ofVec2f tpL_, tpR_, cpL_, cpR_, bpL_, bpR_;
			bpL_.set(-baseWidth_ * 0.35, -baseHeight_);
			bpR_.set(-bpL_.x, bpL_.y);

			cpL_.set(-baseWidth_ * 0.5, -baseHeight_ * 2.5 );
			cpR_.set(-cpL_.x, cpL_.y);

			tpL_.set(-baseWidth_ * 0.6, -baseHeight_ * 7 );
			tpR_.set(-tpL_.x, tpL_.y);

			ofPath top_;
			top_.clear();
			top_.setFillColor(ofColor(param.fillcolor, param.alpha));
			top_.setFilled(param.bFill);
			top_.setStrokeWidth(param.flineWidth);
			top_.setStrokeColor(ofColor(param.linecolor, param.alpha));

			top_.moveTo(bpL_);
			top_.lineTo(cpL_);
			top_.lineTo(tpL_);
			top_.lineTo(tpR_);
			top_.lineTo(cpR_);
			top_.lineTo(bpR_);
			top_.close();

			ofSetLineWidth(param.flineWidth);
			if(param.bFill)
			{
				ofFill();
				ofSetColor(param.fillcolor, param.alpha);
				ofRect(bottom_);
			}
			ofNoFill();
			ofSetColor(param.linecolor, param.alpha);
			ofRect(bottom_);
			
			top_.draw();
		}
		endDraw();
	}
};

#endif // !OFX_CT_PAINTING_DEEXCLAMATION
