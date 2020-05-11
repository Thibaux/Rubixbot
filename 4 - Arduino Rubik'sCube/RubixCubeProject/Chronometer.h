#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <Arduino.h>							//library for basic Arduino function 

unsigned long ulTime = 0;		//global Integer use for count the number of timer 1 overflow

class Chronometer {				//Chronometer class

private:						//private Attribute and Method
	uint16_t u16tSeconds = 0;
	uint16_t u16tMilliSeconds = 0;
	uint16_t u16tMicroSeconds = 0;

public:							//public Attribute and Methode
	void InitChronometer() {	//Method for initializes the chronometer
		TCCR1A = 0b00000000;	//COM1A disconnect COM1B disconnect COM1C disconnect WGM11 WGM10 (0,0) normal timer mode
		TCCR1B = 0b00000000;	//ICNC and ICES disconnect WGM13 WGM12 (0,0) normal timer mode CS12 CS11 CS10 clock source disconnect(timer off)
		TCCR1C = 0b00000000;	//FOC1A/B/C useless
		cli();					//disable all interrupts
		TIMSK1 |= (1 << TOIE1);	//set the interrupts on timer 1 overflow (TOIE1 bit)
		sei();					//enable all interrupts
	}

	void StartCount() {			//Method for start the chronometer
		ulTime = 0;				//reset the value of ulTime
		TCNT1H = 0x00;			//reset the value of TCNT1H
		TCNT1L = 0x00;			//reset the value of TCNT1L
		TCCR1B = 0b00000001;	//connect the clock source (timer on) with a clock frequency of 16MHz
	}

	void StopCount() {			//Method for stop the chronometer
		TCCR1B = 0b00000000;	//disconnect the clock source (timer off)
		ulTime = ulTime * 4096 + ((float)((TCNT1H * 1000) + TCNT1L)*0.0625);	//ulTime get the value of timing in µs
	}

	void GetTime(uint16_t &u16ValueSeconds, uint16_t &u16ValueMilliSeconds, uint16_t &u16ValueMicroSeconds) {	//Method for get the value of the chronometer (pointer)
		if (ulTime < 1000) {									//if time < micro second
			u16ValueMicroSeconds = ulTime;
			u16ValueMilliSeconds = 0;
			u16ValueSeconds = 0;
		}
		else if (ulTime < 1000000 && ulTime > 999) {			//if time < second & time > micro second
			u16ValueMilliSeconds = ulTime / 1000;
			u16ValueMicroSeconds = ulTime % 1000;
			u16ValueSeconds = 0;
		}
		else if (ulTime > 999999)								//if time > milli secondUL
		{
			u16ValueSeconds = ulTime / 1000000;
			u16ValueMilliSeconds = (ulTime % 1000000)/1000;
			u16ValueMicroSeconds = ulTime % 1000;
		}
	}
};

ISR(TIMER1_OVF_vect) {				//interrupt for timeur 1 overflow
	ulTime++;			//each overflow increment the the number ulTime
}
#endif // !CHRONOMETER_H
#pragma once
