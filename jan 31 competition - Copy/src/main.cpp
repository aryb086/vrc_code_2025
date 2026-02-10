#include "main.h"
#include "liblvgl/llemu.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.hpp"
#include "robot.h"
#include "pros/misc.h"

// #include "pros/motor_group.hpp"




/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
 
pros::adi::DigitalOut matchloader ('A');
pros::adi::DigitalOut midgoal ('H');
pros::adi::DigitalOut midgoal2 ('G');
pros::adi::DigitalOut wing ('C');

void initialize() {
	pros::lcd::initialize();

	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);

	pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors


    // pros::Task screen_task([&]() {
    //     while (true) {
    //         // print robot location to the brain screen
    //         printf(0, "X: %f", chassis.getPose().x); // x
    //         pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    //         pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    //         pros::delay(20);
    //     }
    // });

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

	

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

	void midgoalOut(){
		wing.set_value(HIGH);
	} 

	void midgoalIn(){
		wing.set_value(LOW);
	} 

void autonomous() {
	//pid tuning 
    //chassis.setPose(0, 0, 0);
    // move 48" forwards
    // chassis.moveToPoint(0, 48, 10000, {.maxSpeed=100	});

	//*************************************************************************************************************
	
	//move forward

	// chassis.setPose(61, 17, 0);
	// pros::delay(500);
	// chassis.moveToPoint(61,22, 4000, {.maxSpeed = 30}, false);


	// //skills
	// chassis.setPose(47, 17, 0);
	// pros::delay(500);

	// //getting to first matchloading station 
	// chassis.moveToPoint(43,47, 1400, {.maxSpeed = 80}, false);
	// chassis.turnToPoint(67,47, 500, {.maxSpeed = 80}, false);
	// matchloaderOut();
	// pros::delay(600);
	// intake_front();
	// chassis.moveToPoint(65,44, 1500, {.maxSpeed = 60}, false);
	// chassis.moveToPoint(60,45, 400, {.maxSpeed = 127}, false);
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


	//*************************************************************************************************************
	// Blue1
	
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




	//*************************************************************************************************************
	// matchloaderIn();
	// intake_front_stop();
	// chassis.moveToPoint(47,58, 600, {.maxSpeed = 80}, false);
	// chassis.turnToPoint(70,58, 700,{.maxSpeed = 80}, false);
	// chassis.moveToPoint(-47,58, 4000,{.maxSpeed = 100}, false);
	// pros::delay(300);


	// chassis.turnToPoint(-47,47, 700,{.maxSpeed = 80}, false);
	// chassis.moveToPoint(-47,47, 700,{.maxSpeed = 80}, false);
	// chassis.turnToPoint(-68,47, 700,{.maxSpeed = 80}, false);
	// chassis.moveToPoint(-30,47, 1500,{.maxSpeed = 40}, false);
	// intake_back();
	// intake_front();
	// pros::delay(3000);

	// // collecting balls from second matchloading station & scoring them
	// matchloaderOut();
	// intake_back_stop();
	// chassis.moveToPoint(-45,47, 700,{.maxSpeed = 80}, false);
	// chassis.moveToPoint(-61,47, 1500,{.maxSpeed = 40}, false);
	// pros::delay(1000);
	// chassis.moveToPoint(-30,47, 2000,{.maxSpeed = 40}, false);
	// intake_back();
	// pros::delay(2000);

	// // collecting balls from third matchloading station
	// chassis.moveToPoint(-40,47, 700,{.maxSpeed = 80}, false);
	// intake_front_stop();
	// intake_back_stop();
	// chassis.turnToPoint(-40,-47, 700,{.maxSpeed = 80}, false);
	// chassis.moveToPoint(-40,-47, 3000,{.maxSpeed = 100}, false);
	// matchloaderOut();
	// intake_front();
	// pros::delay(600);
	// chassis.turnToPoint(-61,-47, 700,{.maxSpeed = 80}, false);
	// chassis.moveToPoint(-61,-47, 600,{.maxSpeed = 80}, false);
	// pros::delay(2000);

	// // moving away from third matchloading station and scoring 
	// chassis.moveToPoint(-40,-47, 700,{.maxSpeed = 80}, false);
	// matchloaderIn();
	// intake_front_stop();
	// chassis.turnToPoint(-40,-20, 700,{.maxSpeed = 80}, false);
	// chassis.moveToPoint(-40,-60, 700,{.maxSpeed = 80}, false);
	// chassis.turnToPoint(-60,-60, 700,{.maxSpeed = 80}, false);
	// chassis.moveToPoint(40,-60, 3000,{.maxSpeed = 100}, false);
	// chassis.turnToPoint(40,-30, 700,{.maxSpeed = 80}, false);
	// chassis.moveToPoint(40,-47, 800,{.maxSpeed = 80}, false);
	// chassis.turnToPoint(60,-47, 700,{.maxSpeed = 80}, false);
	// chassis.moveToPoint(27,-47, 1000,{.maxSpeed = 40}, false);
	// intake_front();
	// intake_back();
	// pros::delay(1400);
	// matchloaderOut();
	// intake_back_stop();
	// pros::delay(600);
	// chassis.moveToPoint(63,-47, 1500,{.maxSpeed = 40}, false);	
	// pros::delay(2000);
	// chassis.moveToPoint(27,-47, 1500,{.maxSpeed = 40}, false);
	// pros::delay(400);
	// intake_back();
	// pros::delay(2000);




	pros::delay(500);


	//

	
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	pros::Controller master(pros::E_CONTROLLER_MASTER);
	// pros::MotorGroup left_mg({13, -16, 14});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
	// pros::MotorGroup right_mg({-18, 19, -20});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6

    // while (true) {

    // }

	bool back_intake_running = false;
	bool both_intake = false;
	bool intake_running = true;
    bool intake_reverse_running = false;
 
    bool last_button_R1_state = false;
    // bool intake_reversed = false;
    bool last_button_R2_state = false;
    bool last_button_L1_state = false;
    bool last_button_L2_state = false;
    bool last_button_right_state = false;
    bool last_button_Y_state = false;
    bool last_button_B_state = false;
    bool last_button_down_state = false;\
    bool last_button_X_state = false;
    bool last_button_A_state = false;



    // bool last_button_left_state = false;
	
	bool midgoal_state = LOW;
	bool midgoal2_state = LOW;
    bool matchloader_state = LOW; 
	bool wing_state = LOW; 

	// bool doinker_state = LOW; 

    
    while (true) {


		int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        chassis.tank(leftY, rightY);
        // pros::delay(25);


        // hello
        int current_button_R1_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
        int current_button_R2_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
        bool current_button_down_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
        // bool current_button_up_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
        bool current_button_B_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);
        bool current_button_L2_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
        bool current_button_Y_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y);
        // bool current_button_X_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);
        bool current_button_L1_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
        bool current_button_right_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);
	
        bool current_button_X_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);
        bool current_button_A_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);


		//both intake forward
        if (current_button_right_state && !last_button_right_state) {
            midgoal_state = !midgoal_state; // Toggle the state
            
            if(midgoal_state) {
                midgoal.set_value(LOW);
				
            } else {
                midgoal.set_value(HIGH);
		    }
        }

		if (current_button_X_state && !last_button_X_state) {
            midgoal2_state = !midgoal2_state; // Toggle the state
            midgoal_state = !midgoal_state; // Toggle the state


            if(midgoal2_state) {
                midgoal2.set_value(HIGH);
				midgoal.set_value(LOW);

            } else {
                midgoal2.set_value(LOW);
				midgoal.set_value(HIGH);
		    }
        }

		if (current_button_A_state && !last_button_A_state) {
            midgoal2_state = !midgoal2_state; // Toggle the state


            if(midgoal2_state) {
                midgoal2.set_value(HIGH);

            } else {
                midgoal2.set_value(LOW);
		    }
        }

		//front intake forward
        if (current_button_R1_state && !last_button_R1_state) {
            both_intake = !both_intake;

            if (both_intake) {
                intake_motor_front.move(127);
				intake_motor_back.move(127);
            } else {

                intake_motor_front.move(0);
				intake_motor_back.move(0);
            
                bool intake_running = true;
            }
        }


        //front intake reverse
        if (current_button_R2_state && !last_button_R2_state) {
            intake_running = !intake_running;

            if (intake_running) {
                intake_motor_front.move(-127);
			    intake_motor_back.move(-127);

			} else {
                intake_motor_front.move(0);
                intake_motor_back.move(0);
				bool intake_running = true;
            }
        }

		// back intake forward
        if (current_button_L2_state && !last_button_L2_state) {
            back_intake_running = !back_intake_running;

            if (back_intake_running) {
                // intake_motor_back.move(127);
                intake_motor_back.move(-127);
            } else {
                // intake_motor_back.brake();
                // intake_motor_front.brake();
                // intake_motor_back.move(0);
                intake_motor_back.move(0);
            
                bool back_intake_running = true;
            }
        }


        //back intake reverse
        if (current_button_L1_state && !last_button_L1_state) {
            back_intake_running = !back_intake_running;

            if (back_intake_running) {
                intake_motor_back.move(127);
            } else {
                intake_motor_back.move(0);
                bool back_intake_running = true;
            }
        }
		
        if (current_button_Y_state && !last_button_Y_state) {
            midgoal_state = !midgoal_state; // Toggle the state
            
            if(midgoal_state) {
                midgoal.set_value(HIGH);
				
            } else {
                midgoal.set_value(LOW);
		    }
        }
		
	    if (current_button_down_state && !last_button_down_state) {
        	wing_state = !wing_state; // Toggle the state
            
			if(wing_state) {
				wing.set_value(LOW);
					
			} else {
				wing.set_value(HIGH);
			}
        }	

		if (current_button_B_state && !last_button_B_state) {
        	matchloader_state = !matchloader_state; // Toggle the state
            
			if(matchloader_state) {
				matchloader.set_value(HIGH);
					
			} else {
				matchloader.set_value(LOW);
			}
        }	
		

        last_button_R1_state = current_button_R1_state;
        last_button_R2_state = current_button_R2_state;
        last_button_L1_state = current_button_L1_state;
		last_button_L2_state = current_button_L2_state;
		last_button_right_state = current_button_right_state;
        last_button_Y_state = current_button_Y_state;
        last_button_B_state = current_button_B_state;
		last_button_down_state = current_button_down_state;
        last_button_A_state = current_button_A_state;
        last_button_X_state = current_button_X_state;

		
		// last_button_up_state = current_button_up_state;
        // last_button_B_state = current_button_B_state;
        // last_button_X_state = current_button_X_state;
        // last_button_left_state = current_button_left_state;

		// while (true) {
		// 	printf(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		// 	                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		// 	                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen LCDs

		// 	// Arcade control scheme
		// 	// int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		// 	// int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		// 	// left_motor.move(dir - turn);                      // Sets left motor voltage
		// 	// right_mg.move(dir + turn);                     // Sets right motor voltage
		// 	pros::delay(20);                               // Run for 20 ms then update
		pros::delay(25);

	}
}