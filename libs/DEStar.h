#ifndef OFX_CT_PAINTING_DESTAR
#define OFX_CT_PAINTING_DESTAR

#include "DEParameter.h"

class DEStar : public DEBasic<stStarP>
{
public:
	static void draw(const stStarP& param)
	{
		beginDraw(param);
		{
			ofPath star_;
			star_.setFilled(param.bFill);
			star_.setFillColor(ofColor(param.fillcolor, param.falpha));
			star_.setStrokeColor(ofColor(param.linecolor, param.falpha));
			star_.setStrokeWidth(param.flineWidth);

			float fOutRadius_ = param.fsize * 0.5;
			float fInRadius_ = fOutRadius_ * param.InRadiusRate;
			float fOutDegree_ = 0.0;
			float fInDegree_ = 36.0;

			star_.moveTo(0, -fOutRadius_);
			for (int idx_ = 0; idx_ < 5; idx_++, fOutDegree_ += 72, fInDegree_ += 72)
			{
				star_.lineTo(sin(fOutDegree_ * DEG_TO_RAD) * fOutRadius_, -cos(fOutDegree_ * DEG_TO_RAD) * fOutRadius_);
				star_.lineTo(sin(fInDegree_ * DEG_TO_RAD) * fInRadius_, -cos(fInDegree_ * DEG_TO_RAD) * fInRadius_);
			}
			star_.lineTo(0, -fOutRadius_);
			star_.close();

			star_.draw();
		}
		endDraw();
	}
};

#endif // !OFX_CT_PAINTING_DESTAR
