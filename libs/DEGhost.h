#ifndef OFX_CT_PAINTING_DEGHOST
#define OFX_CT_PAINTING_DEGHOST

#include "DEParameter.h"

class DEGhost : public DEBasic<stGhostP>
{
public:
	static void draw(const stGhostP& param)
	{
		beginDraw(param);
		{
			float fbase_ = param.fsize / 14.0;
			ofPath outline_, mouth_;
			createOutline(outline_, param);

			//Draw
			outline_.draw();
						
			if(param.scared)
			{
				//eyes
				ofFill();
				ofSetColor(ofColor(param.fillcolor, param.falpha));
				ofEllipse(fbase_ * -2.0, fbase_ * -1.0, fbase_ * 2.0, fbase_ * 3.0);
				ofEllipse(fbase_ * 2.0, fbase_ * -1.0, fbase_ * 2.0, fbase_ * 3.0);

				//Mouth
				mouth_.setFilled(false);
				mouth_.setStrokeWidth(fbase_ * 0.5);
				mouth_.setStrokeColor(ofColor(param.fillcolor, param.falpha));
				mouth_.moveTo(fbase_ * -6.0, fbase_ * 3.5);
				mouth_.curveTo(fbase_ * -6.0, fbase_ * 3.5);
				mouth_.curveTo(fbase_ * -4.0, fbase_ * 2.5);
				mouth_.curveTo(fbase_ * -2.0, fbase_ * 3.5);
				mouth_.curveTo(fbase_ * 0.0, fbase_ * 2.5);
				mouth_.curveTo(fbase_ * 2.0, fbase_ * 3.5);
				mouth_.curveTo(fbase_ * 4.0, fbase_ * 2.5);
				mouth_.curveTo(fbase_ * 6.0, fbase_ * 3.5);
				mouth_.curveTo(fbase_ * 6.0, fbase_ * 3.5);

				mouth_.draw();

			}
			else
			{
				//eyes
				ofSetLineWidth(param.flineWidth);
				ofNoFill();
				ofSetColor(ofColor(param.linecolor, param.falpha));
				ofEllipse(fbase_ * -4.0, fbase_ * -1.0, fbase_ * 4.0, fbase_ * 5.0);
				ofEllipse(fbase_ * 2.0, fbase_ * -1.0, fbase_ * 4.0, fbase_ * 5.0);

				ofFill();
				ofCircle(fbase_ * -5.0, fbase_ * -1.0, fbase_ * 1.0);
				ofCircle(fbase_ * 1.0, fbase_ * -1.0, fbase_ * 1.0);
			}
			
		}
		endDraw();
	}

private:
	static void createOutline(ofPath& path, const stGhostP& param)
	{
		bool type_ = (ofGetFrameNum() / 10 % 2) == 0;
		path.clear();

		if(param.scared)
		{
			path.setFillColor(ofColor(param.linecolor, param.falpha));
			path.setStrokeColor(ofColor(param.fillcolor, param.falpha));
		}
		else
		{
			path.setFillColor(ofColor(param.fillcolor, param.falpha));
			path.setStrokeColor(ofColor(param.linecolor, param.falpha));
		}
		path.setFilled(true);		
		path.setStrokeWidth(param.flineWidth);
		

		float fbase_ = param.fsize / 14.0;

		path.moveTo(fbase_ * -7.0, fbase_ * -1.0);
		path.arc(0, 0, fbase_ * 7.0, fbase_ * 7.0, 180, 0);

		if(type_)
		{
			path.lineTo(fbase_ * 7.0, fbase_ * 7.0);
			path.curveTo(fbase_ * 7.0, fbase_ * 7.0);
			path.curveTo(fbase_ * 6.0, fbase_ * 7.0);
			path.curveTo(fbase_ * 4, fbase_ * 5.0);
			path.curveTo(fbase_ * 2.0, fbase_ * 7.0);
			path.curveTo(fbase_ * 0.0, fbase_ * 5.0);
			path.curveTo(fbase_ * -2.0, fbase_ * 7.0);
			path.curveTo(fbase_ * -4, fbase_ * 5.0);
			path.curveTo(fbase_ * -6.0, fbase_ * 7.0);
			path.curveTo(fbase_ * -7.0, fbase_ * 7.0);
			path.curveTo(fbase_ * -7.0, fbase_ * 7.0);
		}
		else
		{
			path.lineTo(fbase_ * 7.0, fbase_ * 5.0);
			path.curveTo(fbase_ * 7.0, fbase_ * 5.0);
			path.curveTo(fbase_ * 5.0, fbase_ * 7.0);
			path.curveTo(fbase_ * 3.0, fbase_ * 5.0);
			path.curveTo(fbase_ * 1.0, fbase_ * 7.0);
			path.curveTo(fbase_ * -1.0, fbase_ * 7.0);
			path.curveTo(fbase_ * -3.0, fbase_ * 5.0);
			path.curveTo(fbase_ * -5.0, fbase_ * 7.0);
			path.curveTo(fbase_ * -7.0, fbase_ * 5.0);
			path.curveTo(fbase_ * -7.0, fbase_ * 5.0);
		}
		path.close();
	}
};
#endif // !OFX_CT_PAINTING_DEGHOST
