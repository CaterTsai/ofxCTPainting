#ifndef OFX_CT_PAINTING_DEFIREFLOWER
#define OFX_CT_PAINTING_DEFIREFLOWER

#include "DEParameter.h"

class DEFireFlower : public DEBasic<stFireFlowerP>
{
public:
	static void draw(const stFireFlowerP& param)
	{
		beginDraw(param);
		{
			float fBaseLength_ = param.fsize / 12;
			ofSetLineWidth(param.flineWidth);
			//stem
			ofFill();
			ofSetColor(param.fillcolor);
			ofRect(fBaseLength_ * -1.0, fBaseLength_ * -6.0, fBaseLength_ * 2, fBaseLength_ * 12);
		
			ofNoFill();
			ofSetColor(param.linecolor);
			ofRect(fBaseLength_ * -1.0, fBaseLength_ * -6.0, fBaseLength_ * 2, fBaseLength_ * 12);
			
			//flower
			float fFlowerW_ = fBaseLength_ * 16 * param.fFlowerPrec;
			float fFlowerH_ = fBaseLength_ * 12 * param.fFlowerPrec;

			ofColor c1_, c2_;
			c1_ = param.fillcolor;
			c2_ = param.linecolor;
			
			for(int idx_ = 0; idx_ < 3; idx_++)
			{
				ofFill();
				ofSetColor(c1_);
				ofEllipse(0, fBaseLength_ * -6.0, fFlowerW_, fFlowerH_);
			
				ofNoFill();
				ofSetColor(c2_);
				ofEllipse(0, fBaseLength_ * -6.0, fFlowerW_, fFlowerH_);

				fFlowerW_ *= 0.7;
				fFlowerH_ *= 0.7;
				swap(c1_, c2_);
			}

			float fEyesW_ =  fBaseLength_ * 1 * param.fFlowerPrec;
			float fEyesH_ =  fBaseLength_ * 2.5 * param.fFlowerPrec;
			
			ofFill();
			ofSetColor(param.linecolor);
			ofEllipse(fBaseLength_ * -2.0, fBaseLength_ * -6.0, fEyesW_, fEyesH_);
			ofEllipse(fBaseLength_ * 2.0, fBaseLength_ * -6.0, fEyesW_, fEyesH_);

			//leaf
			ofPath Lleaf_, Rleaf_;
			Lleaf_.setFilled(true);
			Lleaf_.setFillColor(param.fillcolor);
			Lleaf_.setStrokeWidth(param.flineWidth);
			Lleaf_.setStrokeColor(param.linecolor);

			Rleaf_.setFilled(true);
			Rleaf_.setFillColor(param.fillcolor);
			Rleaf_.setStrokeWidth(param.flineWidth);
			Rleaf_.setStrokeColor(param.linecolor);

			float fLeftlength_ = fBaseLength_ * param.fLeafPrec;

			ofVec2f LleafS_, LleafE_, LleafC1_, LleafC2_, LleafC3_, LleafC4_;
			LleafS_.set(fBaseLength_ * -1.0, fBaseLength_ * 6.0);
			LleafE_ = LleafS_ + ofVec2f(-1, -1) * fLeftlength_ * 7.0;
			LleafC1_ = LleafS_ + ofVec2f(-1, 0) * fLeftlength_ * 3;
			LleafC2_ = LleafE_ + ofVec2f(0, 1) * fLeftlength_ * 5;
			LleafC3_ = LleafS_ + ofVec2f(0, -1) * fLeftlength_ * 3;
			LleafC4_ = LleafE_ + ofVec2f(1, 0) * fLeftlength_ * 3;

			Lleaf_.moveTo(LleafS_);
			Lleaf_.bezierTo(
				LleafC1_
				,LleafC2_
				,LleafE_
				);
			Lleaf_.bezierTo(
				LleafC4_
				,LleafC3_
				,LleafS_
				);
			Lleaf_.close();

			ofVec2f RleafS_, RleafE_, RleafC1_, RleafC2_, RleafC3_, RleafC4_;
			RleafS_.set(fBaseLength_ * 1.0, fBaseLength_ * 6.0);
			RleafE_ = RleafS_ + ofVec2f(1, -1) * fLeftlength_ * 7.0;
			RleafC1_ = RleafS_ + ofVec2f(1, 0) * fLeftlength_ * 3;
			RleafC2_ = RleafE_ + ofVec2f(0, 1) * fLeftlength_ * 5;
			RleafC3_ = RleafS_ + ofVec2f(0, -1) * fLeftlength_ * 3;
			RleafC4_ = RleafE_ + ofVec2f(-1, 0) * fLeftlength_ * 3;

			Rleaf_.moveTo(RleafS_);
			Rleaf_.bezierTo(
				RleafC1_
				,RleafC2_
				,RleafE_
				);
			Rleaf_.bezierTo(
				RleafC4_
				,RleafC3_
				,RleafS_
				);
			Rleaf_.close();

			Lleaf_.draw();
			Rleaf_.draw();
		}
		endDraw();
	}
};

#endif // !OFX_CT_PAINTING_DEFIREFLOWER
