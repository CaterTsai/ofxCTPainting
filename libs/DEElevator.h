#ifndef OFX_CT_PAINTING_DEELEVATOR
#define OFX_CT_PAINTING_DEELEVATOR

#include "DEParameter.h"

class DEElevator : public DEBasic<stElevatorP>
{
public:
	static void draw(const stElevatorP& param)
	{
		beginDraw(param);
		{
			ofSetLineWidth(param.flineWidth);
			ofSetColor(param.linecolor);
			//ground
			ofLine(ofVec2f(- param.fsize/2, param.fsize/2), ofVec2f(param.fsize/2));

			float fMainWidth_ = param.fsize * 0.6;
			float fDoorHeight_ = param.fsize * param.upPerc;
			float fDoorWidth_ = fMainWidth_/2 * (1 - param.openPerc);

			//main
			ofVec2f mainPos_( - (fMainWidth_ / 2),  param.fsize/2 - fDoorHeight_);
			ofNoFill();
			ofSetColor(param.linecolor);
			ofRect(mainPos_, fMainWidth_, fDoorHeight_);

			//door left
			auto doorPos_ = mainPos_;
			ofFill();
			ofSetColor(param.fillcolor);
			ofRect(doorPos_, fDoorWidth_, fDoorHeight_);
			ofNoFill();
			ofSetColor(param.linecolor);
			ofRect(doorPos_, fDoorWidth_, fDoorHeight_);

			//door right
			doorPos_.x = doorPos_.x + fMainWidth_ - fDoorWidth_;
			ofFill();
			ofSetColor(param.fillcolor);
			ofRect(doorPos_, fDoorWidth_, fDoorHeight_);
			ofNoFill();
			ofSetColor(param.linecolor);
			ofRect(doorPos_, fDoorWidth_, fDoorHeight_);

			//display
			float funitSize_ = fMainWidth_ / (cDISPLAY_NUM + 1);
			float fDisplayHeight_ = param.fsize * 0.03 ;
			ofVec2f startPos_(mainPos_.x, -param.fsize/2 - param.fsize * 0.1);
			
			int iLightIdx_ = static_cast<int>(param.upPerc * (cDISPLAY_NUM - 1) + 0.5);
			
			for(int idx_ = 0; idx_ < cDISPLAY_NUM; idx_++)
			{
				startPos_.x += funitSize_;				
				
				ofFill();
				idx_ != iLightIdx_?ofSetColor(param.fillcolor):ofSetColor(param.linecolor);
				
				ofCircle(startPos_, fDisplayHeight_);

				ofNoFill();
				ofSetColor(param.linecolor);
				ofCircle(startPos_, fDisplayHeight_);
			}
		}
		endDraw();
	}
private:
	static const int cDISPLAY_NUM = 5;
};

#endif // !OFX_CT_PAINTING_DEELEVATOR
