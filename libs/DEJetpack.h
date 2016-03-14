#ifndef OFX_CT_PAINTING_DEJETPACK
#define OFX_CT_PAINTING_DEJETPACK

#include "DEParameter.h"

class DEJetpack : public DEBasic<stJetpackP>
{
public:
	static void draw(const stJetpackP& param)
	{
		beginDraw(param);
		{
			ofSetColor(255);
			float fBaseH_ = param.fsize / 7.0;
			float fBaseW_ = fBaseH_ * 2;

			//Jetpack
			ofVec2f	p1L_, p2L_, p3L_, p4L_;
			ofVec2f	p1R_, p2R_, p3R_, p4R_;

			p1L_.set(fBaseW_ * -0.5, fBaseH_ * -2.0);
			p2L_.set(fBaseW_ * -0.5, fBaseH_ * 2.0);
			p3L_.set(fBaseW_ * -0.25, fBaseH_ * 3.0);
			p4L_.set(fBaseW_ * -0.5, fBaseH_ * 4.5);

			p1R_.set(fBaseW_ * 0.5, fBaseH_ * -2.0);
			p2R_.set(fBaseW_ * 0.5, fBaseH_ * 2.0);
			p3R_.set(fBaseW_ * 0.25, fBaseH_ * 3.0);
			p4R_.set(fBaseW_ * 0.5, fBaseH_ * 4.5);

			ofPath Jetpack_;
			Jetpack_.setFilled(param.bFill);
			Jetpack_.setFillColor(param.fillcolor);
			Jetpack_.setStrokeWidth(param.flineWidth);
			Jetpack_.setStrokeColor(param.linecolor);

			Jetpack_.moveTo(p4L_);
			Jetpack_.lineTo(p3L_);
			Jetpack_.lineTo(p2L_);
			Jetpack_.lineTo(p1L_);
			Jetpack_.bezierTo(
				p1L_.x, p1L_.y + fBaseH_ * -2.0
				,p1R_.x, p1R_.y + fBaseH_ * -2.0
				,p1R_.x, p1R_.y
			);
			Jetpack_.lineTo(p2R_);
			Jetpack_.lineTo(p3R_);
			Jetpack_.lineTo(p4R_);
			Jetpack_.close();

			//Fire
			float fFireBase_ = param.fFireLength / 3.0;
			ofPath Fire_;
			ofVec2f sp1_, sp2_, ep1_, ep2_;

			sp1_.set(p3L_.x, p4L_.y);
			ep1_.set(p3R_.x, p4R_.y);
			sp2_.set(p4L_.x, sp1_.y + fFireBase_ * ofRandom(2, 3));
			ep2_.set(p4R_.x, sp1_.y + fFireBase_ * ofRandom(2, 3));

			Fire_.setFilled(true);
			Fire_.setFillColor(param.linecolor);
			Fire_.moveTo(sp1_);
			Fire_.lineTo(sp2_);

			int num_ = 3 + 2 * (rand() % 3);

			float flength_ = fBaseW_;
			float fbaseL_ = flength_ / (num_ );
			
			float px_ = sp2_.x;
			for(int idx_ = 0; idx_ < num_; idx_++)
			{
				ofVec2f newp_;
				px_ += fbaseL_ * ofRandom(0.7, 1.0);
				
				float foffset_ =  2 * fFireBase_ * (1 - (abs(px_)/(fBaseW_ * 0.5)));
				newp_.x = px_;

				if(idx_ % 2 == 0)
				{
					//In
					newp_.y = sp1_.y + fFireBase_ * ofRandom(0.5, 1.0);
				}
				else
				{
					//Out
					newp_.y = sp1_.y + fFireBase_ * ofRandom(2, 3);					
				}
				newp_.y += foffset_;

				Fire_.lineTo(newp_);
			}
			Fire_.lineTo(ep2_);
			Fire_.lineTo(ep1_);
			Fire_.close();

			//Draw
			Jetpack_.draw();
			Fire_.draw();

			ofSetLineWidth(param.flineWidth);

			if(param.bFill)
			{
				ofFill();
				ofSetColor(param.fillcolor);
				ofRect(
					-(param.fBeltLength + fBaseW_ * 0.5)
					,fBaseH_ * -1.0
					,param.fBeltLength + fBaseW_
					,fBaseH_);

				ofNoFill();
				ofSetColor(param.linecolor);
				ofRect(
					-(param.fBeltLength + fBaseW_ * 0.5)
					,fBaseH_ * -1.0
					,param.fBeltLength + fBaseW_
					,fBaseH_);
			}
			else
			{
				ofNoFill();
				ofSetColor(param.linecolor);
				ofRect(
					-(param.fBeltLength + fBaseW_ * 0.5)
					,fBaseH_ * -1.0
					,param.fBeltLength + fBaseW_
					,fBaseH_);
			}
			
		}
		endDraw();
	}

};

#endif // !OFX_CT_PAINTING_DEJETPACK
