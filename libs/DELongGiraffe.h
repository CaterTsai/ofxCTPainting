#ifndef OFX_CT_PAINTING_DELONGGIRAFFE
#define OFX_CT_PAINTING_DELONGGIRAFFE

#include "DEParameter.h"

class DELongGiraffe  : public DEBasic<stLongGiraffeP>
{
public:
	static void draw(stLongGiraffeP& param)
	{
		ofPath head_;
		ofVec2f startPos(-0.05 * param.fsize, -0.5 * (param.fneckLength - 0.2 * param.fsize));
		CreateOutline(head_, startPos, param);
		
		beginDraw(param);
		{
			ofSetColor(255);
			head_.draw();

			ofSetColor(param.linecolor);
			//tongue
			auto Tstart_ = ofBezierPoint( 
				startPos
				,ofVec2f(startPos.x - (0.4 * param.fsize), startPos.y)
				,ofVec2f(startPos.x - (0.4 * param.fsize), startPos.y - (0.1 * param.fsize))
				,ofVec2f(startPos.x, startPos.y - (0.2 * param.fsize))
				,0.2
			);

			auto Tend_ = ofBezierPoint( 
				startPos
				,ofVec2f(startPos.x - (0.4 * param.fsize), startPos.y)
				,ofVec2f(startPos.x - (0.4 * param.fsize), startPos.y - (0.1 * param.fsize))
				,ofVec2f(startPos.x, startPos.y - (0.2 * param.fsize))
				,0.3
			);

			ofVec2f tV_(-1, 0);
			tV_.rotate(param.tongueD).scale(param.tongueL);

			ofBezier(
				Tstart_.x, Tstart_.y
				,Tstart_.x + tV_.x, Tstart_.y + tV_.y
				,Tend_.x + tV_.x, Tend_.y + tV_.y
				,Tend_.x, Tend_.y
			);

			//eyes
			ofCircle(startPos.x, startPos.y + (-0.1 * param.fsize), 0.025 * param.fsize);

			//neck
			ofSetLineWidth(param.flineWidth);
			auto neckStartLeft_ = startPos;
			auto neckStartRight_ = ofVec2f(startPos.x + (0.125 * param.fsize), startPos.y + (-0.05 * param.fsize));
			auto neckEndLeft_ = ofVec2f(startPos.x, startPos.y + param.fneckLength);
			auto neckEndRight_ = ofVec2f(startPos.x + (0.3 * param.fsize), startPos.y + param.fneckLength);
			ofLine(neckStartLeft_, neckEndLeft_);
			ofLine(neckStartRight_, neckEndRight_);
			ofLine(neckEndLeft_, neckEndRight_);

			//spot
			auto neckLeftVec_ = (neckEndLeft_ - neckStartLeft_).normalized();
			auto neckRightVec_ = (neckEndRight_ - neckStartRight_).normalized();

			float spotBasicSize_ = 0.3 * param.fsize;
			int spotNum_ = static_cast<int>(param.fneckLength / spotBasicSize_);

			float spotLeftLength_, spotRightLength_;
			spotLeftLength_ = spotRightLength_ = spotBasicSize_;

			bool bLeft_ = true;
			for(int idx_ = 0; idx_ < spotNum_; idx_++)
			{
				int iduration_ = 0;
				ofVec2f s_, e_;
				if(bLeft_)
				{	
					s_ = neckStartLeft_ + (neckLeftVec_ * idx_ * spotLeftLength_);
					e_ = s_ + neckLeftVec_ * spotLeftLength_;
					iduration_ = 1;
				}
				else
				{
					s_ = neckStartRight_ + (neckRightVec_ * idx_ * spotRightLength_);
					e_ = s_ + neckRightVec_ * spotRightLength_;
					iduration_ = -1; 
				}

				auto drawS_ = s_.getInterpolated(e_, 0.2);
				auto drawE_ = s_.getInterpolated(e_, 0.8);

				ofBezier(	
					drawS_.x, drawS_.y
					,drawS_.x + iduration_ * (0.1 * param.fsize), drawS_.y
					,drawE_.x + iduration_ * (0.1 * param.fsize), drawE_.y
					,drawE_.x, drawE_.y
				);

				bLeft_ ^= true;
			}
		}
		endDraw();
	}
private:
	static void CreateOutline(ofPath& path, const ofVec2f& startPos, const stLongGiraffeP& param)
	{
		path.clear();
		path.setFillColor(param.fillcolor);
		path.setFilled(param.bFill);
		path.setStrokeWidth(param.flineWidth);
		path.setStrokeColor(param.linecolor);

		path.moveTo(startPos);

		//mouse
		path.bezierTo(
			startPos.x + (-0.4 * param.fsize), startPos.y
			,startPos.x + (-0.4 * param.fsize), startPos.y + (-0.1 * param.fsize)
			,startPos.x, startPos.y + (-0.2 * param.fsize)
		);

		//horn
		path.bezierTo(
			startPos.x + (0.05 * param.fsize), startPos.y + (-0.35 * param.fsize)
			,startPos.x + (0.125 * param.fsize), startPos.y + (-0.375 * param.fsize)
			,startPos.x + (0.125 * param.fsize), startPos.y + (-0.2 * param.fsize)
		);
		
		//ear
		path.bezierTo(
			startPos.x + (0.275 * param.fsize), startPos.y + (-0.2 * param.fsize)
			,startPos.x + (0.275 * param.fsize), startPos.y + (-0.05 * param.fsize)
			,startPos.x + (0.125 * param.fsize), startPos.y + (-0.05 * param.fsize)
		);
	}
};

#endif // !OFX_CT_PAINTING_DELONGGIRAFFE