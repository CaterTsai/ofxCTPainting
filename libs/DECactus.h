#ifndef OFX_CT_PAINTING_DECACUTS
#define OFX_CT_PAINTING_DECACUTS

#include "DEParameter.h"

class DECacuts : public DEBasic<stCactusP>
{
public:
	static void draw(const stCactusP& param)
	{
		beginDraw(param);
		{
			float fBasic_ = param.fsize / 7.0;

			//hair
			ofSetColor(param.linecolor, param.falpha);
			ofSetLineWidth(param.flineWidth);
			ofVec2f hairV_(0, -1);
			ofVec2f hairSP_(0, -fBasic_ * 2.5);
			
			ofLine(hairSP_, hairSP_ + hairV_.getRotated(-15) * fBasic_ * 2);
			ofLine(hairSP_, hairSP_ + hairV_.getRotated(0) * fBasic_ * 2);
			ofLine(hairSP_, hairSP_ + hairV_.getRotated(15) * fBasic_ * 2);

			//Body & Hand
			ofPath body_, leftHand_, rightHand_;
			CreateBody(body_, param);
			CreateLeftHand(leftHand_, param);
			CreateRightHand(rightHand_, param);
			
			body_.draw();
			leftHand_.draw();
			rightHand_.draw();

			//eyes
			ofFill();
			ofSetColor(param.linecolor, param.falpha);
			ofCircle(fBasic_ * -0.5, fBasic_ * -1.8, fBasic_ * 0.2);
			ofCircle(fBasic_ * 0.5, fBasic_ * -1.8, fBasic_ * 0.2);

			//mouth
			ofEllipse(0, fBasic_ * -0.7, fBasic_ * 0.4, fBasic_ * 1.0);


		}
		endDraw();
	}

private:
	static void CreateBody(ofPath& path, const stCactusP& param)
	{
		path.clear();
		path.setFillColor(ofColor(param.fillcolor, param.falpha));
		path.setFilled(true);
		path.setStrokeWidth(param.flineWidth);
		path.setStrokeColor(ofColor(param.linecolor, param.falpha));

		float fBasic_ = param.fsize / 7.0;

		//Body
		path.moveTo(-fBasic_, fBasic_);
		path.lineTo(-fBasic_, -fBasic_ * 2.5);
		path.arc(0, -fBasic_ * 2.5, fBasic_, fBasic_, 180, 0);
		path.lineTo(fBasic_, fBasic_ * 2.5);

		//Right Leg
		path.lineTo(fBasic_ * 2.25, fBasic_ * 2.5);
		path.arc(fBasic_ * 2.25, fBasic_ * 3.0, fBasic_ * 0.3, fBasic_ * 0.5,270, 90);
		path.lineTo(fBasic_ * 0.5, fBasic_ * 3.5);
		path.arc(fBasic_ * 0.5, fBasic_ * 3.0, fBasic_ * 0.5, fBasic_ * 0.5, 90, 180);
		path.lineTo(0 , fBasic_ * 2.0);

		//Left Leg
		path.lineTo(fBasic_ * -1.25, fBasic_ * 2.0);
		path.lineTo(fBasic_ * -1, fBasic_ * 3.2);
		path.arc(fBasic_ * -1.50, fBasic_ * 3.2, fBasic_ * 0.5, fBasic_ * 0.3, 0, 180);
		path.lineTo(fBasic_ * -2.25, fBasic_ * 1.5);
		path.arc(fBasic_ * -1.75, fBasic_ * 1.5, fBasic_ * 0.5, fBasic_ * 0.5, 180, 270);
		path.close();
	}

	static void CreateLeftHand(ofPath& path, const stCactusP& param)
	{
		path.clear();
		path.setFillColor(ofColor(param.fillcolor, param.falpha));
		path.setFilled(true);
		path.setStrokeWidth(param.flineWidth);
		path.setStrokeColor(ofColor(param.linecolor, param.falpha));

		float fBasic_ = param.fsize / 7.0;
		path.moveTo(fBasic_ * -1.0, 0);

		path.lineTo(fBasic_ * -2.05, 0);
		path.arc(fBasic_ * -2.05, fBasic_ * -0.35, fBasic_ * 0.35, fBasic_ * 0.35, 90, 180);
		path.lineTo(fBasic_ * -2.4, fBasic_ * -1.7);
		path.arc(fBasic_ * -2.05, fBasic_ * -1.7, fBasic_ * 0.35, fBasic_ * 0.2, 180, 0);
		path.lineTo(fBasic_ * -1.7, fBasic_ * -0.7);
		path.lineTo(fBasic_ * -1.0, fBasic_ * -0.7);

		path.close();

	}

	static void CreateRightHand(ofPath& path, const stCactusP& param)
	{
		path.clear();
		path.setFillColor(ofColor(param.fillcolor, param.falpha));
		path.setFilled(true);
		path.setStrokeWidth(param.flineWidth);
		path.setStrokeColor(ofColor(param.linecolor, param.falpha));

		float fBasic_ = param.fsize / 7.0;
		path.moveTo(fBasic_ * 1.0, fBasic_ * -0.7);


		path.lineTo(fBasic_ * 2.05, fBasic_ * -0.7);
		path.arc(fBasic_ * 2.05, fBasic_ * -0.35, fBasic_ * 0.35, fBasic_ * 0.35, 270, 0);
		path.lineTo(fBasic_ * 2.4, fBasic_ * 1.0);
		path.arc(fBasic_ * 2.05, fBasic_ * 1.0, fBasic_ * 0.35, fBasic_ * 0.2, 0, 180);
		path.lineTo(fBasic_ * 1.7, 0);
		path.lineTo(fBasic_ * 1.0, 0);

		path.close();
	}
};

#endif // !OFX_CT_PAINTING_DECACUTS
