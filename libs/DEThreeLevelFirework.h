#ifndef OFX_CT_PAINTING_DETHREELEVELFIREWORK
#define OFX_CT_PAINTING_DETHREELEVELFIREWORK

#include "DEParameter.h"

class DEThreeLevelFirework  : public DEBasic<stThreeLevelFireworkP>
{
public:
	static void draw(stThreeLevelFireworkP& param)
	{
		beginDraw(param);
		{
			ofSetColor(255);
			ofPath levelPath_[3];
			createLevel1(levelPath_[0], param);
			createLevel2(levelPath_[1], param);
			createLevel3(levelPath_[2], param);

			for(int level_ = 0; level_ < 3; level_++)
			{
				float unitDegree_ = 360.0 / param.levelNum[level_];
				float rotateDegree_ = param.levelDegree[level_];
				for(int idx_ = 0; idx_ < param.levelNum[level_]; idx_++)
				{
					ofPushMatrix();
					ofRotateZ(rotateDegree_);
					ofTranslate(0, -param.levelDist[level_]);
					{
						levelPath_[level_].draw();
					}
					ofPopMatrix();
					rotateDegree_ += unitDegree_;
				}
			}
		}
		endDraw();
	}

private:

	static void createLevel1(ofPath& path, const stThreeLevelFireworkP& param)
	{
		float fOutDegree_ = 0.0;
		float fInDegree_ = 36.0;

		float fOutRadius_ = param.fsize * 0.2;
		float fInRadius_ = fOutRadius_ * 0.6;

		path.setFillColor(ofColor(param.levelColor[0], param.levelAlpha[0]));
		path.setStrokeWidth(0);

		path.clear();
		path.moveTo(0, -fOutRadius_);
		for (int idx_ = 0; idx_ < 5; idx_++, fOutDegree_ += 72, fInDegree_ += 72)
		{
			path.lineTo(sin(fOutDegree_ * DEG_TO_RAD) * fOutRadius_, -cos(fOutDegree_ * DEG_TO_RAD) * fOutRadius_);
			path.lineTo(sin(fInDegree_ * DEG_TO_RAD) * fInRadius_, -cos(fInDegree_ * DEG_TO_RAD) * fInRadius_);
		}
		path.lineTo(0, -fOutRadius_);
		path.close();
		
	}

	static void createLevel2(ofPath& path, const stThreeLevelFireworkP& param)
	{
		path.setFillColor(ofColor(param.levelColor[1], param.levelAlpha[1]));
		path.setStrokeWidth(0);
		path.clear();
		path.circle(ofVec2f(0), param.fsize * 0.05);
	}

	static void createLevel3(ofPath& path, const stThreeLevelFireworkP& param)
	{
		path.setFillColor(ofColor(param.levelColor[2], param.levelAlpha[2]));
		path.setStrokeWidth(0);
		path.clear();
		
		path.moveTo(0, 0);
		path.bezierTo(
			-param.fsize * 0.4, -param.fsize * 0.6
			,param.fsize * 0.4, -param.fsize * 0.6
			,0, 0
		);
	}
};

#endif // !OFX_CT_PAINTING_DETHREELEVELFIREWORK
