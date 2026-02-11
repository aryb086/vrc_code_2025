#include "robot.h"

void intake_front_reverse(){
	intake_motor_front.move(-127);
}

void intake_front(){
	intake_motor_front.move(127);
}

void intake_front_stop(){
	intake_motor_front.move(0);
}

void intake_back(){
	intake_motor_back.move(127);
}

void intake_back_stop(){
	intake_motor_back.move(0);
}

void matchloaderOut(){
	matchloader.set_value(HIGH);
} 

void matchloaderIn(){
	matchloader.set_value(LOW);
} 

void wingOut(){
	wing.set_value(HIGH);
} 

void wingIn(){
	wing.set_value(LOW);
} 
