#ifndef OFX_CT_PAINTING_DEPOKEBALL
#define OFX_CT_PAINTING_DEPOKEBALL

#include "DEParameter.h"

class DEPokeBall : public DEBasic<stPokeBallP>
{
public:
	static void draw(const stPokeBallP& param)
	{
		beginDraw(param);
		{
			ofPath bottom_, top_, belt_;
			float fopenH_ = sinf(param.openPerc * 90.0 * DEG_TO_RAD) * param.fsize;
			
			//Create
			//Bottom
			createBottom(bottom_, param);
			
			//Top
			float fopenW_ = createTop(top_, param, fopenH_);
			float fopenY_ = (ofVec2f(-1, 0).rotate(5) * param.fsize * 0.5).y;
			//Belt
			createBelt(belt_, param);

			//Draw
			//Top
			top_.draw();

			//Inside
			ofFill();
			ofSetColor(param.fillcolor);
			ofEllipse(0, fopenY_ + fopenH_  * -0.5, fopenW_, fopenH_);

			ofNoFill();
			ofSetLineWidth(2);
			ofSetColor(param.linecolor);
			ofEllipse(0, fopenY_ + fopenH_  * -0.5, fopenW_, fopenH_);

			//Bottom
			bottom_.draw();

			//Belt
			belt_.draw();

			ofNoFill();
			ofSetColor(param.linecolor);
			ofSetLineWidth(2);
			ofCircle(0, 0, param.fsize * 0.5 * 0.2);

		}
		endDraw();
	}

private:
	static void createBottom(ofPath& path, const stPokeBallP& param)
	{
		path.clear();
		path.setFillColor(ofColor(param.fillcolor, param.falpha));
		path.setFilled(true);
		path.setStrokeWidth(param.flineWidth);
		path.setStrokeColor(ofColor(param.linecolor, param.falpha));
		path.setArcResolution(50);

		ofVec2f start_, end_;

		start_ = ofVec2f(-1, 0).rotate(-5) * param.fsize * 0.5;
		end_ =  ofVec2f(1, 0).rotate(5) * param.fsize * 0.5;

		path.moveTo(start_);
		path.lineTo(end_);
		path.arc(0, 0, param.fsize * 0.5, param.fsize * 0.5, 0 + 5, 180 - 5);
	}

	static float createTop(ofPath& path, const stPokeBallP& param, float fopenH)
	{
		path.clear();
		path.setFillColor(ofColor(param.linecolor, param.falpha));
		path.setFilled(true);
		path.setStrokeWidth(param.flineWidth);
		path.setStrokeColor(ofColor(param.linecolor, param.falpha));
		path.setArcResolution(50);

		ofVec2f start_, end_;
		start_ = ofVec2f(-1, 0).rotate(5) * param.fsize * 0.5;
		end_ =  ofVec2f(1, 0).rotate(-5) * param.fsize * 0.5;

		float farcX_ = start_.distance(end_) * 0.5;
		float farcY_ = param.fsize * 0.5 - abs(start_.y - 0);

		
		start_ += ofVec2f(0,  fopenH * -0.5);
		end_ += ofVec2f(0,  fopenH * -0.5);

		path.moveTo(end_);
		path.lineTo(start_);
		path.arc(0, start_.y, farcX_, farcY_, 180, 0);

		return start_.distance(end_);
	}

	static void createBelt(ofPath& path, const stPokeBallP& param)
	{
		path.clear();
		path.setFillColor(ofColor(param.fillcolor, param.falpha));
		path.setFilled(true);
		path.setStrokeWidth(param.flineWidth);
		path.setStrokeColor(ofColor(param.linecolor, param.falpha));

		ofVec2f p1_, p2_, p3_, p4_;
		p1_ = ofVec2f(-1, 0).rotate(5) * (param.fsize * 0.5);
		p2_ = ofVec2f(1, 0).rotate(-5) * (param.fsize * 0.5);
		p3_ = ofVec2f(1, 0).rotate(5) * (param.fsize * 0.5);
		p4_ = ofVec2f(-1, 0).rotate(-5) * (param.fsize * 0.5);
		p1_.x *= 0.95;
		p2_.x *= 0.95;
		p3_.x *= 0.95;
		p4_.x *= 0.95;

		float fCircleR_ = param.fsize * 0.5 * 0.4;
		float fradian_ = asin(abs(p1_.y - 0)/fCircleR_);
		float fdegree_ = fradian_ * RAD_TO_DEG;
		float fCircleX_ = fCircleR_ * cosf(fradian_);
		ofVec2f a1_, a2_;
		a1_ = ofVec2f(-fCircleX_, p1_.y);
		a2_ = ofVec2f(fCircleX_, p3_.y);
		
		
		path.moveTo(p1_);
		path.lineTo(a1_);
		path.arc(0, 0, fCircleR_, fCircleR_, 180 + fdegree_, 0 - fdegree_);
		path.lineTo(p2_);
		path.lineTo(p3_);
		path.lineTo(a2_);
		path.arc(0, 0, fCircleR_, fCircleR_, 0 + fdegree_, 180 - fdegree_);
		path.lineTo(p4_);
		path.close();
	}
};

#endif // !OFX_CT_PAINTING_DEPOKEBALL
