#ifndef OFX_CT_PAINTING_DEGIRAFFE
#define OFX_CT_PAINTING_DEGIRAFFE

#include "DEParameter.h"

class DEGiraffe  : public DEBasic<stGiraffeP>
{
public:
	static void draw(const stGiraffeP& param)
	{
		ofPath outline_;
		CreateOutline(outline_, param);
		beginDraw(param);
		{
			ofSetColor(255);
			outline_.draw();

			ofSetColor(param.linecolor, param.falpha);
			ofFill();
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

			//ofBezier(	
			//	Tstart_.x, Tstart_.y
			//	,Tstart_.x - (0.075 * param.fsize), Tstart_.y + (0.05 * param.fsize)
			//	,Tend_.x - (0.075 * param.fsize), Tend_.y + (0.05 * param.fsize)
			//	,Tend_.x, Tend_.y
			//);
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
		
			LinePos_.set(-0.05 * param.fsize, -0.3 * param.fsize);
			auto spotsStart2_ = LinePos_.getInterpolated(ofVec2f(-0.05 * param.fsize, 0.5 * param.fsize), 0.6);
			auto spotsEnd2_ = LinePos_.getInterpolated(ofVec2f(-0.05 * param.fsize, 0.5 * param.fsize), 0.9);

			ofBezier(	
				spotsStart1_.x, spotsStart1_.y
				,spotsStart1_.x - (0.1 * param.fsize), spotsStart1_.y
				,spotsEnd1_.x - (0.1 * param.fsize), spotsEnd1_.y
				,spotsEnd1_.x, spotsEnd1_.y
			);

			ofBezier(	
				spotsStart2_.x, spotsStart2_.y
				,spotsStart2_.x + (0.1 * param.fsize), spotsStart2_.y
				,spotsEnd2_.x + (0.1 * param.fsize), spotsEnd2_.y
				,spotsEnd2_.x, spotsEnd2_.y
			);
		}
		endDraw();
	}

private:
	static void CreateOutline(ofPath& path, const stGiraffeP& param)
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
		path.lineTo(0.25 * param.fsize, 0.5 * param.fsize);
		path.lineTo(-0.05 * param.fsize, 0.5 * param.fsize);
		path.close();
	}
};

#endif // !OFX_CT_PAINTING_DEGIRAFFE