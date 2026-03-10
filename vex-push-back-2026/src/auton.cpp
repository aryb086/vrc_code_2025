#include "auton.h"
#include "pros/adi.h"
#include "robot.h"
#include "util.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"
ASSET(curve1_txt);

void skills_state(void){
	chassis.setPose(-48, 6, 270);

	//score preload in mid goal
	
	chassis.moveToPoint(-9, 6, 1000, {.forwards = false, .maxSpeed = 100}, false);
	chassis.turnToHeading(315, 1000);
	midgoal2.set_value(LOW);
	midgoal.set_value(HIGH);
	pros::delay(200);
	intake_front();
	pros::delay(1000);

	//first 4 for left long goal
	midgoal2.set_value(LOW);
	midgoal.set_value(LOW);
	//chassis.moveToPoint(-19, 17, 1000, {.maxSpeed = 100}, false);
	chassis.moveToPoint(-44, 44, 2000, {.maxSpeed = 80}, true);
	chassis.turnToHeading(270, 800);
	chassis.moveToPoint(-22, 44, 1000, {.forwards = false, .maxSpeed = 60}, false);
	midgoal2.set_value(HIGH);
	midgoal.set_value(LOW);
	matchloaderOut();
	pros::delay(1700);

	//first matchloader
	midgoal2.set_value(LOW);
	midgoal.set_value(LOW);
	chassis.moveToPoint(-64, 43.5, 1200, {.forwards = true, .maxSpeed = 60}, false);
	chassis.moveToPoint(-65, 43.5, 1500, {.forwards = true, .maxSpeed = 40}, true);
	pros::delay(2000);

	//scoring first 6 in long goal
	chassis.moveToPoint(-45, 44, 1000, {.forwards = false, .maxSpeed = 60}, false);
	matchloaderIn();
	chassis.turnToHeading(20, 700);
	chassis.follow(curve1_txt, 10, 10000);
	// chassis.moveToPoint(-39, 58, 1000, {.forwards = true, .maxSpeed = 100}, false);
	// chassis.turnToHeading(90, 700);
	// chassis.moveToPoint(0, 58, 2500, {.forwards = true, .maxSpeed = 100}, false);
	// chassis.moveToPoint(32, 58, 2500, {.forwards = true, .maxSpeed = 100}, false);
	// chassis.turnToHeading(0, 700);
	chassis.moveToPoint(32, 50, 1000, {.forwards = false, .maxSpeed = 100}, false);
	chassis.turnToHeading(90, 900);
	chassis.moveToPoint(18, 50, 1000, {.forwards = false, .maxSpeed = 80}, false);
	midgoal2.set_value(HIGH);
	midgoal.set_value(LOW);
	matchloaderOut();
	pros::delay(2000);

	//second matchloader
	midgoal2.set_value(LOW);
	midgoal.set_value(LOW);
	chassis.moveToPoint(64, 48.5, 1200, {.forwards = true, .maxSpeed = 60}, false);
	chassis.moveToPoint(65, 48.5, 1500, {.forwards = true, .maxSpeed = 40}, true);
	pros::delay(2000);
}

void auton_skills2(void) {
	// 1. Record the start time
    uint32_t startTime = pros::millis();

	wing.set_value(HIGH);

	auton_first_matchloading();
    auton_soring_position();
    auton_soring_position2();
	auton_midgoal_position();
	auton_third_matchloading();
	auton_third_scoring_position();
	auton_fourth_matchloading();
	auton_park();

	// 2. Record the end time
    uint32_t endTime = pros::millis();
	// 3. Calculate the duration
    uint32_t timeTaken = endTime - startTime;

    // 4. Print to the Brain screen or Terminal for debugging
    pros::lcd::print(4, "Autonomous Time: %ld ms", timeTaken);
}

void auton_first_matchloading(){
	//getting to first matchloading station 
	chassis.moveToPoint(47,48.5, 1000, {.maxSpeed = 90}, false);
	chassis.turnToPoint(67,47, 1000, {.forwards = true, .maxSpeed = 100}, false);
	matchloaderOut(); 
	pros::delay(300);
	intake_front();
	chassis.moveToPoint(66,47, 1000, {.maxSpeed = 60}, false);
	pros::delay(1200);
	chassis.moveToPoint(40,60, 1000, {.forwards = false, .maxSpeed = 80}, false);
	chassis.turnToPoint(65, 60, 1000, {.forwards = true, .maxSpeed = 80}, false);
	// matchloaderIn(); 
}

void auton_soring_position(){
	chassis.moveToPoint(-30,73, 2500, {.forwards = false, .maxSpeed = 90}, false);
	matchloaderIn(); 
	pros::delay(200);
	chassis.moveToPoint(-10,57, 2000, {.forwards = false, .maxSpeed = 60}, false);
	midgoal2.set_value(HIGH);
	matchloaderOut();
	pros::delay(3000);
}

void auton_soring_position2(){
	//second matchloader
	midgoal2.set_value(LOW);
	chassis.moveToPoint(-77, 62, 2200, {.forwards = true, .maxSpeed = 40}, false);
	pros::delay(1200);

	//scoring second 6
	chassis.moveToPoint(-10,62, 1500, {.forwards = false, .maxSpeed = 50}, false);
	midgoal2.set_value(HIGH);
	pros::delay(2500);
	midgoal2.set_value(LOW);
	// matchloaderIn();
}

void auton_midgoal_position(){
	//chassis.moveToPoint(-40,50, 1000, {.forwards = true, .maxSpeed = 80}, false);
	chassis.turnToPoint(-30,0, 1000, {.forwards = true, .maxSpeed = 60}, false);
	pros::delay(200);
	matchloaderIn();
	pros::delay(400);


	chassis.moveToPoint(-30,48, 800, {.forwards = true, .maxSpeed = 60}, false);
	pros::delay(200);

	chassis.moveToPoint(-28,35, 1300, {.forwards = true, .maxSpeed = 60}, false);
	pros::delay(200);
	chassis.moveToPoint(-37,45, 900, {.forwards = false, .maxSpeed = 80}, false);
	intake_front_stop();

	chassis.turnToPoint(0,0, 1000, {.forwards = false, .maxSpeed = 80}, false);
	chassis.moveToPoint(-18,31, 1500, {.forwards = false, .maxSpeed = 50}, false);
	chassis.moveToPoint(-16,28, 700, {.forwards = false, .maxSpeed = 90}, false);

	midgoal.set_value(HIGH);
	intake_front();
	pros::delay(1000);
}


void auton_third_matchloading(){
	chassis.moveToPoint(-40,38, 1200, {.forwards = true, .maxSpeed = 80}, false);
	midgoal.set_value(LOW);
	intake_front_stop();
	chassis.turnToPoint(-50,-32, 1000, {.forwards = true, .maxSpeed = 80}, false);
	chassis.moveToPoint(-50,-32, 2200, {.forwards = true, .maxSpeed = 80}, false);
	pros::delay(400);
	chassis.turnToPoint(-67,-25, 1000, {.forwards = true, .maxSpeed = 80}, false);
	matchloaderOut();
	intake_front();
	pros::delay(300);
	chassis.moveToPoint(-80,-25, 1300, {.forwards = true, .maxSpeed = 80}, false);
	pros::delay(1500);
}

void auton_third_scoring_position(){
	chassis.moveToPoint(-70,-39, 800, {.forwards = false, .maxSpeed = 80}, false);
	chassis.moveToPoint(-46,-52, 1500, {.forwards = false, .maxSpeed = 60}, false);
	matchloaderIn();
	pros::delay(300);
	chassis.turnToPoint(25,-58.5, 1000, {.forwards = false, .maxSpeed = 80}, false);
	pros::delay(300);
	chassis.moveToPoint(25,-58.5, 3000, {.forwards = false, .maxSpeed = 90}, false);
	chassis.moveToPoint(10,-50, 2000, {.forwards = false, .maxSpeed = 60}, false);
	midgoal2.set_value(HIGH);

	matchloaderOut();
	pros::delay(2200);
	midgoal2.set_value(LOW);
}
void auton_fourth_matchloading(){
	chassis.moveToPoint(70,-50, 2000, {.forwards = true, .maxSpeed = 80}, false);
	pros::delay(1500);
	chassis.moveToPoint(10,-50, 2000, {.forwards = false, .maxSpeed = 60}, false);
	midgoal2.set_value(HIGH);
	matchloaderIn();	
	pros::delay(2000);
	chassis.moveToPoint(40,-50, 1000, {.forwards = true, .maxSpeed = 80}, false);


}

void auton_park(){
	chassis.turnToPoint(41,-66, 600, {.forwards = false, .maxSpeed = 127}, false);
	chassis.moveToPoint(73,10, 2000, {.forwards = true, .maxSpeed = 127}, false);
	chassis.moveToPoint(60,25, 500, {.forwards = true, .maxSpeed = 127}, false);
	chassis.moveToPoint(50,45, 500, {.forwards = true, .maxSpeed = 100}, false);

	matchloaderOut();
	matchloaderIn();
	// intake_front_stop();

}


void auton_skills(void) {
	// // set position to x:0, y:0, heading:0
    // chassis.setPose(0, 0, 0);
    // // turn to face heading 90 with a very long timeout
    // chassis.turnToHeading(90, 100000);

	//skills
	chassis.setPose(47, 17, 0);
	pros::delay(500);

	//getting to first matchloading station 
	chassis.moveToPoint(47,47, 1000, {.maxSpeed = 100}, false);
	chassis.turnToPoint(67,47, 1000, {.forwards = true, .maxSpeed = 100}, false);
	matchloaderOut(); 
	pros::delay(600);
	intake_front();
	chassis.moveToPoint(65,46, 1700, {.maxSpeed = 40}, false);
	pros::delay(1500);
	chassis.moveToPoint(47,52, 3000, {.forwards = false, .maxSpeed = 80}, false);
	matchloaderIn(); 

	//moving to scoring position
	chassis.moveToPoint(-40,60, 5000, {.forwards = false, .maxSpeed = 80}, false);
	chassis.turnToPoint(-40, -20, 1200, {.forwards = false, .maxSpeed = 80}, false);
	chassis.moveToPoint(-33,55, 1000, {.forwards = false, .maxSpeed = 80}, false);
	chassis.moveToPoint(-35,50, 1000, {.forwards = false, .maxSpeed = 60}, false);
	chassis.turnToPoint(20,55, 1200, {.forwards = false, .maxSpeed = 100}, false);

	//scoring first 7
	midgoal2.set_value(HIGH);
	chassis.moveToPoint(-10,50, 2000, {.forwards = false, .maxSpeed = 40}, false);
	matchloaderOut();
	pros::delay(2000);

	//second matchloader
	midgoal2.set_value(LOW);
	chassis.moveToPoint(-70,55, 1500, {.forwards = true, .maxSpeed = 60}, false);
	chassis.moveToPoint(-70, 55, 1000, {.forwards = true, .maxSpeed = 40}, false);
	pros::delay(1500);

	//scoring second 6
	chassis.moveToPoint(-10,55, 1000, {.forwards = false, .maxSpeed = 50}, false);
	midgoal2.set_value(HIGH);
	pros::delay(3000);
	midgoal2.set_value(LOW);
	matchloaderIn();
	// move forward and push back so that balls gets pushed in
	chassis.moveToPoint(-30,50, 1000, {.forwards = true, .maxSpeed = 60}, false);
	chassis.moveToPoint(-10,50, 1000, {.forwards = false, .maxSpeed = 50}, false);
	pros::delay(100);


	//get 1 ball for mid goal
	chassis.moveToPoint(-30,50, 1000, {.forwards = true, .maxSpeed = 60}, false);
	chassis.turnToPoint(-30,0, 1000, {.forwards = true, .maxSpeed = 60}, false);
	chassis.moveToPoint(-30,48, 1000, {.forwards = true, .maxSpeed = 80}, false);
	pros::delay(1000); // picking up two blue and two red balls
	intake_front_stop();
	chassis.turnToPoint(-3,3, 1000, {.forwards = false, .maxSpeed = 80}, false);
	chassis.moveToPoint(-3,3, 1000, {.forwards = false, .maxSpeed = 60}, false);
	intake_front();
	pros::delay(1000);
	chassis.moveToPoint(-3,3, 800, {.forwards = false, .maxSpeed = 40}, false);
	midgoal2.set_value(LOW);
	midgoal.set_value(HIGH);

	//third matchloader
	chassis.moveToPoint(-30,30, 1000, {.forwards = true, .maxSpeed = 80}, false);
	chassis.turnToPoint(-50,-50, 1000, {.forwards = true, .maxSpeed = 100}, false);
	chassis.moveToPoint(-50,-50, 2500, {.forwards = true, .maxSpeed = 80}, false);
	chassis.turnToPoint(-67,-50, 1000, {.forwards = true, .maxSpeed = 100}, false);
	matchloaderOut();
	chassis.moveToPoint(-67,-50, 1500, {.forwards = true, .maxSpeed = 40}, false);
	pros::delay(1000);

	//moving to second scoring position
	chassis.moveToPoint(-43,-54, 2500, {.forwards = true, .maxSpeed = 80}, false);






	// chassis.moveToPoint(34,54, 2000, {.maxSpeed = 80}, false);2s
	// chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);	
	// chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);
	// // chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);

	// //collecting balls from first matchloading station
	// pros::delay(1700);
	// // intake_front_stop();


	// //moving away from first matchloading station & scoring
	// chassis.moveToPoint(50,44, 1200, {.forwards = false, .maxSpeed = 80}, false);
	// // intake_front();
	// pros::delay(200);
	// matchloaderIn();
	// chassis.turnToPoint(29,62, 1000, {.maxSpeed = 80}, false);
	// chassis.moveToPoint(29,62, 1600, {.forwards = true, .maxSpeed = 60}, false);		
	// chassis.turnToPoint(-47,58, 1000, {.maxSpeed = 80}, false);	
	// intake_front_stop();

	// chassis.moveToPoint(-60,58, 3000, {.forwards = true, .maxSpeed = 90}, false);
	// pros::delay(200);
	// // chassis.turnToPoint(-70,65, 500, {.maxSpeed = 80}, false);
	// chassis.moveToPoint(-35,47, 1000, {.forwards = false, .maxSpeed = 50}, false);
	// pros::delay(200);
	// chassis.moveToPoint(-23,47, 1000, {.forwards = false, .maxSpeed = 50}, false);
	// intake_motor_front.move(-127);
	// pros::delay(150);
	// intake_front();
	// intake_back();
	// matchloaderOut();
	// chassis.moveToPoint(-17,47, 1000, {.forwards = false, .maxSpeed = 50}, false);
	// pros::delay(5000);


	// chassis.moveToPoint(-70,47, 1500, {.maxSpeed = 50}, false);
	// intake_back_stop();
	// // intake_front_stop();


	// chassis.moveToPoint(-62,47, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(-68,47, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(-62,47, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(-68,47, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(-62,47, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(-68,47, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(-62,47, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(-68,47, 400, {.maxSpeed = 127}, false);	
	// chassis.moveToPoint(-62,47, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(-68,47, 400, {.maxSpeed = 127}, false);
	// // chassis.moveToPoint(-63,47, 400, {.maxSpeed = 127}, false);
	
	// chassis.moveToPoint(-40,47, 1000, {.forwards = false, .maxSpeed = 40}, false);	

	// intake_motor_front.move(-127);
	// pros::delay(150);
	// intake_front();

	// chassis.moveToPoint(-20,47, 2500, {.forwards = false, .maxSpeed = 40}, false);	
	// matchloaderIn();
	// intake_back();
	// pros::delay(5000);

	// chassis.moveToPoint(-50,47, 700, {.forwards = true, .maxSpeed = 60}, false);
	// chassis.turnToPoint(-25,25, 1000, {.maxSpeed = 80}, false);
	// chassis.moveToPoint(-25,25, 1500, {.forwards = true, .maxSpeed = 80}, false);
	// chassis.moveToPoint(83,37, 2000, {.forwards = true, .maxSpeed = 80}, false);
	// pros::delay(400);
	// chassis.turnToPoint(80,-7, 1000, {.maxSpeed = 80}, false);

	// chassis.moveToPoint(80,-7, 1500, {.forwards = true, .maxSpeed = 127}, false);
}
void auton_left(void) {
	// Your autonomous code for the left side
	// 1. Record the start time
    uint32_t startTime = pros::millis();
	wing.set_value(HIGH);

	chassis.setPose(43, -17, 270);


	//scoring midgoal
	intake_front();
	chassis.moveToPoint(17,-30, 2100, {.maxSpeed = 100}, false);
	chassis.turnToPoint(0,0, 1000, {.forwards = false, .maxSpeed = 80}, false);
	chassis.moveToPoint(12 ,-15, 1300, {.forwards = false, .maxSpeed = 70}, false);
	midgoal.set_value(HIGH);
	pros::delay(1600);

	//getting matchloader
	chassis.moveToPoint(47,-50, 2000, {.forwards = true, .maxSpeed = 90}, false);
	midgoal.set_value(LOW);
	matchloaderOut();
	chassis.turnToPoint(72,-52, 600, {.forwards = true, .maxSpeed = 127}, false);
	chassis.moveToPoint(72,-52, 1200, {.forwards = true, .maxSpeed = 50}, false);
	pros::delay(200);

	//scoring
	chassis.moveToPoint(10,-52, 1500, {.forwards = false, .maxSpeed = 60}, false);
	midgoal2.set_value(HIGH);
	pros::delay(1500);
	midgoal2.set_value(LOW);
	matchloaderIn();

	//winging
	chassis.moveToPoint(50,-52, 1500, {.forwards = true, .maxSpeed = 80}, false);
	pros::delay(700);
	wing.set_value(LOW);

	chassis.moveToPoint(40,-58, 1400, {.forwards = false, .maxSpeed = 80}, false);
	chassis.moveToPoint(15,-58, 1800, {.forwards = false, .maxSpeed = 60}, false);


	// 2. Record the end time
    uint32_t endTime = pros::millis();
	// 3. Calculate the duration
    uint32_t timeTaken = endTime - startTime;

    // 4. Print to the Brain screen or Terminal for debugging
    pros::lcd::print(4, "AWP Time: %ld ms", timeTaken);


}

void drive_forward(void) {
	// Your autonomous code for the left side
	// 1. Record the start time
    uint32_t startTime = pros::millis();
	wing.set_value(HIGH);

	chassis.setPose(43, -17, 270);


	//scoring midgoal
	intake_front();
	chassis.moveToPoint(40,-17, 3000, {.maxSpeed = 60}, false);
}

void auton_right(void) {
	// Your autonomous code for the right side
	// 1. Record the start time
    uint32_t startTime = pros::millis();
	wing.set_value(HIGH);

	chassis.setPose(43, 17, 270);
	intake_front();
	chassis.moveToPoint(12,24, 1300, {.maxSpeed = 127}, false);
	matchloaderOut();
	pros::delay(200);
	matchloaderIn();

	// chassis.moveToPoint(10,44, 1500, {.maxSpeed = 60}, false);
	// chassis.turnToHeading(360, 500);
	// chassis.moveToPoint(7,54, 2000, {.maxSpeed = 50}, false);
	// pros::delay(500);
	// chassis.moveToPoint(23,23, 1500, {.forwards = false, .maxSpeed = 80}, false);
	chassis.turnToHeading(48, 1200);
	pros::delay(200);
	chassis.moveToPoint(35,50, 1500, {.maxSpeed = 80}, false);
	chassis.turnToHeading(90, 500);
	// chassis.moveToPoint(20,54, 1000, {.forwards = false, .maxSpeed = 80}, false);
	// midgoal2.set_value(HIGH);
	matchloaderOut();

	// pros::delay(2000);
	// midgoal2.set_value(LOW);
	chassis.moveToPoint(73,51, 1000, {.forwards = true, .maxSpeed = 60}, false);
	// pros::delay(200);

	chassis.moveToPoint(20,51, 1500, {.forwards = false, .maxSpeed = 70}, false);
	midgoal2.set_value(HIGH);


	pros::delay(4000);
	matchloaderIn();

	chassis.moveToPoint(45,51, 800, {.forwards = true, .maxSpeed = 70}, false);
	pros::delay(200);	
	chassis.moveToPoint(32,43, 1200, {.forwards = false, .maxSpeed = 70}, false);
	pros::delay(200);	

	chassis.moveToPoint(14,45, 2500, {.forwards = false, .maxSpeed = 70}, false);

	// chassis.moveToPoint(20,51, 1500, {.forwards = false, .maxSpeed = 110}, false);
	// matchloaderIn();

	// chassis.moveToPoint(50,48, 1200, {.forwards = true, .maxSpeed = 70}, false);
	// // chassis.turnToHeading(40, 500);
	// matchloaderIn();
	// chassis.turnToPoint(40,43.5, 500, {.forwards = false, .maxSpeed = 127}, false);
	// chassis.moveToPoint(40,45, 1300, {.forwards = false, .maxSpeed = 70}, false);
	// chassis.turnToHeading(90, 500);
	// wingIn();
	// chassis.moveToPoint(40,49, 1500,{.forwards = false, .maxSpeed = 100}, false);
	// // pros::delay(200);
	// chassis.moveToPoint(25,4, 3000,{.forwards = false, .maxSpeed = 100}, false);




	// chassis.turnToHeading(225, 500);
	// chassis.moveToPoint(10,10, 1000, {.maxSpeed = 60}, false);
	// chassis.moveToPoint(12,12, 400, {.maxSpeed = 60}, false);

	// intake_front_reverse();



	// //scoring midgoal
	// intake_front();
	// chassis.moveToPoint(17,22, 1900, {.maxSpeed = 100}, false);
	// chassis.turnToPoint(0,0, 1000, {.forwards = true, .maxSpeed = 80}, false);
	// chassis.moveToPoint(12,16, 1300, {.forwards = true, .maxSpeed = 70}, false);
	// intake_front_reverse();
	// // midgoal.set_value(HIGH);
	// pros::delay(1500);

	// //getting matchloader
	// chassis.moveToPoint(43,48, 2000, {.forwards = false, .maxSpeed = 90}, false);
	// // midgoal.set_value(LOW);
	// matchloaderOut();
	// intake_front();
	// chassis.turnToPoint(72,48, 600, {.forwards = true, .maxSpeed = 127}, false);
	// pros::delay(500);

	// chassis.moveToPoint(75,48, 100, {.forwards = true, .maxSpeed = 70}, false);

	// //scoring
	// chassis.moveToPoint(10,48, 1500, {.forwards = false, .maxSpeed = 60}, false);
	// midgoal2.set_value(HIGH);
	// pros::delay(1500);
	// midgoal2.set_value(LOW);
	// matchloaderIn();

	// //winging
	// chassis.moveToPoint(50,49, 1500, {.forwards = true, .maxSpeed = 80}, false);
	// pros::delay(700);
	// wing.set_value(LOW);

	// chassis.moveToPoint(40,45, 1400, {.forwards = false, .maxSpeed = 80}, false);
	// chassis.moveToPoint(15,46.5, 1800, {.forwards = false, .maxSpeed = 60}, false);


	// 2. Record the end time
    uint32_t endTime = pros::millis();
	// 3. Calculate the duration
    uint32_t timeTaken = endTime - startTime;

    // 4. Print to the Brain screen or Terminal for debugging
    pros::lcd::print(4, "AWP Time: %ld ms", timeTaken);


}

void auton_right1(void) {
	// Your autonomous code for the right side
	// 1. Record the start time
    uint32_t startTime = pros::millis();
	wing.set_value(HIGH);

	chassis.setPose(43, 17, 270);
	intake_front();
	chassis.moveToPoint(15,26, 1500, {.maxSpeed = 70}, false);
	chassis.moveToPoint(10,44, 1500, {.maxSpeed = 60}, false);
	chassis.turnToHeading(360, 500);
	chassis.moveToPoint(7,54, 2000, {.maxSpeed = 50}, false);
	pros::delay(500);
	chassis.moveToPoint(23,23, 1500, {.forwards = false, .maxSpeed = 80}, false);
	chassis.turnToHeading(40, 500);
	chassis.moveToPoint(40,63, 2000, {.maxSpeed = 80}, false);
	chassis.turnToHeading(90, 900);
	chassis.moveToPoint(20,63, 1500, {.forwards = false, .maxSpeed = 70}, false);
	midgoal2.set_value(HIGH);
	matchloaderOut();

	pros::delay(2000);
	midgoal2.set_value(LOW);
	chassis.moveToPoint(73,52, 1500, {.forwards = true, .maxSpeed = 50}, false);
	pros::delay(600);

	chassis.moveToPoint(20,54, 1000, {.forwards = false, .maxSpeed = 80}, false);
	midgoal2.set_value(HIGH);
	// pros::delay(1500);



	// chassis.turnToHeading(225, 500);
	// chassis.moveToPoint(10,10, 1000, {.maxSpeed = 60}, false);
	// chassis.moveToPoint(12,12, 400, {.maxSpeed = 60}, false);

	// intake_front_reverse();



	// //scoring midgoal
	// intake_front();
	// chassis.moveToPoint(17,22, 1900, {.maxSpeed = 100}, false);
	// chassis.turnToPoint(0,0, 1000, {.forwards = true, .maxSpeed = 80}, false);
	// chassis.moveToPoint(12,16, 1300, {.forwards = true, .maxSpeed = 70}, false);
	// intake_front_reverse();
	// // midgoal.set_value(HIGH);
	// pros::delay(1500);

	// //getting matchloader
	// chassis.moveToPoint(43,48, 2000, {.forwards = false, .maxSpeed = 90}, false);
	// // midgoal.set_value(LOW);
	// matchloaderOut();
	// intake_front();
	// chassis.turnToPoint(72,48, 600, {.forwards = true, .maxSpeed = 127}, false);
	// pros::delay(500);

	// chassis.moveToPoint(75,48, 100, {.forwards = true, .maxSpeed = 70}, false);

	// //scoring
	// chassis.moveToPoint(10,48, 1500, {.forwards = false, .maxSpeed = 60}, false);
	// midgoal2.set_value(HIGH);
	// pros::delay(1500);
	// midgoal2.set_value(LOW);
	// matchloaderIn();

	// //winging
	// chassis.moveToPoint(50,49, 1500, {.forwards = true, .maxSpeed = 80}, false);
	// pros::delay(700);
	// wing.set_value(LOW);

	// chassis.moveToPoint(40,45, 1400, {.forwards = false, .maxSpeed = 80}, false);
	// chassis.moveToPoint(15,46.5, 1800, {.forwards = false, .maxSpeed = 60}, false);


	// 2. Record the end time
    uint32_t endTime = pros::millis();
	// 3. Calculate the duration
    uint32_t timeTaken = endTime - startTime;

    // 4. Print to the Brain screen or Terminal for debugging
    pros::lcd::print(4, "AWP Time: %ld ms", timeTaken);


}
void awp(void) {
	// Your autonomous code for the AWP
	// 1. Record the start time
    uint32_t startTime = pros::millis();
	wing.set_value(HIGH);

	chassis.setPose(47, 17, 0);


	// first matchloader
	chassis.moveToPoint(47,47, 1000, {.maxSpeed = 110}, false);
	chassis.turnToHeading(90,700);
	intake_front();
	matchloaderOut();
	chassis.moveToPoint(69,49, 950, {.forwards = true, .maxSpeed=50}, false);
	chassis.moveToPoint(20,48, 1100, {.forwards = false, .maxSpeed = 70}, false);
	midgoal2.set_value(HIGH);
	pros::delay(1400);
	midgoal2.set_value(LOW);

	chassis.turnToHeading(180, 1000);
	matchloaderIn();
	chassis.moveToPoint(23,-23, 1400, {.forwards = true, .maxSpeed = 110}, false);
	matchloaderOut();
	chassis.turnToHeading(135, 900);
	matchloaderOut();
	chassis.moveToPoint(17,-10, 800, {.forwards = false, .maxSpeed = 70}, false);
	midgoal.set_value(HIGH);
	chassis.turnToHeading(135, 600,{.maxSpeed = 127}, true);

	pros::delay(700);
	// intake_front_reverse();
	// pros::delay(100);

	midgoal.set_value(LOW);
	pros::delay(200);

	// intake_front_stop();

	chassis.moveToPoint(53,-44, 1500, {.forwards = true, .maxSpeed = 100}, false);
	
	// intake_front();
	chassis.turnToPoint(76	,-42, 1100, {.forwards = true, .maxSpeed = 127}, false);
	matchloaderOut();
	// chassis.moveToPoint(76,-42, 1300, {.forwards = true, .maxSpeed = 80}, false);
	// pros::delay(200);

	chassis.moveToPose(20,-42, 90, 1200,{.forwards = false, .maxSpeed = 127}, false);
	matchloaderIn();
	midgoal2.set_value(HIGH);







	// chassis.turnToPoint(67,47, 800, {.forwards = true, .maxSpeed = 100}, false);
	// matchloaderOut(); 
	// pros::delay(200);
	// intake_front();
	// chassis.moveToPoint(66,47, 1000, {.maxSpeed = 50}, false);
	// pros::delay(80);

	// //score 3-4 in first long goal
	// chassis.moveToPoint(10,47, 900, {.forwards = false, .maxSpeed = 80}, false);
	// midgoal2.set_value(HIGH);
	// pros::delay(1400);

	// //collecting 6 balls
	// // chassis.moveToPoint(45,47, 700, {.forwards = true, .maxSpeed = 100}, false);
	// midgoal2.set_value(LOW);
	// matchloaderIn();
	// chassis.turnToPoint(38,-23, 800, {.forwards = true, .maxSpeed = 70}, false);
	// // chassis.moveToPoint(23,23, 1000, {.forwards = true, .maxSpeed = 100}, false);
	// // chassis.turnToPoint(23,-23, 600, {.forwards = true, .maxSpeed = 100}, false);
	// chassis.moveToPoint(30,-22, 1600, {.forwards = true, .maxSpeed = 90}, false);
	

	// //scoring midgoal
	// pros::delay(500);
	// chassis.turnToPoint(0,15, 600, {.forwards = false, .maxSpeed = 70}, false);
	// chassis.moveToPoint(18,-4, 1300, {.forwards = false, .maxSpeed = 80}, false);
	// midgoal.set_value(HIGH);
	// pros::delay(1300);
	// // chassis.moveToPoint(23,-23, 700, {.forwards = true, .maxSpeed = 100}, false);
	// midgoal.set_value(LOW);

	// // second matchloader
	// // chassis.turnToPoint(44,-50, 800, {.forwards = true, .maxSpeed = 100}, false);
	// chassis.moveToPoint(52,-44, 1400, {.forwards = true, .maxSpeed = 100}, false);
	// matchloaderOut();
	// chassis.turnToPoint(72,-40, 600, {.forwards = true, .maxSpeed = 127}, false);
	// chassis.moveToPoint(72,-40, 1300, {.forwards = true, .maxSpeed = 50}, false);
	// pros::delay(100);

	// //scoring 3 on second long goal
	// chassis.moveToPoint(10,-40, 1200, {.forwards = false, .maxSpeed = 70}, false);
	// midgoal2.set_value(HIGH);
	// pros::delay(800);
	
	// chassis.moveToPoint(30,-50, 800, {.forwards = true, .maxSpeed = 127}, false);


	// 2. Record the end time
    uint32_t endTime = pros::millis();
	// 3. Calculate the duration
    uint32_t timeTaken = endTime - startTime;

    // 4. Print to the Brain screen or Terminal for debugging
    pros::lcd::print(4, "AWP Time: %ld ms", timeTaken);


}

void awp1(void) {
	// Your autonomous code for the AWP
	// 1. Record the start time
    uint32_t startTime = pros::millis();
	wing.set_value(HIGH);

	chassis.setPose(47, 17, 0);


	// first matchloader
	chassis.moveToPoint(47,47, 1000, {.maxSpeed = 110}, false);
	chassis.turnToHeading(90,700);
	intake_front();
	matchloaderOut();
	chassis.moveToPoint(69,49, 950, {.forwards = true, .maxSpeed=50}, false);
	chassis.moveToPoint(20,48, 1100, {.forwards = false, .maxSpeed = 70}, false);
	midgoal2.set_value(HIGH);
	pros::delay(1100);
	midgoal2.set_value(LOW);

	chassis.turnToHeading(195, 1000);
	matchloaderIn();
	chassis.moveToPoint(23,-23, 1400, {.forwards = true, .maxSpeed = 110}, false);
	chassis.turnToHeading(135, 900);
	chassis.moveToPoint(17,-10, 800, {.forwards = false, .maxSpeed = 70}, false);
	midgoal.set_value(HIGH);
	chassis.turnToHeading(135, 600,{.maxSpeed = 127}, true);

	pros::delay(500);
	// intake_front_reverse();
	// pros::delay(100);

	midgoal.set_value(LOW);
	// intake_front_stop();

	chassis.moveToPoint(49,-44, 1500, {.forwards = true, .maxSpeed = 100}, false);
	
	// intake_front();
	chassis.turnToPoint(76,-42, 1100, {.forwards = true, .maxSpeed = 127}, false);
	matchloaderOut();
	chassis.moveToPoint(76,-42, 1300, {.forwards = true, .maxSpeed = 80}, false);
	// pros::delay(200);

	chassis.moveToPose(20,-44, 90, 1200,{.forwards = false, .maxSpeed = 127}, false);
	matchloaderIn();
	midgoal2.set_value(HIGH);







	// chassis.turnToPoint(67,47, 800, {.forwards = true, .maxSpeed = 100}, false);
	// matchloaderOut(); 
	// pros::delay(200);
	// intake_front();
	// chassis.moveToPoint(66,47, 1000, {.maxSpeed = 50}, false);
	// pros::delay(80);

	// //score 3-4 in first long goal
	// chassis.moveToPoint(10,47, 900, {.forwards = false, .maxSpeed = 80}, false);
	// midgoal2.set_value(HIGH);
	// pros::delay(1400);

	// //collecting 6 balls
	// // chassis.moveToPoint(45,47, 700, {.forwards = true, .maxSpeed = 100}, false);
	// midgoal2.set_value(LOW);
	// matchloaderIn();
	// chassis.turnToPoint(38,-23, 800, {.forwards = true, .maxSpeed = 70}, false);
	// // chassis.moveToPoint(23,23, 1000, {.forwards = true, .maxSpeed = 100}, false);
	// // chassis.turnToPoint(23,-23, 600, {.forwards = true, .maxSpeed = 100}, false);
	// chassis.moveToPoint(30,-22, 1600, {.forwards = true, .maxSpeed = 90}, false);
	

	// //scoring midgoal
	// pros::delay(500);
	// chassis.turnToPoint(0,15, 600, {.forwards = false, .maxSpeed = 70}, false);
	// chassis.moveToPoint(18,-4, 1300, {.forwards = false, .maxSpeed = 80}, false);
	// midgoal.set_value(HIGH);
	// pros::delay(1300);
	// // chassis.moveToPoint(23,-23, 700, {.forwards = true, .maxSpeed = 100}, false);
	// midgoal.set_value(LOW);

	// // second matchloader
	// // chassis.turnToPoint(44,-50, 800, {.forwards = true, .maxSpeed = 100}, false);
	// chassis.moveToPoint(52,-44, 1400, {.forwards = true, .maxSpeed = 100}, false);
	// matchloaderOut();
	// chassis.turnToPoint(72,-40, 600, {.forwards = true, .maxSpeed = 127}, false);
	// chassis.moveToPoint(72,-40, 1300, {.forwards = true, .maxSpeed = 50}, false);
	// pros::delay(100);

	// //scoring 3 on second long goal
	// chassis.moveToPoint(10,-40, 1200, {.forwards = false, .maxSpeed = 70}, false);
	// midgoal2.set_value(HIGH);
	// pros::delay(800);
	
	// chassis.moveToPoint(30,-50, 800, {.forwards = true, .maxSpeed = 127}, false);


	// 2. Record the end time
    uint32_t endTime = pros::millis();
	// 3. Calculate the duration
    uint32_t timeTaken = endTime - startTime;

    // 4. Print to the Brain screen or Terminal for debugging
    pros::lcd::print(4, "AWP Time: %ld ms", timeTaken);


}

void pid_tuning(void) {
	chassis.setPose(0, 0, 0);
	chassis.turnToHeading(90, 1000);
}


void auton_skills3(){
	chassis.setPose(47, 17, 0);
	wingOut();
	chassis.moveToPoint(47, 47, 2000, {.maxSpeed = 100});
	chassis.turnToHeading(90, 1000);
	matchloaderOut();
	intake_front();
	chassis.moveToPoint(65, 47, 2000, {.maxSpeed = 60}, false);
	chassis.moveToPoint(66, 47, 2000, {.maxSpeed = 60}, true);
	pros::delay(2500);
	chassis.moveToPoint(53, 47, 2000, {.forwards = false, .maxSpeed = 60});
	chassis.turnToHeading(0, 1000);
	chassis.turnToHeading(315, 1000);
	matchloaderIn();

	//reset 1
	chassis.moveToPoint(38, 63, 1000, {.maxSpeed = 100});
	chassis.turnToHeading(270, 1000);
	chassis.moveToPoint(-65, 63, 2000, {.maxSpeed = 100});
	intake_front_stop();
	chassis.moveToPoint(-69, 63, 2000, {.maxSpeed = 40}, false);
	wallReset(270);
	pros::delay(500);

	//score first 7
	chassis.moveToPose(-10, 51, 270, 2000, {.forwards = false, .maxSpeed = 100});
	chassis.turnToHeading(270, 1000, {}, false);
	intake_front();
	midgoal2.set_value(HIGH);
	pros::delay(2500);
	matchloaderOut();
	midgoal2.set_value(LOW);

	//second match loader
	chassis.moveToPose(-66, 50, 270, 2000, {.maxSpeed = 60}, false);
	chassis.moveToPoint(-67, 50, 2000, {.maxSpeed = 60}, true);
	pros::delay(2000);
	chassis.moveToPoint(-10, 50, 2000, {.forwards = false, .maxSpeed = 60}, false);
	intake_front_stop();
	pros::delay(200);
	intake_front();
	matchloaderIn();
	midgoal2.set_value(HIGH);
	pros::delay(3000);
	midgoal2.set_value(LOW);

	//moving to third match loader
	chassis.moveToPoint(-40, 50, 2000, {.maxSpeed = 80}, false);
	chassis.turnToHeading(180, 1000);
	chassis.moveToPoint(-40, -42, 2000, {.maxSpeed = 80}, false);
	chassis.turnToHeading(270, 1000);
	matchloaderOut();
	chassis.moveToPoint(-60, -42, 2000, {.maxSpeed = 60}, false);
	chassis.moveToPoint(-61, -42, 2000, {.maxSpeed = 60}, true);
	pros::delay(2500);
	chassis.moveToPoint(-51, -42, 2000, {.forwards = false, .maxSpeed = 60}, false);
	matchloaderIn();
	pros::delay(200);
	chassis.turnToHeading(180, 1000);
	chassis.turnToHeading(135, 1000);

	//reset 2
	chassis.moveToPoint(-39, -65, 1000, {.maxSpeed = 100});
	chassis.turnToHeading(100, 1000);
	intake_front_stop();
	chassis.moveToPoint(65, -65, 2000, {.maxSpeed = 100});
	chassis.moveToPoint(67, -65, 1000, {.maxSpeed = 40}, false);
	wallReset(90);
	pros::delay(500);

	//second scoring position
	chassis.moveToPose(10, -52, 90, 2000, {.forwards = false, .maxSpeed = 100});
	chassis.turnToHeading(90, 1000, {}, false);
	intake_front();
	midgoal2.set_value(HIGH);
	pros::delay(3000);
	matchloaderOut();
	midgoal2.set_value(LOW);

	//fourth match loader
	chassis.moveToPose(67, -51, 90, 2000, {.maxSpeed = 60}, false);
	chassis.moveToPoint(68, -51, 2000, {.maxSpeed = 60}, true);
	pros::delay(2000);
	chassis.moveToPoint(10, -53, 2000, {.forwards = false, .maxSpeed = 60}, false);	
	intake_front_stop();
	pros::delay(200);
	intake_front();
	matchloaderIn();
	midgoal2.set_value(HIGH);
	pros::delay(3000);

	//park
	chassis.moveToPose(68, -40, 90, 2500, {.maxSpeed = 100}, false);
	chassis.turnToHeading(10, 1400);
	//matchloaderOut();
	chassis.moveToPoint(72, 10, 10000);
	//matchloaderIn();
}

