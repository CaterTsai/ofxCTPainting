#ifndef OFX_CT_PAINTING_DESWINGGIRAFFE
#define OFX_CT_PAINTING_DESWINGGIRAFFE

#include "DEParameter.h"

class DESwingGiraffe  : public DEBasic<stSwingGiraffeP>
{
public:
	static void draw(stSwingGiraffeP& param)
	{
		ofPath head_;
		CreateOutline(head_, param);

		beginDraw(param);
		{
			ofSetColor(255);
			auto BaseMatrix_ = ofGetCurrentMatrix(OF_MATRIX_MODELVIEW);
			ofMatrix4x4	T_;

			ofPushMatrix();
			ofTranslate(0.1 * param.fsize, 0.5 * param.fsize);
			ofRotateZ(param.fswingDegree);
			ofTranslate(-0.1 * param.fsize, -0.5 * param.fsize);
			{
				head_.draw();

				ofSetColor(param.linecolor);
				//tongue
				auto Tstart_ = ofBezierPoint( 
					ofVec2f(-0.05 * param.fsize, -0.3 * param.fsize)
					,ofVec2f(-0.45 * param.fsize, -0.3 * param.fsize)
					,ofVec2f(-0.45 * param.fsize, -0.4 * param.fsize)
					,ofVec2f(-0.05 * param.fsize,  -0.5 * param.fsize)
					,0.2
				);

				auto Tend_ = ofBezierPoint( 
					ofVec2f(-0.05 * param.fsize, -0.3 * param.fsize)
					,ofVec2f(-0.45 * param.fsize, -0.3 * param.fsize)
					,ofVec2f(-0.45 * param.fsize, -0.4 * param.fsize)
					,ofVec2f(-0.05 * param.fsize,  -0.5 * param.fsize)
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
				ofCircle(-0.05 * param.fsize, -0.4 * param.fsize, 0.025 * param.fsize);

				T_ = ofGetCurrentMatrix(OF_MATRIX_MODELVIEW) * BaseMatrix_.getInverse();
			}
			ofPopMatrix();
			
			//Neck
			auto swingVector_ = getWindingVector(param.fswingDegree);
			ofPoint NeckLeft_, NectRight_;
			NeckLeft_.set(-0.05 * param.fsize, -0.3 * param.fsize);
			NectRight_.set(0.075 * param.fsize, -0.35 * param.fsize);
			
			ofVec2f NeckLeftBegin_ = NeckLeft_ * T_;
			ofVec2f NeckRightBegin_ = NectRight_ * T_;
			ofVec2f NeckLeftEnd_ = ofVec2f(-0.05 * param.fsize, 0.5 * param.fsize);
			ofVec2f NeckRightEnd_ = ofVec2f(0.25 * param.fsize, 0.5 * param.fsize);

			ofVec2f NeckLeftCp1_ = NeckLeftBegin_ + (swingVector_ * 0.3 * param.fsize);
			ofVec2f NeckRightCp1_ = NeckRightBegin_ + (swingVector_ * 0.3 * param.fsize);
			ofVec2f NeckLeftCp2_ = NeckLeftEnd_ + (ofVec2f(0, -1) * 0.3 * param.fsize);
			ofVec2f NeckRightCp2_ = NeckRightEnd_ + (ofVec2f(0, -1) * 0.3 * param.fsize);
	
			ofSetColor(param.linecolor);
			ofSetLineWidth(param.flineWidth);
			ofNoFill();
			ofBezier(	
				NeckLeftBegin_.x, NeckLeftBegin_.y,
				NeckLeftCp1_.x, NeckLeftCp1_.y,
				NeckLeftCp2_.x, NeckLeftCp2_.y,
				NeckLeftEnd_.x, NeckLeftEnd_.y
			);

			ofBezier(	
				NeckRightBegin_.x, NeckRightBegin_.y,
				NeckRightCp1_.x, NeckRightCp1_.y,
				NeckRightCp2_.x, NeckRightCp2_.y,
				NeckRightEnd_.x, NeckRightEnd_.y
			);

			ofLine(NeckLeftEnd_, NeckRightEnd_);			
		}
		endDraw();
	}	

private:
	static void CreateOutline(ofPath& path, const stSwingGiraffeP& param)
	{
		path.clear();
		path.setFillColor(param.fillcolor);
		path.setFilled(param.bFill);
		path.setStrokeWidth(param.flineWidth);
		path.setStrokeColor(param.linecolor);
		
		path.moveTo(-0.05 * param.fsize, -0.3 * param.fsize);
		
		ofVec2f  tongueStart_, tongueEnd_;

		//mouse
		path.bezierTo(
			-0.45 * param.fsize, -0.3 * param.fsize
			,-0.45 * param.fsize, -0.4 * param.fsize
			,-0.05 * param.fsize, -0.5 * param.fsize
		);

		//horn
		path.bezierTo(
			0 * param.fsize, -0.65 * param.fsize
			,0.075 * param.fsize, -0.675 * param.fsize
			,0.075 * param.fsize, -0.5 * param.fsize
		);
		
		//ear
		path.bezierTo(
			0.225 * param.fsize, -0.5 * param.fsize
			,0.225 * param.fsize, -0.35 * param.fsize
			,0.075 * param.fsize, -0.35 * param.fsize
		);
	}
	static ofVec2f getWindingVector(float fWindingDefree)
	{
		ofVec2f result_;
		if(fWindingDefree * 2 > 90)
		{
			result_ = ofVec2f(0, 1).getRotated( 90 );
		}
		else if(fWindingDefree * 2 < -90)
		{
			result_ = ofVec2f(0, 1).getRotated( -90 );
		}
		else
		{
			result_ = ofVec2f(0, 1).getRotated( fWindingDefree * 2 );
		}
		return result_;
	}
};

#endif // !OFX_CT_PAINTING_DESWINGGIRAFFE