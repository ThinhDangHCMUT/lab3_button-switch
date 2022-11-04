/*
 * fsm_automatic.h
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */


#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status_1){

		case INIT:
			clearAllLights(0);
			status_1 = NORMAL_RED;
			setTimer1(red_time*100); //setTimer1(500)
			time_1 = red_time;
			break;

		case NORMAL_RED:
			//TODO
			//countDownTime();
			red(0);
			setLED(0, time_1);
			countDownTime();
			if(timer1_flag == 1){
				status_1 = NORMAL_GREEN;
				setTimer1(green_time*100);
				time_1 = green_time;
			}
			//CHANGE STATE IF BUTTON 1 IS PRESSED
			if(is_button_pressed(0) == 1){
				status_1 = -1;
				status_2 = -1;
				status_3 = INIT;
			}

			break;

		case NORMAL_GREEN:
			//TODO
			//countDownTime();
			green(0);
			setLED(0, time_1);
			countDownTime();
			if(timer1_flag == 1){
				status_1 = NORMAL_YELLOW;
				setTimer1(yellow_time*100);
				time_1 = yellow_time;
			}
			//CHANGE STATE IF BUTTON 1 IS PRESSED
			if(is_button_pressed(0) == 1){
				status_1 = -1;
				status_2 = -1;
				status_3 = INIT;
			}

			break;

		case NORMAL_YELLOW:
			//countDownTime();
			yellow(0);
			setLED(0, time_1);
			countDownTime();
			if(timer1_flag == 1){
				status_1 = NORMAL_RED;
				setTimer1(red_time*100);
				time_1 = red_time;
			}

			if(is_button_pressed(0) == 1){
				status_1 = -1;
				status_2 = -1;
				status_3 = INIT;
			}

			break;

		default:
			break;
	}

}
