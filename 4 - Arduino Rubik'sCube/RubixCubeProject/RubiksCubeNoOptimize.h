#ifndef RUBIKSCUBENOOPTIMIZE_H
#define RUBIXSCUBENOOPTIMIZE_H

#include <Arduino.h>

#define White_Step          17
#define White_Direction     16 
#define White_Enable        48
#define Orange_Step         54
#define Orange_Direction    47
#define Orange_Enable       55
#define Yellow_Step         57 
#define Yellow_Direction    56
#define Yellow_Enable       62 
#define Green_Step          23
#define Green_Direction     22
#define Green_Enable        24
#define Blue_Step           26
#define Blue_Direction      25
#define	Blue_Enable         27
#define Red_Step            29
#define Red_Direction       28
#define Red_Enable          39

class RubiksCubeNoOptimize {

private:
	Chronometer myChrono;
	Light myLight;
public:
	void InitRubiksCube() {
		pinMode(White_Step, OUTPUT);
		pinMode(White_Direction, OUTPUT);
		pinMode(White_Enable, OUTPUT);
		pinMode(Orange_Step, OUTPUT);
		pinMode(Orange_Direction, OUTPUT);
		pinMode(Orange_Enable, OUTPUT);
		pinMode(Yellow_Step, OUTPUT);
		pinMode(Yellow_Direction, OUTPUT);
		pinMode(Yellow_Enable, OUTPUT);
		pinMode(Green_Step, OUTPUT);
		pinMode(Green_Direction, OUTPUT);
		pinMode(Green_Enable, OUTPUT);
		pinMode(Blue_Step, OUTPUT);
		pinMode(Blue_Direction, OUTPUT);
		pinMode(Blue_Enable, OUTPUT);
		pinMode(Red_Step, OUTPUT);
		pinMode(Red_Direction, OUTPUT);
		pinMode(Red_Enable, OUTPUT);

		digitalWrite(White_Enable, LOW);
		digitalWrite(Orange_Enable, LOW);
		digitalWrite(Yellow_Enable, LOW);
		digitalWrite(Green_Enable, LOW);
		digitalWrite(Blue_Enable, LOW);
		digitalWrite(Red_Enable, LOW);

		randomSeed(analogRead(0));
		myChrono.InitChronometer();
		Serial.begin(115200);
		myLight.Init();
		myLight.CircleAnimation();
		Scramble();
		Serial.println("EndInit");
	}

	void SetSideWhiteClock() {
		digitalWrite(White_Direction, LOW);
		for (int x = 0; x < 100; x++) {
			digitalWrite(White_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(White_Step, LOW);
			delayMicroseconds(700);
		}
	}
	void SetSideWhiteRevClock() {
		digitalWrite(White_Direction, HIGH);
		for (int x = 0; x < 100; x++) {
			digitalWrite(White_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(White_Step, LOW);
			delayMicroseconds(700);
		}
	}


	void SetSideOrangeClock() {
		digitalWrite(Orange_Direction, LOW);
		for (int x = 0; x < 100; x++) {
			digitalWrite(Orange_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(Orange_Step, LOW);
			delayMicroseconds(700);
		}
	}
	void SetSideOrangeRevClock() {
		digitalWrite(Orange_Direction, HIGH);
		for (int x = 0; x < 100; x++) {
			digitalWrite(Orange_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(Orange_Step, LOW);
			delayMicroseconds(700);
		}
	}


	void SetSideYellowClock() {
		digitalWrite(Yellow_Direction, LOW);
		for (int x = 0; x < 100; x++) {
			digitalWrite(Yellow_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(Yellow_Step, LOW);
			delayMicroseconds(700);
		}
	}
	void SetSideYellowRevClock() {
		digitalWrite(Yellow_Direction, HIGH);
		for (int x = 0; x < 100; x++) {
			digitalWrite(Yellow_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(Yellow_Step, LOW);
			delayMicroseconds(700);
		}
	}


	void SetSideGreenClock() {
		digitalWrite(Green_Direction, LOW);
		for (int x = 0; x < 100; x++) {
			digitalWrite(Green_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(Green_Step, LOW);
			delayMicroseconds(700);
		}
	}
	void SetSideGreenRevClock() {
		digitalWrite(Green_Direction, HIGH);
		for (int x = 0; x < 100; x++) {
			digitalWrite(Green_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(Green_Step, LOW);
			delayMicroseconds(700);
		}
	}


	void SetSideBlueClock() {
		digitalWrite(Blue_Direction, LOW);
		for (int x = 0; x < 100; x++) {
			digitalWrite(Blue_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(Blue_Step, LOW);
			delayMicroseconds(700);
		}
	}
	void SetSideBlueRevClock() {
		digitalWrite(Blue_Direction, HIGH);
		for (int x = 0; x < 100; x++) {
			digitalWrite(Blue_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(Blue_Step, LOW);
			delayMicroseconds(700);
		}
	}


	void SetSideRedClock() {
		digitalWrite(Red_Direction, LOW);
		for (int x = 0; x < 100; x++) {
			digitalWrite(Red_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(Red_Step, LOW);
			delayMicroseconds(700);
		}
	}
	void SetSideRedRevClock() {
		digitalWrite(Red_Direction, HIGH);
		for (int x = 0; x < 100; x++) {
			digitalWrite(Red_Step, HIGH);
			delayMicroseconds(700);
			digitalWrite(Red_Step, LOW);
			delayMicroseconds(700);
		}
	}

	void Scramble() {
		int irandNumber = 0;
		int iNumberUse = 0;
		int iMovement = random(15, 30);					//We said we want a random number between 15 and 30 for iMovement. We scramble the cube whith the number put int iMovement of movement
		for (int iBcl = 0; iBcl < iMovement; iBcl++)
		{

			irandNumber = random(0, 11);			//We said we want a random number between 0 and 11 for irandNumber. We said 12 number because we have 12 movement possible for scramble the cube

			//We make a if loop to don't make the opposite movement
			if (irandNumber == iNumberUse)	//If irandNumber is equal to iNumberUse
			{
				if (irandNumber > 5)
				{
					irandNumber--;				//We make irandNumber - 1;
				}
				else
				{
					irandNumber++;				//We make irandNumber + 1;
				}
			}


			//We make a switch to make the good movement following the random number put in irandNumber
			switch (irandNumber)					//We look the value in irandNumber
			{
			case 0:									//If the value is 0
				SetSideRedClock();			//We turn the red face clockwise
				break;
			case 1:									//If the value is 1
				SetSideOrangeClock();;		//We turn the orange face clockwise

				break;
			case 2:									//If the value is 2
				SetSideGreenClock();;			//We turn the green face clockwise

				break;
			case 3:									//If the value is 3
				SetSideBlueClock();;			//We turn the blue face clockwise
				break;
			case 4:									//If the value is 4
				SetSideWhiteClock();;			//We turn the white face clockwise
				break;
			case 5:									//If the value is 5
				SetSideYellowClock();;		//We turn the yellow face clockwise
				break;
			case 6:									//If the value is 6
				SetSideRedRevClock();;		//We turn the red face counterclockwise
				break;
			case 7:									//If the value is 7
				SetSideOrangeRevClock();;		//We turn the orange face counterclockwise
				break;
			case 8:									//If the value is 8
				SetSideGreenRevClock();;		//We turn the green face counterclockwise
				break;
			case 9:									//If the value is 9
				SetSideBlueRevClock();;		//We turn the blue face counterclockwise
				break;
			case 10:								//If the value is 10
				SetSideWhiteRevClock();;		//We turn the white face counterclockwise
				break;
			case 11:								//If the value is 11
				SetSideYellowRevClock();;		//We turn the yellow face counterclockwise
				break;
			}
			//We make a if loop to remember the opposite movement of the last movement
			if (irandNumber > 5)				//If the last movement is superior as 5
			{
				iNumberUse = irandNumber - 6;	//We write in iNumberUse the value of irandNumber minus 6. We substract 6 at irandNumber because we have 12 value, 2 times 6 movement. So when we substract 6 we have the opposite movement 
			}
			else
			{
				iNumberUse = irandNumber + 6;	//We write in iNumberUse the value of irandNumber plus 6. We add 6 at irandNumber because we have 12 value, 2 times 6 movement. So when we add 6 we have the opposite movement 
			}

			delay(700);
		}
	}

	void Treatment() {
		char cTabByte[50];
		uint8_t ui8tNbByte;
		uint16_t ulS = 0;
		uint16_t ulmS = 0;
		uint16_t uluS = 0;

		for (uint8_t ui8tBcl = 0; ui8tBcl < 50; ui8tBcl++)
		{
			cTabByte[ui8tBcl] = 0;
		}

		if (Serial.available() > 0)
		{
			ui8tNbByte = 0;

			do
			{
				cTabByte[ui8tNbByte] = Serial.read();
				if ('\'' == cTabByte[ui8tNbByte])
				{
					cTabByte[ui8tNbByte] = cTabByte[ui8tNbByte - 1];
					cTabByte[ui8tNbByte - 1] = '\'';
				}
				ui8tNbByte++;
				delay(1);
			} while (Serial.available() > 0);

			if (cTabByte[0] == 'S')
			{
				Scramble();
			}
			else if (cTabByte[0] == 'C')
			{
				myChrono.StartCount();
				myLight.TurnOnAll(1);
				delay(700);
				myLight.TurnOffAll();
				delay(700);
				myLight.BackFaceON(0);
				delay(700);
				myLight.BackFaceOFF();
				delay(700);
				myLight.FrontFaceON(0);
				delay(700);
				myLight.FrontFaceOFF();
				delay(700);
				myLight.RightFaceON(0);
				delay(700);
				myLight.RightFaceOFF();
				delay(700);
				myLight.LeftFaceON(0);
				delay(700);
				myLight.LeftFaceOFF();
				delay(700);

				Serial.println("G");
			}
			else
			{
				for (uint8_t ui8tBcl1 = 0; ui8tBcl1 < ui8tNbByte; ui8tBcl1++)
				{
					switch (cTabByte[ui8tBcl1])
					{
					case 'F':
						SetSideRedClock();
						break;
					case 'B':
						SetSideOrangeClock();
						break;
					case 'L':
						SetSideGreenClock();
						break;
					case 'R':
						SetSideBlueClock();
						break;
					case 'U':
						SetSideWhiteClock();
						break;
					case 'D':
						SetSideYellowClock();
						break;
					case '\'':
						switch (cTabByte[ui8tBcl1 + 1])
						{
						case 'F':
							SetSideRedRevClock();
							break;
						case 'B':
							SetSideOrangeRevClock();
							break;
						case 'L':
							SetSideGreenRevClock();
							break;
						case 'R':
							SetSideBlueRevClock();
							break;
						case 'U':
							SetSideWhiteRevClock();
							break;
						case 'D':
							SetSideYellowRevClock();
							break;
						}
						ui8tBcl1++;
						break;
					}

				}
				myChrono.StopCount();
				myChrono.GetTime(ulS, ulmS, uluS);
				Serial.println(ulS);
				Serial.println(ulmS);
				Serial.println(uluS);
				myLight.RaceAnimation();
			}
		}
	}
};
#endif // !RUBIKSCUBENOOPTIMIZE_H
#pragma once
