/*
    Name:					RubixCubeProject.ino
    Created:				30/01/2019 10:18:15
    Author:					DESKTOP-3MJIBAF\enzob
	Last Modification :		20/02/2019
*/

#include"RubiksCube.h"

RubiksCube myRubiks;					//creation of the object myRubiks

#define LED_PIN    36
 
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 24
 
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup(){
  myRubiks.InitRubiksCube();
}

void loop(){
  myRubiks.TreatmentRubik();
}
