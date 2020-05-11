#ifndef LIGHT_H
#define LIGHT_H

#include <Arduino.h>
#include <EasyNeoPixels.h>
#include <Adafruit_NeoPixel.h>
#define ANIMATIONSPEED 75				//Variable who is the time (in ms) beetween the lightin/light out of each LED (More short is the time more fast the animation is do) 


class Light {

private:
	int iInvBcl;		//Variable use in the second animation for the opposite direction.
	int iRed;			//Variable use for the value of the Red color.
	int iGreen;			//Variable use for the value of the Green color.
	int iBlue;			//Variable use for the value of the Blue color.

public:

	//Function for initialize the NeoCircle LED.
	void Init() {
		setupEasyNeoPixels(36, 37);			//The LED are connected on the pin 36 and 37.
	}



	//Function for change the color of LED automatically.
	void ChangeColor() {
		iBlue = iBlue - iRed;				//We put on iBlue its value minus the value of iRed.
		iRed = iRed + iGreen;				//We put on iRed its value plus the value of iGreen.
		//We make a if loop for change the value of iGreen.
		if (iGreen < 255) {				//If iGreen is lower than 255.	
			iGreen = iGreen + 200;			//We add 200 at iGreen.
		}
		else {							//else.
			iGreen = iGreen - 200;			//We substract 200 at iGreen.
		}
	}



	//Animation with the Led.
	//Write "Tnc" to execute it.
	void CircleAnimation() {
		ChangeColor();		//We call the function who change the color of the LED automatically.
		//We make a For loop who switch on all the LED one after one and use the function who change the color.
		for (int iBcl = 0; iBcl < 24; iBcl++)				//We make a for loop beetween 0 and 24 because we have 24 LED.
		{
			writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
			writeEasyNeoPixel(iBcl, iRed, iGreen, iBlue);		//We write the three color at the value set on the function for ChangeColor.
			delay(ANIMATIONSPEED);								//We wait the time of ANIMATIONSPEED between the lighting of each LED.
		}
		//We make a For loop who switch off all the LED one after one.
		for (int iBcl = 0; iBcl < 24; iBcl++)				//We make a for loop beetween 0 and 24 because we have 24 LED.
		{
			writeEasyNeoPixel(iBcl, LOW);						//The LED iBcl become LOW (Swich off).
			delay(ANIMATIONSPEED);								//We wait the time of ANIMATIONSPEED between the light out of each LED.
		}
	}



	//Second animation with the Led.
	//Write "Tnr" to execute it.
	void RaceAnimation() {
		ChangeColor();			//We call the function who change the color of the LED automatically.
		//We make a For loop who switch on each half of the LED circle one after one and use the function who change the color.
		for (int iBcl = 0; iBcl < 16; iBcl++)
		{
			iInvBcl = iBcl + 12;								//We set the start at the half of the circle.
			if (iBcl < 12) {									//If iBcl is lower as 12 (We make a If because we want to switch off the light at the half).
				writeEasyNeoPixel(iBcl, HIGH);					//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, iRed, iGreen, iBlue);	//We write the three color at the value set on the function ChangeColor.
			}

			writeEasyNeoPixel(iInvBcl, HIGH);					//The LED iBcl become HIGH (Swich On).
			writeEasyNeoPixel(iInvBcl, iRed, iGreen, iBlue);	//We write the three color at the value set on the function ChangeColor.

			writeEasyNeoPixel(iBcl - 4, LOW);					//The LED at iBcl - 4 become LOW (Swich off). 
			writeEasyNeoPixel(iInvBcl - 4, LOW);				//The LED at iBcl - 4 become LOW (Swich off).
			delay(70);				//We wait 0.7 seconds between each passage because we don't to make the animation too fast.
		}
	}



	//Function used to switch on all the LED of the circle.
	//The input parameter is used to choose the color of the LED.
	void TurnOnAll(int iColor) {
		if (iColor == 1)			//If iColor is equal to 1 the color of the LED will be Red.
		{
			for (int iBcl = 0; iBcl < 24; iBcl++)				//We make a For loop for swich on all the LED between 0 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 0);					//We write the first color at 255 and the other at 0 to have red LED.
			}
		}
		else if (iColor == 2)		//If iColor is equal to 2 the color of the LED will be Green.
		{
			for (int iBcl = 0; iBcl < 24; iBcl++)				//We make a For loop for swich on all the LED between 0 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 0, 255, 0);					//We write the second color at 255 and the other at 0 to have green LED.
			}
		}
		else if (iColor == 3)		//If iColor is equal to 3 the color of the LED will be Blue.
		{
			for (int iBcl = 0; iBcl < 24; iBcl++)				//We make a For loop for swich on all the LED between 0 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 0, 0, 255);					//We write the third color at 255 and the other at 0 to have blue LED.
			}
		}
		else if (iColor == 4)		//If iColor is equal to 4 the color of the LED will be Yellow.
		{
			for (int iBcl = 0; iBcl < 24; iBcl++)				//We make a For loop for swich on all the LED between 0 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 255, 0);				//We write the first and second color at 255 and the third at 0 to have yellow LED.
			}
		}
		else if (iColor == 5)		//If iColor is equal to 5 the color of the LED will be Orange.
		{
			for (int iBcl = 0; iBcl < 24; iBcl++)				//We make a For loop for swich on all the LED between 0 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 128, 0);				//We write the first color at 255, the second at 128 and the third at 0 to have Orange LED.
			}
		}
		else if (iColor == 6)		//If iColor is equal to 6 the color of the LED will be Purple.
		{
			for (int iBcl = 0; iBcl < 24; iBcl++)				//We make a For loop for swich on all the LED between 0 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 255);				//We write the first and third color at 255 and the second at 0 to have purple LED.
			}
		}
		else if (iColor == 7)		//If iColor is equal to 7 the color of the LED will be Pink.
		{
			for (int iBcl = 0; iBcl < 24; iBcl++)				//We make a For loop for swich on all the LED between 0 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 128);				//We write the first color at 255, the third at 128 and the second at 0 to have pink LED.
			}
		}
		else						//If iColor is equal to an other value the color of the LED will be White.
		{
			for (int iBcl = 0; iBcl < 24; iBcl++)				//We make a For loop for swich on all the LED between 0 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 255, 255);				//We write the three color at 255 to have white LED.
			}
		}

	}



	//Function for swich off all LED.
	void TurnOffAll() {
		//We make a For loop who swich off all the LED between 0 and 24
		for (int iBcl = 0; iBcl < 24; iBcl++)
		{
			writeEasyNeoPixel(iBcl, LOW);				//The LED iBcl become LOW (Swich Off)
		}
	}



	//Function for swich on the LED on the Front Face (Red face).
	//The input parameter is used to choose the color of the LED.
	void FrontFaceON(int iColor) {
		if (iColor == 1)			//If iColor is equal to 1 the color of the LED will be Red
		{
			for (int iBcl = 0; iBcl < 6; iBcl++)				//We make a For loop who swich on all the LED between 18 and 6. With this LED we illuminate the front face.
			{
				writeEasyNeoPixel(18 + iBcl, HIGH);					//The LED iBcl + 18 become HIGH (Swich On). This line swich on the LED between 18 and 24.
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On). This line swich on the LED between 0 and 6.
				writeEasyNeoPixel(18 + iBcl, 255, 0, 0);			//We write the first color at 255 and the other at 0 to have red LED.
				writeEasyNeoPixel(iBcl, 255, 0, 0);					//We write the first color at 255 and the other at 0 to have red LED.
			}
		}
		else if (iColor == 2)		//If iColor is equal to 2 the color of the LED will be Green.
		{
			for (int iBcl = 0; iBcl < 6; iBcl++)				//We make a For loop who swich on all the LED between 18 and 6. With this LED we illuminate the front face.				
			{
				writeEasyNeoPixel(18 + iBcl, HIGH);					//The LED iBcl + 18 become HIGH (Swich On). This line swich on the LED between 18 and 24.
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On). This line swich on the LED between 0 and 6.
				writeEasyNeoPixel(18 + iBcl, 0, 255, 0);			//We write the second color at 255 and the other at 0 to have green LED.
				writeEasyNeoPixel(iBcl, 0, 255, 0);					//We write the second color at 255 and the other at 0 to have green LED.
			}
		}
		else if (iColor == 3)		//If iColor is equal to 3 the color of the LED will be Blue.
		{
			for (int iBcl = 0; iBcl < 6; iBcl++)				//We make a For loop who swich on all the LED between 18 and 6. With this LED we illuminate the front face.
			{
				writeEasyNeoPixel(18 + iBcl, HIGH);					//The LED iBcl + 18 become HIGH (Swich On). This line swich on the LED between 18 and 24.
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On). This line swich on the LED between 0 and 6.
				writeEasyNeoPixel(18 + iBcl, 0, 0, 255);			//We write the third color at 255 and the other at 0 to have blue LED.
				writeEasyNeoPixel(iBcl, 0, 0, 255);					//We write the third color at 255 and the other at 0 to have blue LED.
			}
		}
		else if (iColor == 4)		//If iColor is equal to 4 the color of the LED will be Yellow.
		{
			for (int iBcl = 0; iBcl < 6; iBcl++)				//We make a For loop who swich on all the LED between 18 and 6. With this LED we illuminate the front face.
			{
				writeEasyNeoPixel(18 + iBcl, HIGH);					//The LED iBcl + 18 become HIGH (Swich On). This line swich on the LED between 18 and 24.
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On). This line swich on the LED between 0 and 6.
				writeEasyNeoPixel(18 + iBcl, 255, 255, 0);			//We write the first and second color at 255 and the third at 0 to have yellow LED.
				writeEasyNeoPixel(iBcl, 255, 255, 0);				//We write the first and second color at 255 and the third at 0 to have yellow LED.
			}
		}
		else if (iColor == 5)		//If iColor is equal to 5 the color of the LED will be Orange.
		{
			for (int iBcl = 0; iBcl < 6; iBcl++)				//We make a For loop who swich on all the LED between 18 and 6. With this LED we illuminate the front face.
			{
				writeEasyNeoPixel(18 + iBcl, HIGH);					//The LED iBcl + 18 become HIGH (Swich On). This line swich on the LED between 18 and 24.
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On). This line swich on the LED between 0 and 6.
				writeEasyNeoPixel(18 + iBcl, 255, 128, 0);			//We write the first color at 255, the second at 128 and the third at 0 to have Orange LED.
				writeEasyNeoPixel(iBcl, 255, 128, 0);				//We write the first color at 255, the second at 128 and the third at 0 to have Orange LED.
			}
		}
		else if (iColor == 6)		//If iColor is equal to 6 the color of the LED will be Purple.
		{
			for (int iBcl = 0; iBcl < 6; iBcl++)				//We make a For loop who swich on all the LED between 18 and 6. With this LED we illuminate the front face.
			{
				writeEasyNeoPixel(18 + iBcl, HIGH);					//The LED iBcl + 18 become HIGH (Swich On). This line swich on the LED between 18 and 24.
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On). This line swich on the LED between 0 and 6.
				writeEasyNeoPixel(18 + iBcl, 255, 0, 255);			//We write the first and third color at 255 and the second at 0 to have purple LED.
				writeEasyNeoPixel(iBcl, 255, 0, 255);				//We write the first and third color at 255 and the second at 0 to have purple LED.
			}
		}
		else if (iColor == 7)		//If iColor is equal to 7 the color of the LED will be Pink.
		{
			for (int iBcl = 0; iBcl < 6; iBcl++)				//We make a For loop who swich on all the LED between 18 and 6. With this LED we illuminate the front face.
			{
				writeEasyNeoPixel(18 + iBcl, HIGH);					//The LED iBcl + 18 become HIGH (Swich On). This line swich on the LED between 18 and 24.
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On). This line swich on the LED between 0 and 6.
				writeEasyNeoPixel(18 + iBcl, 255, 0, 128);			//We write the first color at 255, the third at 128 and the second at 0 to have pink LED.
				writeEasyNeoPixel(iBcl, 255, 0, 128);				//We write the first color at 255, the third at 128 and the second at 0 to have pink LED.
			}
		}
		else						//If iColor is equal to an other value the color of the LED will be White.
		{
			for (int iBcl = 0; iBcl < 6; iBcl++)				//We make a For loop who swich on all the LED between 18 and 6. With this LED we illuminate the front face.
			{
				writeEasyNeoPixel(18 + iBcl, HIGH);					//The LED iBcl + 18 become HIGH (Swich On). This line swich on the LED between 18 and 24.
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On). This line swich on the LED between 0 and 6.
				writeEasyNeoPixel(18 + iBcl, 255, 255, 255);		//We write the three color at 255 to have white LED.
				writeEasyNeoPixel(iBcl, 255, 255, 255);				//We write the three color at 255 to have white LED.
			}
		}
	}



	//Function for swich off the LED on the Front Face (Red face).
	void FrontFaceOFF() {
		//We make a For loop who swich off all the LED between 18 and 6.
		for (int iBcl = 0; iBcl < 12; iBcl++)
		{
			writeEasyNeoPixel(18 + iBcl, LOW);					//The LED iBcl + 18 become LOW (Swich off). This line swich off the LED between 18 and 24.
			writeEasyNeoPixel(iBcl, LOW);						//The LED iBcl become LOW (Swich off). This line swich off the LED between 18 and 24.
		}
	}



	//Function for swich on the LED on the Back Face (Orange face).
	void BackFaceON(int iColor) {
		//We make a For loop who swich on all the LED between 6 and 18.
		if (iColor == 1)			//If iColor is equal to 1 the color of the LED will be Red.
		{
			for (int iBcl = 6; iBcl < 18; iBcl++)				//We make a For loop who swich on all the LED between 6 and 18.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 0);					//We write the first color at 255 and the other at 0 to have red LED.
			}
		}
		else if (iColor == 2)		//If iColor is equal to 2 the color of the LED will be Green.
		{
			for (int iBcl = 6; iBcl < 18; iBcl++)				//We make a For loop who swich on all the LED between 6 and 18.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 0, 255, 0);					//We write the second color at 255 and the other at 0 to have green LED.
			}
		}
		else if (iColor == 3)		//If iColor is equal to 3 the color of the LED will be Blue.
		{
			for (int iBcl = 6; iBcl < 18; iBcl++)				//We make a For loop who swich on all the LED between 6 and 18.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 0, 0, 255);					//We write the third color at 255 and the other at 0 to have blue LED.
			}
		}
		else if (iColor == 4)		//If iColor is equal to 4 the color of the LED will be Yellow.
		{
			for (int iBcl = 6; iBcl < 18; iBcl++)				//We make a For loop who swich on all the LED between 6 and 18.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 255, 0);				//We write the first and second color at 255 and the third at 0 to have yellow LED.
			}
		}
		else if (iColor == 5)		//If iColor is equal to 5 the color of the LED will be Orange.
		{
			for (int iBcl = 6; iBcl < 18; iBcl++)				//We make a For loop who swich on all the LED between 6 and 18.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 128, 0);				//We write the first color at 255, the second at 128 and the third at 0 to have Orange LED.
			}
		}
		else if (iColor == 6)		//If iColor is equal to 6 the color of the LED will be Purple.
		{
			for (int iBcl = 6; iBcl < 18; iBcl++)				//We make a For loop who swich on all the LED between 6 and 18.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 255);				//We write the first and third color at 255 and the second at 0 to have purple LED.
			}
		}
		else if (iColor == 7)		//If iColor is equal to 7 the color of the LED will be Pink.
		{
			for (int iBcl = 6; iBcl < 18; iBcl++)				//We make a For loop who swich on all the LED between 6 and 18.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 128);				//We write the first color at 255, the third at 128 and the second at 0 to have pink LED.
			}
		}
		else						//If iColor is equal to an other value the color of the LED will be White.
		{
			for (int iBcl = 6; iBcl < 18; iBcl++)				//We make a For loop who swich on all the LED between 6 and 18.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 255, 255);				//We write the three color at 255 to have white LED.
			}
		}
	}
	


	//Function for swich off the LED on the Back Face (Orange face).
	void BackFaceOFF() {
		//We make a For loop who swich off all the LED between 6 and 18.
		for (int iBcl = 6; iBcl < 18; iBcl++)
		{
			writeEasyNeoPixel(iBcl, LOW);						//The LED iBcl become LOW (Swich off).
		}
	}



	//Function for swich on the LED on the Left Face (Green face).
	void LeftFaceON(int iColor) {
		if (iColor == 1)			//If iColor is equal to 1 the color of the LED will be Red
		{
			for (int iBcl = 0; iBcl < 12; iBcl++)				//We make a For loop who swich on all the LED between 0 and 12.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 0);					//We write the first color at 255 and the other at 0 to have red LED.
			}
		}
		else if (iColor == 2)		//If iColor is equal to 2 the color of the LED will be Green.
		{
			for (int iBcl = 0; iBcl < 12; iBcl++)				//We make a For loop who swich on all the LED between 0 and 12.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 0, 255, 0);					//We write the second color at 255 and the other at 0 to have green LED.
			}
		}
		else if (iColor == 3)		//If iColor is equal to 3 the color of the LED will be Blue.
		{
			for (int iBcl = 0; iBcl < 12; iBcl++)				//We make a For loop who swich on all the LED between 0 and 12.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 0, 0, 255);					//We write the third color at 255 and the other at 0 to have blue LED.
			}
		}
		else if (iColor == 4)		//If iColor is equal to 4 the color of the LED will be Yellow.
		{
			for (int iBcl = 0; iBcl < 12; iBcl++)				//We make a For loop who swich on all the LED between 0 and 12.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 255, 0);				//We write the first and second color at 255 and the third at 0 to have yellow LED.
			}
		}
		else if (iColor == 5)		//If iColor is equal to 5 the color of the LED will be Orange.
		{
			for (int iBcl = 0; iBcl < 12; iBcl++)				//We make a For loop who swich on all the LED between 0 and 12.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 128, 0);				//We write the first color at 255, the second at 128 and the third at 0 to have Orange LED.
			}
		}
		else if (iColor == 6)		//If iColor is equal to 6 the color of the LED will be Purple.
		{
			for (int iBcl = 0; iBcl < 12; iBcl++)				//We make a For loop who swich on all the LED between 0 and 12.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 255);				//We write the first and third color at 255 and the second at 0 to have purple LED.
			}
		}
		else if (iColor == 7)		//If iColor is equal to 7 the color of the LED will be Pink.
		{
			for (int iBcl = 0; iBcl < 12; iBcl++)				//We make a For loop who swich on all the LED between 0 and 12.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 128);				//We write the first color at 255, the third at 128 and the second at 0 to have pink LED.
			}
		}
		else						//If iColor is equal to an other value the color of the LED will be White.
		{
			for (int iBcl = 0; iBcl < 12; iBcl++)				//We make a For loop who swich on all the LED between 0 and 12.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 255, 255);				//We write the three color at 255 to have white LED.
			}
		}
	}


	//Function for swich off the LED on the Left Face (Green face).
	void LeftFaceOFF() {
		//We make a For loop who swich off all the LED between 0 and 12.
		for (int iBcl = 0; iBcl < 12; iBcl++)
		{
			writeEasyNeoPixel(iBcl, LOW);						//The LED iBcl become LOW (Swich off).
		}
	}



	//Function for swich on and off the LED on the Right Face (Blue face).
	void RightFaceON(int iColor) {
		if (iColor == 1)			//If iColor is equal to 1 the color of the LED will be Red.
		{
			for (int iBcl = 12; iBcl < 24; iBcl++)				//We make a For loop who swich on all the LED between 12 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 0);					//We write the first color at 255 and the other at 0 to have red LED.
			}
		}
		else if (iColor == 2)		//If iColor is equal to 2 the color of the LED will be Green.
		{
			for (int iBcl = 12; iBcl < 24; iBcl++)				//We make a For loop who swich on all the LED between 12 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 0, 255, 0);					//We write the second color at 255 and the other at 0 to have green LED.
			}
		}
		else if (iColor == 3)		//If iColor is equal to 2 the color of the LED will be Blue.
		{
			for (int iBcl = 12; iBcl < 24; iBcl++)				//We make a For loop who swich on all the LED between 12 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 0, 0, 255);					//We write the third color at 255 and the other at 0 to have blue LED.
			}
		}
		else if (iColor == 4)		//If iColor is equal to 2 the color of the LED will be Yellow.
		{
			for (int iBcl = 12; iBcl < 24; iBcl++)				//We make a For loop who swich on all the LED between 12 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 255, 0);				//We write the first and second color at 255 and the third at 0 to have yellow LED.
			}
		}
		else if (iColor == 5)		//If iColor is equal to 2 the color of the LED will be Orange.
		{
			for (int iBcl = 12; iBcl < 24; iBcl++)				//We make a For loop who swich on all the LED between 12 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 128, 0);				//We write the first color at 255, the second at 128 and the third at 0 to have Orange LED.
			}
		}
		else if (iColor == 6)		//If iColor is equal to 2 the color of the LED will be Purple.
		{
			for (int iBcl = 12; iBcl < 24; iBcl++)				//We make a For loop who swich on all the LED between 12 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 255);				//We write the first and third color at 255 and the second at 0 to have purple LED.
			}
		}
		else if (iColor == 7)		//If iColor is equal to 2 the color of the LED will be Pink.
		{
			for (int iBcl = 12; iBcl < 24; iBcl++)				//We make a For loop who swich on all the LED between 12 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 0, 128);				//We write the first color at 255, the third at 128 and the second at 0 to have pink LED.
			}
		}
		else						//If iColor is equal to an other value the color of the LED will be White.
		{
			for (int iBcl = 12; iBcl < 24; iBcl++)				//We make a For loop who swich on all the LED between 12 and 24.
			{
				writeEasyNeoPixel(iBcl, HIGH);						//The LED iBcl become HIGH (Swich On).
				writeEasyNeoPixel(iBcl, 255, 255, 255);				//We write the three color at 255 to have white LED.
			}
		}
	}



	//We make a For loop who swich off all the LED between 12 and 24 (Blue face).
	void RightFaceOFF() {
		//We make a For loop who swich off all the LED between 12 and 24.
		for (int iBcl = 12; iBcl < 24; iBcl++)
		{
			writeEasyNeoPixel(iBcl, LOW);						//The LED iBcl become LOW (Swich off).
		}

	}


};

#endif 
#pragma once
