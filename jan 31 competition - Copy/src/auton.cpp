#include "auton.h"
#include "robot.h"
#include "util.h"

void auton_left(void) {
	// Your autonomous code for the left side
}

void auton_right(void) {
	// Your autonomous code for the right side
	chassis.setPose(61, 17, 0);
	pros::delay(500);
	chassis.moveToPoint(61,22, 4000, {.maxSpeed = 30}, false);


	chassis.setPose(47, 17, 0);
	pros::delay(500);

	//getting to first matchloading station 
	chassis.moveToPoint(43,47, 1400, {.maxSpeed = 80}, false);
	chassis.turnToPoint(67,47, 500, {.maxSpeed = 80}, false);
	matchloaderOut();
	pros::delay(600);
	intake_front();
	chassis.moveToPoint(65,44, 1500, {.maxSpeed = 60}, false);
	chassis.moveToPoint(60,45, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);
	// 
	chassis.moveToPoint(17,44, 1000, {.forwards = false, .maxSpeed = 50}, false);
	intake_back();
	pros::delay(5000);


	// //end of blue1

	// chassis.moveToPoint(44,44, 700, {.maxSpeed = 127}, false);
	// chassis.turnToPoint(44,54, 500, {.maxSpeed = 80}, false);
	// chassis.moveToPoint(44,54, 700, {.maxSpeed = 127}, false);

	// chassis.turnToPoint(8,56, 500, {.maxSpeed = 80}, false);
	// wingIn();
	// chassis.moveToPoint(8,56, 1000, {.maxSpeed = 60}, false);


	// // 
	// chassis.setPose(47, 13, 270);
	// pros::delay(500);
	
	// wing.set_value(HIGH);


	// //getting to bottom scoring goal
	// intake_front();
	

	// chassis.moveToPoint(22,22, 2000, {.maxSpeed = 60}, false);
	// chassis.turnToPoint(0,-14, 500, {.maxSpeed = 80}, false);
	// chassis.moveToPoint(0,-14 , 280, {.maxSpeed = 50}, false);
	// intake_motor_front.move(-127);
	// intake_motor_back.move(-70);
	// pros::delay(1400);
	// chassis.moveToPoint(48,35, 2000, {.forwards = false, .maxSpeed = 80}, false);

	// intake_front_stop();
	// chassis.turnToHeading(90, 1000, {.maxSpeed = 80}, false);

	// //getting matchloads
	// intake_front();

	// matchloaderOut();
	// chassis.moveToPoint(73,44, 3000, {.maxSpeed = 60}, false);
	// chassis.moveToPoint(68,44, 400, {.forwards = false, .maxSpeed = 127}, false);
	// chassis.moveToPoint(73,44, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(68,44, 400, {.forwards = false, .maxSpeed = 127}, false);
	// chassis.moveToPoint(73,44, 400, {.maxSpeed = 127}, false);

	// chassis.moveToPoint(20,45, 4000, {.forwards = false, .maxSpeed = 40}, false);
	// intake_back();
	// pros::delay(3000);
	// chassis.moveToPoint(50,50, 1000, {.forwards = true, .maxSpeed = 60}, false);
	// chassis.moveToPoint(23,55, 1500, {.maxSpeed = 40}, false);
	// wingIn();
	// chassis.moveToPoint(7,60, 3000, {.maxSpeed = 50}, false);

}

void awp(void) {
	// Your autonomous code for the AWP
}

void auton_skills(void) {
	//skills
	chassis.setPose(47, 17, 0);
	pros::delay(500);

	//getting to first matchloading station 
	chassis.moveToPoint(43,47, 1400, {.maxSpeed = 80}, false);
	chassis.turnToPoint(67,47, 500, {.maxSpeed = 80}, false);
	matchloaderOut();
	pros::delay(600);
	intake_front();
	chassis.moveToPoint(65,44, 1500, {.maxSpeed = 60}, false);
	chassis.moveToPoint(60,45, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);	
	chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(65,44, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(60,43, 400, {.maxSpeed = 127}, false);

	//collecting balls from first matchloading station
	pros::delay(1700);
	// intake_front_stop();


	//moving away from first matchloading station & scoring
	chassis.moveToPoint(50,44, 1200, {.forwards = false, .maxSpeed = 80}, false);
	// intake_front();
	pros::delay(200);
	matchloaderIn();
	chassis.turnToPoint(29,62, 1000, {.maxSpeed = 80}, false);
	chassis.moveToPoint(29,62, 1600, {.forwards = true, .maxSpeed = 60}, false);		
	chassis.turnToPoint(-47,58, 1000, {.maxSpeed = 80}, false);	
	intake_front_stop();

	chassis.moveToPoint(-60,58, 3000, {.forwards = true, .maxSpeed = 90}, false);
	pros::delay(200);
	// chassis.turnToPoint(-70,65, 500, {.maxSpeed = 80}, false);
	chassis.moveToPoint(-35,47, 1000, {.forwards = false, .maxSpeed = 50}, false);
	pros::delay(200);
	chassis.moveToPoint(-23,47, 1000, {.forwards = false, .maxSpeed = 50}, false);
	intake_motor_front.move(-127);
	pros::delay(150);
	intake_front();
	intake_back();
	matchloaderOut();
	chassis.moveToPoint(-17,47, 1000, {.forwards = false, .maxSpeed = 50}, false);
	pros::delay(5000);


	chassis.moveToPoint(-70,47, 1500, {.maxSpeed = 50}, false);
	intake_back_stop();
	// intake_front_stop();


	chassis.moveToPoint(-62,47, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(-68,47, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(-62,47, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(-68,47, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(-62,47, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(-68,47, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(-62,47, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(-68,47, 400, {.maxSpeed = 127}, false);	
	chassis.moveToPoint(-62,47, 400, {.maxSpeed = 127}, false);
	chassis.moveToPoint(-68,47, 400, {.maxSpeed = 127}, false);
	// chassis.moveToPoint(-63,47, 400, {.maxSpeed = 127}, false);
	
	chassis.moveToPoint(-40,47, 1000, {.forwards = false, .maxSpeed = 40}, false);	

	intake_motor_front.move(-127);
	pros::delay(150);
	intake_front();

	chassis.moveToPoint(-20,47, 2500, {.forwards = false, .maxSpeed = 40}, false);	
	matchloaderIn();
	intake_back();
	pros::delay(5000);

	chassis.moveToPoint(-50,47, 700, {.forwards = true, .maxSpeed = 60}, false);
	chassis.turnToPoint(-25,25, 1000, {.maxSpeed = 80}, false);
	chassis.moveToPoint(-25,25, 1500, {.forwards = true, .maxSpeed = 80}, false);
	chassis.moveToPoint(83,37, 2000, {.forwards = true, .maxSpeed = 80}, false);
	pros::delay(400);
	chassis.turnToPoint(80,-7, 1000, {.maxSpeed = 80}, false);

	chassis.moveToPoint(80,-7, 1500, {.forwards = true, .maxSpeed = 127}, false);
}
