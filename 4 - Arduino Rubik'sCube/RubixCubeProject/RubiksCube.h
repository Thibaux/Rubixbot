#ifndef RUBIKSCUBE_H
#define RUBIXSCUBE_H

#include <Arduino.h>								//library for basic Arduino function 
#include "Chronometer.h"							//library for use the chronometer
#include"Light.h"									//library for use the ring led

class RubiksCube {									//RubiksCube optimize class

private:											//private Attribute and Method
	Chronometer myChrono;		//creation of the new private object myChrono
	Light myLight;				//creation of the new private object myLight


public:												//public Attribute and Methode
	int iColour;						//Integer use for choose the color of the LED
	char cTabByte[50];					//Table of char use for data receive by the ATMega UART
	uint8_t ui8tNbByte;					//Integer use for the number of data receive by the ATMega UART

	void InitRubiksCube() {				//Method which initializes the rubikscube

		randomSeed(analogRead(0));		//Initializes the pseudo-random number generator
		myChrono.InitChronometer();		//Initializes the chrono
		Serial.begin(115200);			//Initializes the Serial Communication (UART) at speed of 115200 bit/s
		myLight.Init();					//Initializes the ring-light
		Serial.println("EndInit");		//Write "EndInit" on the Serial, it means that the Rubiks can receive order now
	}

  
	void SetSideWhiteClock() {				//Method for turn the white side (1/4 of the face) in CLOCKWISE SENS
		PORTH &= ~(1 << PH1);			//PH1 set to 0
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTH |= (1 << PH0);		//PH0 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTH &= ~(1 << PH0);		//PH0 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}

	void SetSideWhiteRevClock() {			//Method for turn the white side (1/4 of the face) in NON-CLOCKWISE SENS
		PORTH &= ~(1 << PH1);      //PH1 set to 0
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTH |= (1 << PH0);		//PH0 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTH &= ~(1 << PH0);		//PH0 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}

	void SetSideOrangeClock() {				//Method for turn the orange side (1/4 of the face) in CLOCKWISE SENS
		PORTL &= ~(1 << PL2);			//PL2 set to 0
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTF |= (1 << PF0);		//PF0 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTF &= ~(1 << PF0);		//PF0 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}
	
	void SetSideOrangeRevClock() {			//Method for turn the orange side (1/4 of the face) in NON-CLOCKWISE SENS
		PORTL |= (1 << PL2);			//PL2 set to 1
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTF |= (1 << PF0);		//PF0 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTF &= ~(1 << PF0);		//PF0 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}

	void SetSideYellowClock() {				//Method for turn the yellow side (1/4 of the face) in CLOCKWISE SENS
		PORTF &= ~(1 << PF2);			//PF2 set to 0
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTF |= (1 << PF3);		//PF3 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTF &= ~(1 << PF3);		//PF3 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}
	
	void SetSideYellowRevClock() {			//Method for turn the yellow side (1/4 of the face) in NON-CLOCKWISE SENS
		PORTF |= (1 << PF2);			//PF2 set to 1
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTF |= (1 << PF3);		//PF3 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTF &= ~(1 << PF3);		//PF3 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}

	void SetSideGreenClock() {				//Method for turn the green side (1/4 of the face) in CLOCKWISE SENS
		PORTA &= ~(1 << PA0);			//PA0 set to 0
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTA |= (1 << PA1);		//PA1 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTA &= ~(1 << PA1);		//PA1 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}
	
	void SetSideGreenRevClock() {			//Method for turn the green side (1/4 of the face) in NON-CLOCKWISE SENS
		PORTA |= (1 << PA0);			//PA0 set to 1
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTA |= (1 << PA1);		//PA1 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTA &= ~(1 << PA1);		//PA1 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}

	void SetSideBlueClock() {				//Method for turn the blue side (1/4 of the face) in CLOCKWISE SENS
		PORTA &= ~(1 << PA3);			//PA3 set to 0
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTA |= (1 << PA4);		//PA4 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTA &= ~(1 << PA4);		//PA4 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}
	
	void SetSideBlueRevClock() {			//Method for turn the blue side (1/4 of the face) in NON-CLOCKWISE SENS
		PORTA |= (1 << PA3);			//PA3 set to 1
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTA |= (1 << PA4);		//PA4 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTA &= ~(1 << PA4);		//PA4 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}

	void SetSideRedClock() {				//Method for turn the red side (1/4 of the face) in CLOCKWISE SENS
		PORTA &= ~(1 << PA6);			//PA6 set to 0
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTA |= (1 << PA7);		//PA7 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTA &= ~(1 << PA7);		//PA7 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}
	
	void SetSideRedRevClock() {				//Method for turn the red side (1/4 of the face) in NON-CLOCKWISE SENS
		PORTA |= (1 << PA6);			//PA6 set to 1
		for (int x = 0; x < 100; x++) {	//permit to do 100 motor step (it represents 1/4 of the face)
			PORTA |= (1 << PA7);		//PA7 set to 1
			delayMicroseconds(700);		//delay of 700 �s
			PORTA &= ~(1 << PA7);		//PA7 set to 0
			delayMicroseconds(700);		//delay of 700 �s
		}
	}
 
  void SetSideRedClockAndOrangeClock() {        //Method for turn the red side (1/4 of the face) in CLOCKWISE and orange side (1/4 of the face) in CLOCKWISE
    PORTA &= ~(1 << PA6);      //PA6 set to 0 RED
    PORTL &= ~(1 << PL2);      //PL2 set to 0 ORANGE
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTA |= (1 << PA7);    //PA7 set to 1 RED
      PORTF |= (1 << PF0);    //PF0 set to 1 ORANGE
      delayMicroseconds(700);   //delay of 700 µs
      PORTA &= ~(1 << PA7);   //PA7 set to 0 RED
      PORTF &= ~(1 << PF0);    //PF0 set to 0 ORANGE
      delayMicroseconds(700);   //delay of 700 µs
    }
  }
  
  void SetSideRedRevClockAndOrangeRevClock() {        //Method for turn the red side (1/4 of the face) in NON-CLOCKWISE and orange side (1/4 of the face) in NON-CLOCKWISE
    PORTA |= (1 << PA6);      //PA6 set to 1 RED REV
    PORTL |= (1 << PL2);      //PL2 set to 1 ORANGE REV
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTA |= (1 << PA7);    //PA7 set to 1 RED
      PORTF |= (1 << PF0);    //PF0 set to 1 ORANGE
      delayMicroseconds(700);   //delay of 700 µs
      PORTA &= ~(1 << PA7);   //PA7 set to 0 RED
      PORTF &= ~(1 << PF0);    //PF0 set to 0 ORANGE
      delayMicroseconds(700);   //delay of 700 µs
    }
  }

  void SetSideRedRevClockAndOrangeClock() {        //Method for turn the red side (1/4 of the face) in NON-CLOCKWISE and orange side (1/4 of the face) in CLOCKWISE
    PORTA |= (1 << PA6);      //PA6 set to 1 RED REV
    PORTL &= ~(1 << PL2);     //PL2 set to 0 ORANGE
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTA |= (1 << PA7);    //PA7 set to 1 RED
      PORTF |= (1 << PF0);    //PF0 set to 1 ORANGE
      delayMicroseconds(700);   //delay of 700 µs
      PORTA &= ~(1 << PA7);   //PA7 set to 0 RED
      PORTF &= ~(1 << PF0);    //PF0 set to 0 ORANGE
      delayMicroseconds(700);   //delay of 700 µs
    }
  }
  
  void SetSideRedClockAndOrangeRevClock() {        //Method for turn the red side (1/4 of the face) in CLOCKWISE and orange side (1/4 of the face) in NON-CLOCKWISE
    PORTA &= ~(1 << PA6);      //PA6 set to 0 RED
    PORTL |= (1 << PL2);      //PL2 set to 1 ORANGE REV
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTA |= (1 << PA7);    //PA7 set to 1 RED
      PORTF |= (1 << PF0);    //PF0 set to 1 ORANGE
      delayMicroseconds(700);   //delay of 700 µs
      PORTA &= ~(1 << PA7);   //PA7 set to 0 RED
      PORTF &= ~(1 << PF0);    //PF0 set to 0 ORANGE
      delayMicroseconds(700);   //delay of 700 µs
    }
  }

  void SetSideWhiteClockAndYellowClock() {        //Method for turn the white side (1/4 of the face) in CLOCKWISE and yellow side (1/4 of the face) in CLOCKWISE
    PORTH &= ~(1 << PH1);      //PH1 set to 0 WHITE
    PORTF &= ~(1 << PF2);      //PF2 set to 0 YELLOW
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTH |= (1 << PH0);    //PH0 set to 1 WHITE
      PORTF |= (1 << PF3);    //PF3 set to 1 YELLOW
      delayMicroseconds(700);   //delay of 700 �s
      PORTH &= ~(1 << PH0);   //PH0 set to 0 WHITE
      PORTF &= ~(1 << PF3);    //PF3 set to 0 YELLOW
    }
  }
  void SetSideWhiteRevClockAndYellowRevClock() {        //Method for turn the white side (1/4 of the face) in NON-CLOCKWISE and yellow side (1/4 of the face) in NON-CLOCKWISE
    PORTH |= (1 << PH1);      //PH1 set to 1 WHITE REV
    PORTF |= (1 << PF2);      //PF2 set to 1 YELLOW REV
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTH |= (1 << PH0);    //PH0 set to 1 WHITE
      PORTF |= (1 << PF3);    //PF3 set to 1 YELLOW
      delayMicroseconds(700);   //delay of 700 �s
      PORTH &= ~(1 << PH0);   //PH0 set to 0 WHITE
      PORTF &= ~(1 << PF3);    //PF3 set to 0 YELLOW
      delayMicroseconds(700);   //delay of 700 �s
    }
  }
  void SetSideWhiteRevClockAndYellowClock() {        //Method for turn the white side (1/4 of the face) in NON-CLOCKWISE and yellow side (1/4 of the face) in CLOCKWISE
    PORTH |= (1 << PH1);      //PH1 set to 1 WHITE REV
    PORTF &= ~(1 << PF2);      //PF2 set to 0 YELLOW
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTH |= (1 << PH0);    //PH0 set to 1 WHITE
      PORTF |= (1 << PF3);    //PF3 set to 1 YELLOW
      delayMicroseconds(700);   //delay of 700 �s
      PORTH &= ~(1 << PH0);   //PH0 set to 0 WHITE
      PORTF &= ~(1 << PF3);    //PF3 set to 0 YELLOW
    }
  }
  void SetSideWhiteClockAndYellowRevClock() {        //Method for turn the white side (1/4 of the face) in CLOCKWISE and yellow side (1/4 of the face) in NON-CLOCKWISE
    PORTH &= ~(1 << PH1);      //PH1 set to 0 WHITE
    PORTF |= (1 << PF2);      //PF2 set to 1 YELLOW REV
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTH |= (1 << PH0);    //PH0 set to 1 WHITE
      PORTF |= (1 << PF3);    //PF3 set to 1 YELLOW
      delayMicroseconds(700);   //delay of 700 �s
      PORTH &= ~(1 << PH0);   //PH0 set to 0 WHITE
      PORTF &= ~(1 << PF3);    //PF3 set to 0 YELLOW
    }
  }
  void SetSideBlueClockAndGreenClock() {        //Method for turn the blue side (1/4 of the face) in CLOCKWISE and green side (1/4 of the face) in CLOCKWISE
    PORTA &= ~(1 << PA3);      //PA3 set to 0 BLUE
    PORTA &= ~(1 << PA0);      //PA0 set to 0 GREEN
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTA |= (1 << PA4);    //PA4 set to 1 BLUE
      PORTA |= (1 << PA1);    //PA1 set to 1 GREEN
      delayMicroseconds(700);   //delay of 700 µs
      PORTA &= ~(1 << PA4);   //PA4 set to 0 BLUE
      PORTA &= ~(1 << PA1);   //PA1 set to 0 GREEN
      delayMicroseconds(700);   //delay of 700 µs
    }
  }
  void SetSideBlueRevClockAndGreenRevClock() {        //Method for turn the blue side (1/4 of the face) in NON-CLOCKWISE and green side (1/4 of the face) in NON-CLOCKWISE
    PORTA |= (1 << PA3);      //PA3 set to 1 BLUE REV
    PORTA |= (1 << PA0);      //PA0 set to 1 GREEN REV
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTA |= (1 << PA4);    //PA4 set to 1 BLUE
      PORTA |= (1 << PA1);    //PA1 set to 1 GREEN
      delayMicroseconds(700);   //delay of 700 µs
      PORTA &= ~(1 << PA4);   //PA4 set to 0 BLUE
      PORTA &= ~(1 << PA1);   //PA1 set to 0 GREEN
      delayMicroseconds(700);   //delay of 700 µs
    }
  }
  void SetSideBlueRevClockAndGreenClock() {        //Method for turn the blue side (1/4 of the face) in NON-CLOCKWISE and green side (1/4 of the face) in CLOCKWISE
    PORTA |= (1 << PA3);      //PA3 set to 1 BLUE REV
    PORTA &= ~(1 << PA0);      //PA0 set to 0 GREEN
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTA |= (1 << PA4);    //PA4 set to 1 BLUE
      PORTA |= (1 << PA1);    //PA1 set to 1 GREEN
      delayMicroseconds(700);   //delay of 700 µs
      PORTA &= ~(1 << PA4);   //PA4 set to 0 BLUE
      PORTA &= ~(1 << PA1);   //PA1 set to 0 GREEN
      delayMicroseconds(700);   //delay of 700 µs
    }
  }
  void SetSideBlueClockAndGreenRevClock() {        //Method for turn the blue side (1/4 of the face) in CLOCKWISE and green side (1/4 of the face) in NON-CLOCKWISE
    PORTA &= ~(1 << PA3);      //PA3 set to 0 BLUE
    PORTA |= (1 << PA0);      //PA0 set to 1 GREEN REV
    for (int x = 0; x < 100; x++) { //permit to do 100 motor step (it represents 1/4 of the face)
      PORTA |= (1 << PA4);    //PA4 set to 1 BLUE
      PORTA |= (1 << PA1);    //PA1 set to 1 GREEN
      delayMicroseconds(700);   //delay of 700 µs
      PORTA &= ~(1 << PA4);   //PA4 set to 0 BLUE
      PORTA &= ~(1 << PA1);   //PA1 set to 0 GREEN
      delayMicroseconds(700);   //delay of 700 µs
    }
  }
  


	//The Scramble method is a method who mix the rubik's cube randomly. They make beetween 15 and 30 move.
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



	//The DecodFrame method is a method who call the different function for move the Rubik's cube following the letter receive
  void DecodFrame() {
		//We make a for loop to decod the frame send by Kociemba. 
		for (uint8_t ui8tBcl1 = 0; ui8tBcl1 < ui8tNbByte; ui8tBcl1++)
		{ 
			switch (cTabByte[ui8tBcl1])		//We look at the value of cTabByte[ui8tBcl1].
			{

      
      // if it's a F, it's the front face who is wanted to turn clockwise.
			case 'F':		
      				
        //Check if the next letter in the frame is a rotation on the opposite side
        if(cTabByte[ui8tBcl1 + 1]== 'B'){ 
          
          //Checking if the opposite side will turn in reverse
          if(cTabByte[ui8tBcl1 + 1]== '\''){
            
            //We call the function who turn the red face clockwise and the orange face anti-clockwide. 
            SetSideRedClockAndOrangeRevClock(); 
            
            //We made two turn in one, the second turn was anti-clockwise, so we finally read 2 letter more than a simple turn
            ui8tBcl1= ui8tBcl1+2; 
          }else { 
            
            //We call the function who turn the orange face clockwise and the red face clockwide.
            SetSideRedClockAndOrangeClock();  
            
            //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
            ui8tBcl1++; 
          }
        }else { 
          
          //We call the function who turn the red face clockwise.
          SetSideRedClock();        
        }
				break;
			case 'B':						// if it's a B, it's the back face who is wanted to turn clockwise.
        if(cTabByte[ui8tBcl1 + 1]== 'F'){ // Check if the next letter in the frame is a rotation on the opposite side
          if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
            SetSideRedRevClockAndOrangeClock(); //We call the function who turn the orange face clockwise and the red face anti-clockwide.
            ui8tBcl1= ui8tBcl1+2; //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
          }else { 
            SetSideRedClockAndOrangeClock();  //We call the function who turn the orange face clockwise and the red face clockwide.
            ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
          }
        }else { 
          SetSideOrangeClock();        //We call the function who turn the orange face clockwise.
        }
				break;
			case 'L':						// if it's a L
        if(cTabByte[ui8tBcl1 + 1]== 'R'){ // Check if the next letter in the frame is a rotation on the opposite side
          if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
            SetSideBlueRevClockAndGreenClock(); //We call the function who turn the blue face anti-clockwise and the green face clockwide.
            ui8tBcl1= ui8tBcl1+2;   //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
          }else { 
            SetSideBlueClockAndGreenClock();  //We call the function who turn the blue face clockwise and the green face clockwide.
            ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
          }
        }else { 
          SetSideGreenClock();      //We call the function who turn the green face clockwise.
        }
				break;
			case 'R':						// if it's a R, it's the right face who is wanted to turn clockwise.
        if(cTabByte[ui8tBcl1 + 1]== 'L'){ // Check if the next letter in the frame is a rotation on the opposite side
          if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
            SetSideBlueClockAndGreenRevClock(); //We call the function who turn the blue face clockwise and the green face anti-clockwide.
            ui8tBcl1= ui8tBcl1+2; //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
          }else { 
            SetSideBlueClockAndGreenClock();  //We call the function who turn the blue face clockwise and the green face clockwide.
            ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
          }
        }else { 
          SetSideBlueClock();        //We call the function who turn the blue face clockwise.
        }
				break;
			case 'U':						// if it's a U, it's the up face who is wanted to turn clockwise.
        if(cTabByte[ui8tBcl1 + 1]== 'D'){ //// Check if the next letter in the frame is a rotation on the opposite side
          if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
            SetSideWhiteClockAndYellowRevClock(); //We call the function who turn the white face clockwise and the yellow face anti-clockwide.
            ui8tBcl1= ui8tBcl1+2; //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
          }else { 
            SetSideWhiteClockAndYellowClock();  //We call the function who turn the white face clockwise and the yellow face clockwide.
            ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
          }
        }else { 
          SetSideWhiteClock();     //We call the function who turn the white face clockwise.
        }
				break;
			case 'D':						// if it's a D, it's the down face who is wanted to turn clockwise.
        if(cTabByte[ui8tBcl1 + 1]== 'U'){ // Check if the next letter in the frame is a rotation on the opposite side
          if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
            SetSideWhiteRevClockAndYellowClock(); //We call the function who turn the yellow face clockwise and the white face anti-clockwide.
            ui8tBcl1= ui8tBcl1+2; //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
          }else { 
            SetSideWhiteClockAndYellowClock();  //We call the function who turn the yellow face clockwise and the white face clockwide.
            ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
          }
        }else { 
          SetSideYellowClock();     //We call the function who turn the yellow face clockwise.
        }
				break;
      case '\'':            // if it's a ', we want to turn counterclockwise.
        switch (cTabByte[ui8tBcl1 + 1]) //We look at the value of cTabByte[ui8tBcl1 + 1] who are the next value of the table.
        {
        case 'F':           // if it's a F, it's the front face who is wanted to turn counter clockwise.
          if(cTabByte[ui8tBcl1 + 1]== 'B'){ // Check if the next letter in the frame is a rotation on the opposite side
            if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
              SetSideRedRevClockAndOrangeRevClock();  //We call the function who turn the red face anti-clockwise and the orange face anti-clockwide.
              ui8tBcl1= ui8tBcl1+2;   //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
            }else { 
              SetSideRedRevClockAndOrangeClock(); //We call the function who turn the red face anti-clockwise and the orange face clockwide.
              ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
            }
          }else { 
            SetSideRedRevClock();     //We call the function who turn the red face counter anti-clockwise.
          }
          break;
        case 'B':           // if it's a B, it's the back face who is wanted to turn counter clockwise.
          if(cTabByte[ui8tBcl1 + 1]== 'F'){ // Check if the next letter in the frame is a rotation on the opposite side
            if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
              SetSideRedRevClockAndOrangeRevClock(); //We call the function who turn the red face anti-clockwise and the orange face anti-clockwide.
              ui8tBcl1= ui8tBcl1+2;   //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
            }else { 
              SetSideRedClockAndOrangeRevClock();  //We call the function who turn the red face clockwise and the orange face anti-clockwide.
              ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
            }
          }else { 
            SetSideOrangeRevClock();    //We call the function who turn the orange face counter anti-clockwise.
          }
          break;
        case 'L':           // if it's a L, it's the left face who is wanted to turn counter clockwise.
          if(cTabByte[ui8tBcl1 + 1]== 'R'){ // Check if the next letter in the frame is a rotation on the opposite side
            if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
              SetSideBlueRevClockAndGreenRevClock();  //We call the function who turn the blue face anti-clockwise and the green face anti-clockwide.
              ui8tBcl1= ui8tBcl1+2;   //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
            }else { 
              SetSideBlueClockAndGreenRevClock(); //We call the function who turn the blue face clockwise and the green face anti-clockwide.
              ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
            }
          }else { 
            SetSideGreenRevClock();     //We call the function who turn the green face counter anti-clockwise.
          }
          break;
        case 'R':           // if it's a R, it's the right face who is wanted to turn counter clockwise.
          if(cTabByte[ui8tBcl1 + 1]== 'L'){ // Check if the next letter in the frame is a rotation on the opposite side
            if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
              SetSideBlueRevClockAndGreenRevClock();  //We call the function who turn the blue face anti-clockwise and the green face anti-clockwide.
              ui8tBcl1= ui8tBcl1+2;   //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
            }else { 
              SetSideBlueRevClockAndGreenClock(); //We call the function who turn the blue face anti-clockwise and the green face clockwide.
              ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
            }
          }else { 
            SetSideBlueRevClock();      //We call the function who turn the blue face counter anti-clockwise.
          }
          break;
        case 'U':           // if it's a U, it's the up face who is wanted to turn counter clockwise.
          if(cTabByte[ui8tBcl1 + 1]== 'D'){ // Check if the next letter in the frame is a rotation on the opposite side
            if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
              SetSideWhiteRevClockAndYellowRevClock();  //We call the function who turn the white face anti-clockwise and the yellow face anti-clockwide.
              ui8tBcl1= ui8tBcl1+2;   //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
            }else { 
              SetSideWhiteRevClockAndYellowClock(); //We call the function who turn the white face anti-clockwise and the yellow face clockwide.
              ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
            }
          }else { 
            SetSideWhiteRevClock();     //We call the function who turn the white face counter anti-clockwise.
          }
          break;
        case 'D':           // if it's a D, it's the down face who is wanted to turn counter clockwise.
          if(cTabByte[ui8tBcl1 + 1]== 'U'){ // Check if the next letter in the frame is a rotation on the opposite side
            if(cTabByte[ui8tBcl1 + 1]== '\''){  //Check the sens of rotation of the opposite face
              SetSideWhiteRevClockAndYellowRevClock();  //We call the function who turn the white face anti-clockwise and the yellow face anti-clockwide.
              ui8tBcl1= ui8tBcl1+2;   //We made two turn in one, the second turn was in anti-clockwise, so we finally read 2 letter more than a simple turn
            }else { 
              SetSideWhiteClockAndYellowRevClock(); //We call the function who turn the white face clockwise and the yellow face anti-clockwide.
            ui8tBcl1++; //We made two turn in one, the second turn was in clockwise, so we finally reade 1 letter more than a simple turn.
            }
          }else { 
            SetSideYellowRevClock();      //We call the function who turn the yellow face counter anti-clockwise.
          }
          break;
        }
        ui8tBcl1++;     //We add 1 at ui8tBcl1 because we have read the value at ui8tBcl1 + 1 and we don't want to read them a second time.
        break;
			  }
		  }
	  }
  



	//The treatmentRubik method is a method who make the action following the letter receive.
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
				DecodFrame();		//We call the method DecodFrame.
			}
		}
	}
	
};
#endif // !RUBIKSCUBE_H
#pragma once
