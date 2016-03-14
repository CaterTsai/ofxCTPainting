#ifndef OFX_CT_PAINTING_DEOPENGIRAFFE
#define OFX_CT_PAINTING_DEOPENGIRAFFE

#include "DEParameter.h"

class DEOpenGiraffe  : public DEBasic<stOpenGiraffeP>
{
public:
	static void draw(const stOpenGiraffeP& param)
	{
		beginDraw(param);
		{
			ofPath bottom_, top_;
			CreateTop(top_, param);
			CreateBottom(bottom_, param);
			
			ofVec2f openAxis_;
			openAxis_.set(0.075 * param.fsize, -0.35 * param.fsize);		
			openAxis_ = openAxis_.getInterpolated(ofVec2f(0.25 * param.fsize, 0.5 * param.fsize), 0.55);
			
			ofPushMatrix();
			ofTranslate(openAxis_);
			ofRotateZ(param.openPerc * 120.0);
			ofTranslate(-openAxis_);
			{
				top_.draw();

				ofSetColor(param.linecolor, param.falpha);
			
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
			
				//spots
				ofVec2f LinePos_;
				LinePos_.set(0.075 * param.fsize, -0.35 * param.fsize);
				auto spotsStart1_ = LinePos_.getInterpolated(ofVec2f(0.25 * param.fsize, 0.5 * param.fsize), 0.2);
				auto spotsEnd1_ = LinePos_.getInterpolated(ofVec2f(0.25 * param.fsize, 0.5 * param.fsize), 0.5);
		
				ofBezier(	
					spotsStart1_.x, spotsStart1_.y
					,spotsStart1_.x - (0.1 * param.fsize), spotsStart1_.y
					,spotsEnd1_.x - (0.1 * param.fsize), spotsEnd1_.y
					,spotsEnd1_.x, spotsEnd1_.y
				);
			}
			ofPopMatrix();
			
			//Bottom
			bottom_.draw();
			
			ofVec2f LinePos_;
			LinePos_.set(-0.05 * param.fsize, -0.3 * param.fsize);
			auto spotsStart2_ = LinePos_.getInterpolated(ofVec2f(-0.05 * param.fsize, 0.5 * param.fsize), 0.6);
			auto spotsEnd2_ = LinePos_.getInterpolated(ofVec2f(-0.05 * param.fsize, 0.5 * param.fsize), 0.9);

			ofBezier(	
					spotsStart2_.x, spotsStart2_.y
					,spotsStart2_.x + (0.1 * param.fsize), spotsStart2_.y
					,spotsEnd2_.x + (0.1 * param.fsize), spotsEnd2_.y
					,spotsEnd2_.x, spotsEnd2_.y
			);

			ofFill();
			ofSetColor(255);
			ofCircle(openAxis_, param.fsize * 0.05);

			ofNoFill();
			ofSetColor(0);
			ofCircle(openAxis_, param.fsize * 0.02);
			
			ofSetColor(0);
			ofCircle(openAxis_, param.fsize * 0.05);
			
		}
		endDraw();
	}

private:
	static void CreateTop(ofPath& path, const stOpenGiraffeP& param)
	{
		path.clear();
		path.setFillColor(ofColor(param.fillcolor, param.falpha));
		path.setFilled(param.bFill);
		path.setStrokeWidth(param.flineWidth);
		path.setStrokeColor(ofColor(param.linecolor, param.falpha));
		
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

		//neck
		ofVec2f LinePos_;
		
		//Right
		LinePos_.set(0.075 * param.fsize, -0.35 * param.fsize);
		path.lineTo(LinePos_.getInterpolated(ofVec2f(0.25 * param.fsize, 0.5 * param.fsize), 0.55));
		
		//Left
		LinePos_.set(-0.05 * param.fsize, -0.3 * param.fsize);		
		path.lineTo(LinePos_.getInterpolated(ofVec2f(-0.05 * param.fsize, 0.5 * param.fsize), 0.55));

		path.close();
	}

	static void CreateBottom(ofPath& path, const stOpenGiraffeP& param)
	{
		path.clear();
		path.setFillColor(ofColor(param.fillcolor, param.falpha));
		path.setFilled(param.bFill);
		path.setStrokeWidth(param.flineWidth);
		path.setStrokeColor(ofColor(param.linecolor, param.falpha));

		ofVec2f LinePos_;
		LinePos_.set(-0.05 * param.fsize, -0.3 * param.fsize);		
		path.moveTo(LinePos_.getInterpolated(ofVec2f(-0.05 * param.fsize, 0.5 * param.fsize), 0.55));

		LinePos_.set(0.075 * param.fsize, -0.35 * param.fsize);
		path.lineTo(LinePos_.getInterpolated(ofVec2f(0.25 * param.fsize, 0.5 * param.fsize), 0.55));
		
		path.lineTo(0.25 * param.fsize, 0.5 * param.fsize);
		path.lineTo(-0.05 * param.fsize, 0.5 * param.fsize);
		path.close();
		
	}
};

#endif // !OFX_CT_PAINTING_DEOPENGIRAFFE