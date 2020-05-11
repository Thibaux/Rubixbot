#ifndef RUBIKSCUBENOOPTIMIZE_H
#define RUBIXSCUBENOOPTIMIZE_H

#include <Arduino.h>								//library for basic Arduino function 
#include "Chronometer.h"							//library for use the chronometer
#include"Light.h"									//library for use the ring led

#define White_Step          17	//White Step match with the digital pin 17
#define White_Direction     16	//White Direction match with the digital pin 16
#define White_Enable        48	//White Enable match with the digital pin 48
#define Orange_Step         54	//Orange Step match with the digital pin 54
#define Orange_Direction    47	//Orange Direction match with the digital pin 47
#define Orange_Enable       55	//Orange Enable match with the digital pin 55
#define Yellow_Step         57	//Yellow Step match with the digital pin 57
#define Yellow_Direction    56	//Yellow Direction match with the digital pin 56
#define Yellow_Enable       62  //Yellow Enable match with the digital pin 62
#define Green_Step          23	//Green Step match with the digital pin 23
#define Green_Direction     22	//Green Direction match with the digital pin 22
#define Green_Enable        24	//Green Enable match with the digital pin 24
#define Blue_Step           26	//Blue Step match with the digital pin 26
#define Blue_Direction      25	//Blue Direction match with the digital pin 25
#define	Blue_Enable         27	//Blue Enable match with the digital pin 27
#define Red_Step            29	//Red Step match with the digital pin 29
#define Red_Direction       28	//Red Direction match with the digital pin 28
#define Red_Enable          39	//Red Enable match with the digital pin 39

class RubiksCubeNoOptimize {				//RubiksCube NoOptimize class

private:											//private Attribute and Method
	Chronometer myChrono;		//creation of the new private object myChrono
	Light myLight;				//creation of the new private object myLight

public:											//public Attribute and Methode

	int iColour;						//Integer use for choose the color of the LED
	char cTabByte[50];					//Table of char use for data receive by the ATMega UART
	uint8_t ui8tNbByte;					//Integer use for the number of data receive by the ATMega UART

	void InitRubiksCube() {

		/*
			Pin for module driver A4988 set as OUTPUT
		*/
		pinMode(White_Step, OUTPUT);			//White_Step pin set as OUTPUT
		pinMode(White_Direction, OUTPUT);		//White_Direction pin set as OUTPUT
		pinMode(White_Enable, OUTPUT);			//White_Enable pin set as OUTPUT
		pinMode(Orange_Step, OUTPUT);			//Orange_Step pin set as OUTPUT
		pinMode(Orange_Direction, OUTPUT);		//Orange_Direction pin set as OUTPUT
		pinMode(Orange_Enable, OUTPUT);			//Orange_Enable pin set as OUTPUT
		pinMode(Yellow_Step, OUTPUT);			//Yellow_Step pin set as OUTPUT
		pinMode(Yellow_Direction, OUTPUT);		//Yellow_Direction pin set as OUTPUT
		pinMode(Yellow_Enable, OUTPUT);			//Yellow_Enable pin set as OUTPUT
		pinMode(Green_Step, OUTPUT);			//Green_Step pin set as OUTPUT
		pinMode(Green_Direction, OUTPUT);		//Green_Direction pin set as OUTPUT
		pinMode(Green_Enable, OUTPUT);			//Green_Enable pin set as OUTPUT
		pinMode(Blue_Step, OUTPUT);				//Blue_Step pin set as OUTPUT
		pinMode(Blue_Direction, OUTPUT);		//Blue_Direction pin set as OUTPUT
		pinMode(Blue_Enable, OUTPUT);			//Blue_Enable pin set as OUTPUT
		pinMode(Red_Step, OUTPUT);				//Red_Step pin set as OUTPUT
		pinMode(Red_Direction, OUTPUT);			//Red_Direction pin set as OUTPUT
		pinMode(Red_Enable, OUTPUT);			//Red_Enable pin set as OUTPUT

		/*
			Enable Pin for module driver A4988 set to 0 (ENABLE)
		*/
		digitalWrite(White_Enable, LOW);	//White_Enable pin set to 0
		digitalWrite(Orange_Enable, LOW);	//Orange_Enable pin set to 0
		digitalWrite(Yellow_Enable, LOW);	//Yellow_Enable pin set to 0
		digitalWrite(Green_Enable, LOW);	//Green_Enable pin set to 0
		digitalWrite(Blue_Enable, LOW);		//Blue_Enable pin set to 0
		digitalWrite(Red_Enable, LOW);		//Red_Enable pin set to 0
	}

	void SetSideWhiteClock() {						//Method for turn the white side (1/4 of the face) in CLOCKWISE SENS
		digitalWrite(White_Direction, LOW);		//White_Direction set to 0
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(White_Step, HIGH);		//White_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(White_Step, LOW);		//White_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}
	void SetSideWhiteRevClock() {					//Method for turn the white side (1/4 of the face) in NON-CLOCKWISE SENS
		digitalWrite(White_Direction, HIGH);	//White_Direction set to 1
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(White_Step, HIGH);		//White_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(White_Step, LOW);		//White_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}


	void SetSideOrangeClock() {						//Method for turn the orange side (1/4 of the face) in CLOCKWISE SENS
		digitalWrite(Orange_Direction, LOW);	//Orange_Direction set to 0
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(Orange_Step, HIGH);	//Orange_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(Orange_Step, LOW);		//Orange_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}
	void SetSideOrangeRevClock() {					//Method for turn the orange side (1/4 of the face) in NON-CLOCKWISE SENS
		digitalWrite(Orange_Direction, HIGH);	//Orange_Direction set to 1
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(Orange_Step, HIGH);	//Orange_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(Orange_Step, LOW);		//Orange_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}


	void SetSideYellowClock() {						//Method for turn the yellow side (1/4 of the face) in CLOCKWISE SENS
		digitalWrite(Yellow_Direction, LOW);	//Yellow_Direction set to 0
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(Yellow_Step, HIGH);	//Yellow_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(Yellow_Step, LOW);		//Yellow_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}
	void SetSideYellowRevClock() {					//Method for turn the yellow side (1/4 of the face) in NON-CLOCKWISE SENS
		digitalWrite(Yellow_Direction, HIGH);	//Yellow_Direction set to 1
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(Yellow_Step, HIGH);	//Yellow_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(Yellow_Step, LOW);		//Yellow_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}


	void SetSideGreenClock() {						//Method for turn the green side (1/4 of the face) in CLOCKWISE SENS
		digitalWrite(Green_Direction, LOW);		//Green_Direction set to 0
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(Green_Step, HIGH);		//Green_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(Green_Step, LOW);		//Green_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}
	void SetSideGreenRevClock() {					//Method for turn the green side (1/4 of the face) in NON-CLOCKWISE SENS
		digitalWrite(Green_Direction, HIGH);	//Green_Direction set to 1
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(Green_Step, HIGH);		//Green_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(Green_Step, LOW);		//Green_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}


	void SetSideBlueClock() {						//Method for turn the blue side (1/4 of the face) in CLOCKWISE SENS
		digitalWrite(Blue_Direction, LOW);		//Blue_Direction set to 0
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(Blue_Step, HIGH);		//Blue_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(Blue_Step, LOW);		//Blue_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}
	void SetSideBlueRevClock() {					//Method for turn the blue side (1/4 of the face) in NON-CLOCKWISE SENS
		digitalWrite(Blue_Direction, HIGH);		//Blue_Direction set to 1
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(Blue_Step, HIGH);		//Blue_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(Blue_Step, LOW);		//Blue_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}


	void SetSideRedClock() {						//Method for turn the red side (1/4 of the face) in CLOCKWISE SENS
		digitalWrite(Red_Direction, LOW);		//Red_Direction set to 0
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(Red_Step, HIGH);		//Red_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(Red_Step, LOW);		//Red_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}
	void SetSideRedRevClock() {						//Method for turn the red side (1/4 of the face) in NON-CLOCKWISE SENS
		digitalWrite(Red_Direction, HIGH);		//Red_Direction set to 1
		for (int x = 0; x < 100; x++) {			//permit to do 100 motor step (it represents 1/4 of the face)
			digitalWrite(Red_Step, HIGH);		//Red_Step set to 1
			delayMicroseconds(700);				//delay of 700 탎
			digitalWrite(Red_Step, LOW);		//Red_Step set to 0
			delayMicroseconds(700);				//delay of 700 탎
		}
	}

	//The Scramble function is a function who mix the rubik's cube randomly. They make beetween 15 and 30 move.
	//To use it we have to write S.
	void Scramble() {
		int irandNumber = 0;				//Variable used to memorize the random value who is used to choose the face and the direction of movement.
		int iNumberUse = 0;					//Variable used to memorize the opposite of the last movement.

		int iMovement = random(15, 30);					//We said we want a random number between 15 and 30 for iMovement. We scramble the cube whith this number of movement.

		//We make a for loop between 0 and the number of movement. We use it to decide the face and the direction of movement.
		for (int iBcl = 0; iBcl < iMovement; iBcl++)
		{

			irandNumber = random(0, 11);			//We said we want a random number between 0 and 11 for irandNumber. We said 12 number because we have 12 movement possible for scramble the cube.

			//We make a if loop to don't make the opposite movement.
			if (irandNumber == iNumberUse)	//If irandNumber is equal to iNumberUse.
			{
				if (irandNumber > 5)		//If the last movement was counter clockwise, irandNumber is greater than to 5.
				{
					irandNumber--;				//We make irandNumber - 1.
				}
				else						//If the last movement was clockwise, irandNumber is lower or equal to 5.
				{
					irandNumber++;				//We make irandNumber + 1.
				}
			}

			//We make a switch to make the good movement following the random number put in irandNumber.
			switch (irandNumber)			//We look the value in irandNumber.
			{
			case 0:							//If the value is 0.
				SetSideRedClock();				//We turn the red face clockwise.
				break;
			case 1:							//If the value is 1.
				SetSideOrangeClock();			//We turn the orange face clockwise.
				break;
			case 2:							//If the value is 2.
				SetSideGreenClock();			//We turn the green face clockwise.
				break;
			case 3:							//If the value is 3.
				SetSideBlueClock();				//We turn the blue face clockwise.
				break;
			case 4:							//If the value is 4.
				SetSideWhiteClock();			//We turn the white face clockwise.
				break;
			case 5:							//If the value is 5.
				SetSideYellowClock();			//We turn the yellow face clockwise.
				break;
			case 6:							//If the value is 6.
				SetSideRedRevClock();			//We turn the red face counter clockwise.
				break;
			case 7:							//If the value is 7.
				SetSideOrangeRevClock();		//We turn the orange face counter clockwise.
				break;
			case 8:							//If the value is 8.
				SetSideGreenRevClock();			//We turn the green face counter clockwise.
				break;
			case 9:							//If the value is 9.
				SetSideBlueRevClock();			//We turn the blue face counter clockwise.
				break;
			case 10:						//If the value is 10.
				SetSideWhiteRevClock();			//We turn the white face counter clockwise.
				break;
			case 11:						//If the value is 11.
				SetSideYellowRevClock();		//We turn the yellow face counter clockwise.
				break;
			}



			//We make a if loop to remember the opposite movement of the last movement.
			if (irandNumber > 5)				//If the last movement is greater than 5.
			{
				iNumberUse = irandNumber - 6;		//We write in iNumberUse the value of irandNumber minus 6. We substract 6 at irandNumber because we have 12 value, 2 times 6 movement. So when we substract 6 we have the opposite movement.
			}
			else								//else (movement lower or equal to 5).
			{
				iNumberUse = irandNumber + 6;		//We write in iNumberUse the value of irandNumber plus 6. We add 6 at irandNumber because we have 12 value, 2 times 6 movement. So when we add 6 we have the opposite movement.
			}

			delay(700);		//we wait 0.7 seconds between each movement because the motor was not very precise so we have to check if each movement was good.
		}
	}



	//The DecodFrame function is a function who call the different function for move the Rubik's cube following the letter receive
	void DecodFrame() {
		//We make a for loop to decod the frame send by Kociemba. 
		for (uint8_t ui8tBcl1 = 0; ui8tBcl1 < ui8tNbByte; ui8tBcl1++)
		{
			switch (cTabByte[ui8tBcl1])		//We look at the value of cTabByte[ui8tBcl1].
			{
			case 'F':						// if it's a F, it's the front face who is wanted to turn clockwise.
				SetSideRedClock();				//We call the function who turn the red face clockwise.
				break;
			case 'B':						// if it's a B, it's the back face who is wanted to turn clockwise.
				SetSideOrangeClock();			//We call the function who turn the orange face clockwise.
				break;
			case 'L':						// if it's a L, it's the left face who is wanted to turn clockwise.
				SetSideGreenClock();			//We call the function who turn the green face clockwise.
				break;
			case 'R':						// if it's a R, it's the right face who is wanted to turn clockwise.
				SetSideBlueClock();				//We call the function who turn the blue face clockwise.
				break;
			case 'U':						// if it's a U, it's the up face who is wanted to turn clockwise.
				SetSideWhiteClock();			//We call the function who turn the white face clockwise.
				break;
			case 'D':						// if it's a D, it's the down face who is wanted to turn clockwise.
				SetSideYellowClock();			//We call the function who turn the yellow face clockwise.
				break;
			case '\'':						// if it's a ', we want to turn counterclockwise.
				switch (cTabByte[ui8tBcl1 + 1]) //We look at the value of cTabByte[ui8tBcl1 + 1] who are the next value of the table.
				{
				case 'F':						// if it's a F, it's the front face who is wanted to turn counter clockwise.
					SetSideRedRevClock();			//We call the function who turn the red face counter clockwise.
					break;
				case 'B':						// if it's a B, it's the back face who is wanted to turn counter clockwise.
					SetSideOrangeRevClock();		//We call the function who turn the orange face counter clockwise.
					break;
				case 'L':						// if it's a L, it's the left face who is wanted to turn counter clockwise.
					SetSideGreenRevClock();			//We call the function who turn the green face counter clockwise.
					break;
				case 'R':						// if it's a R, it's the right face who is wanted to turn counter clockwise.
					SetSideBlueRevClock();			//We call the function who turn the blue face counter clockwise.
					break;
				case 'U':						// if it's a U, it's the up face who is wanted to turn counter clockwise.
					SetSideWhiteRevClock();			//We call the function who turn the white face counter clockwise.
					break;
				case 'D':						// if it's a D, it's the down face who is wanted to turn counter clockwise.
					SetSideYellowRevClock();			//We call the function who turn the yellow face counter clockwise.
					break;
				}
				ui8tBcl1++;			//We add 1 at ui8tBcl1 because we have read the value at ui8tBcl1 + 1 and we don't want to read them a second time.
				break;
			}
		}
	}



	//The treatmentRubik function is a function who make the action following the letter receive.
	void TreatmentRubik() {
		uint16_t ulS = 0;		//Integer for Second of timeur in the chrono object
		uint16_t ulmS = 0;		//Integer for Milli-Second of timeur in the chrono object
		uint16_t uluS = 0;		//Integer for Micro-Second of timeur in the chrono object


		for (uint8_t ui8tBcl = 0; ui8tBcl < 50; ui8tBcl++) //for which permit to clear the buffer of Serial Communication
		{
			cTabByte[ui8tBcl] = 0;
		}

		//This if loop is executed when a letter is receive. 
		if (Serial.available() > 0)
		{
			ui8tNbByte = 0;

			//We read the frame send at the atmega until that the serial available return at 0.
			do
			{
				cTabByte[ui8tNbByte] = Serial.read();					//We read what it send at the atmega and we write it in cTabByte[ui8tNbByte].

				//If we see a ' we put the ' before the letter. It used to read the letter after the ' and don't read 2 times the letter.
				if ('\'' == cTabByte[ui8tNbByte])
				{
					cTabByte[ui8tNbByte] = cTabByte[ui8tNbByte - 1];	//cTabByte[ui8tNbByte] take the value of cTabByte[ui8tNbByte - 1].
					cTabByte[ui8tNbByte - 1] = '\'';					//And we put the ' in cTabByte[ui8tNbByte - 1]. 
				}
				ui8tNbByte++;		//We add 1 at ui8tNbByte to write the next value read in an other memory compartement of the table.
				delay(1);			//We wait 1 milliseconds to don't make the loop too fast.
			} while (Serial.available() > 0);		//As long as serial available was greater than 0 we make the do.

			//We make a if loop when the variable receive is a 'S'. So we scramble the cube.
			if (cTabByte[0] == 'S')			//If cTabByte[0] is a S.
			{
				Scramble();						//We call the function who scramble the cube.
			}

			//We make a if loop when the variable receive is a 'C'. So we start the timer.
			else if (cTabByte[0] == 'C')	//If cTabByte[0] is a C.
			{
				myChrono.StartCount();			//We call the function who start the timer.
				Serial.println("START TIMER");
			}

			//We make a if loop when the variable receive is a 'c'. So we stop the timer and display the time.
			else if (cTabByte[0] == 'c')	//If cTabByte[0] is a c.
			{
				myChrono.StopCount();				//We call the function who stop the timer
				myChrono.GetTime(ulS, ulmS, uluS);	//We call the function who put the time in seconds, milliseconds and microseconds
				Serial.println(ulS);				//We print the number of second used
				Serial.println(ulmS);				//We print the number of millisecond used
				Serial.println(uluS);				//We print the number of microsecond used
				Serial.println("STOP TIMER");
			}

			//We make a if loop when the variable receive is a 'T'. So we can control the LED.
			else if (cTabByte[0] == 'T')//If cTabByte[0] is a C.
			{
				switch (cTabByte[1])		//We look at the value of cTabByte[1].
				{
				case 'a':						// if it's a a, We want to switch on all the LED.
					myLight.TurnOnAll(iColour);			//We call the function who switch on all the LED.
					break;
				case 'f':						// if it's a f, We want to switch on the LED on the front face.
					myLight.FrontFaceON(iColour);			//We call the function who switch on the LED on the red face.
					break;
				case 'b':						// if it's a b, We want to switch on the LED on the back face.
					myLight.BackFaceON(iColour);			//We call the function who switch on the LED on the orange face.
					break;
				case 'l':						// if it's a l, We want to switch on the LED on the left face. 
					myLight.LeftFaceON(iColour);			//We call the function who switch on the LED on the green face.
					break;
				case 'r':						// if it's a r, We want to switch on the LED on the right face.
					myLight.RightFaceON(iColour);			//We call the function who switch on the LED on the blue face.
					break;
				case '\'':						// if it's a ', we want to switch off the LED.
					switch (cTabByte[2])			//We look at the value of cTabByte[2] who are the next value of the table.
					{
					case 'a':							// if it's a a, We want to switch off all the LED. 
						myLight.TurnOffAll();				//We call the function who switch off all the LED.
						break;
					case 'f':							// if it's a f, We want to switch off the LED on the front face. 
						myLight.FrontFaceOFF();				//We call the function who switch off the LED on the red face.
						break;
					case 'b':							// if it's a b, We want to switch off the LED on the back face. 
						myLight.BackFaceOFF();				//We call the function who switch off the LED on the orange face.
						break;
					case 'l':							// if it's a l, We want to switch off the LED on the left face. 
						myLight.LeftFaceOFF();				//We call the function who switch off the LED on the green face.
						break;
					case 'r':							// if it's a r, We want to switch off the LED on the right face.
						myLight.RightFaceOFF();				//We call the function who switch off the LED on the blue face.
						break;
					}
					break;
				case 'k':						// if it's a k, we want to choose the color.
					switch (cTabByte[2])			//We look at the value of cTabByte[2] who are the next value of the table.
					{
					case 'W':							// if it's a W, We want white LED.
						iColour = 0;						//We set icolour at 0 to have white LED.
						break;
					case 'R':							// if it's a R, We want red LED.
						iColour = 1;						//We set icolour at 1 to have red LED.
						break;
					case 'G':							// if it's a G, We want green LED.
						iColour = 2;						//We set icolour at 2 to have green LED.
						break;
					case 'B':							// if it's a B, We want blue LED.
						iColour = 3;						//We set icolour at 3 to have blue LED.
						break;
					case 'Y':							// if it's a Y, We want to yellow LED.
						iColour = 4;						//We set icolour at 4 to have yellow LED.
						break;
					case 'O':							// if it's a O, We want orange LED.
						iColour = 5;						//We set icolour at 5 to have orange LED.
						break;
					case 'U':							// if it's a U, We want purple LED.
						iColour = 6;						//We set icolour at 6 to have purple LED.
						break;
					case 'P':							// if it's a P, We want pink LED.
						iColour = 7;						//We set icolour at 7 to have pink LED.
						break;
					}
					break;
				case 'n':						// if it's a n, we want to choose the animation.
					switch (cTabByte[2])			//We look at the value of cTabByte[2] who are the next value of the table.
					{
					case 'c':							// if it's a c, We want the circle animation.
						myLight.CircleAnimation();			//We call the function who make the circle animation.
						break;
					case 'r':							// if it's a r, We want the race animation.
						myLight.RaceAnimation();				//We call the function who make the race animation.
						break;
					}
				}
			}

			//We make a if loop when the variable receive is different than C,S or T. In this case we make the movement ask.
			else
			{
				DecodFrame();		//We call the function DecodFrame.
			}
		}
	}
};
#endif // !RUBIKSCUBENOOPTIMIZE_H
#pragma once
