ofxCTPainting
====================

Description
-----------
An openframeworks add-on to painting the giraffe.

How To
-----------

step.1 Import the add-on : #include "ofxCTPainting.h"

step.2 Declare the element : stGiraffeP _giraffe;

step.3 Drawing on the right place : ofxCTPainting::GetInstance()->draw(_giraffe);

step.4 Giraffe!!

There have 16 difference type of element as follow:
	stGiraffeP
	stSwingGiraffeP
	stLongGiraffeP
	stOpenGiraffeP
	stThreeLevelFireworkP
	stElevatorP
	stBoxP
	stJetpackP
	stPipeP
	stFireFlowerP
	stStarP
	stCactusP
	stPokeBallP
	stPACManP
	stGhostP
	stExclamationMarkP

Those elements inherit the same class stBasicP that include the position, rotate, scale... etc.
And each element can be controlled by its own parameter.
You can check out the example to get more detail.
	
Example
-------
The example is test on visual studio 2012 with openframework 0.8.1.

![ofxCTPainting example](https://dl.dropboxusercontent.com/u/23887512/GitHub/ofxCTPainting.gif)
