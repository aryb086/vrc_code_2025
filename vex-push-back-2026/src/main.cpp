#include "main.h"
#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "liblvgl/llemu.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.hpp"
#include "robot.h"
#include "pros/misc.h"
#include "util.h"

// 0 - Skills (default)
// 1 - AWP
// 2 - Left
// 3 - Right
int auton_selection = 0;

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
    auton_selection++;
    if (auton_selection > 3) auton_selection = 0;

    switch (auton_selection) {
        case 0: pros::lcd::set_text(2, "Auton: Skills"); break;
        case 1: pros::lcd::set_text(2, "Auton: AWP"); break;
        case 2: pros::lcd::set_text(2, "Auton: Left"); break;
        case 3: pros::lcd::set_text(2, "Auton: Right"); break;
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
 
 void screenTask(void*) {
    while (true) {
        pros::lcd::print(0, "LD: %d", distanceLeft.get());
        pros::lcd::print(1, "RD: %d", distanceRight.get());
        pros::lcd::print(2, "Heading: %.2f", chassis.getPose().theta);
        pros::delay(50);
    }
}

void initialize() {
    pros::lcd::register_btn1_cb(on_center_button);
    pros::lcd::initialize();

    imu.reset();
    while(imu.is_calibrating()) {
        pros::delay(10);
    }

    chassis.calibrate();
    //static pros::Task screen_task(screenTask);
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
void competition_initialize() {
}

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

void autonomous() {
    // pros::Task screen_task([&]() {
    //     while (true) {
    //         // print robot location to the brain screen
    //         // pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    //         // pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    //         // pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    //         // pros::delay(20);
    //         debugWallReadings();
    //     }
    // });

    
    
    switch (auton_selection) {
        case 0: auton_skills3(); break;
        case 1: awp(); break;
        case 2: auton_left(); break;
        case 3: auton_right(); break;
    }

    check_motor_temp();
    
}

void check_motor_temp(){
    std::vector<double> left_temps = left_motors.get_temperature_all();
    double max_tempL = 0;
    for(double t: left_temps) if( t > max_tempL) max_tempL = t;

    std::vector<double> right_temps = right_motors.get_temperature_all();
    double max_tempR = 0;
    for(double t: left_temps) if( t > max_tempR) max_tempR = t;
    pros::lcd::print(5, "Right: %.2f, Left: %.2f", max_tempR, max_tempL);
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
    // bool last_button_X_state = false;
    // bool last_button_A_state = false;



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
	
        // bool current_button_X_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);
        // bool current_button_A_state = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);


		//both intake forward

        if (current_button_right_state && !last_button_right_state) {
            midgoal_state = !midgoal_state; // Toggle the state
            
            midgoal.set_value(LOW);
            midgoal2.set_value(LOW); 

            // if(midgoal_state) {				
            // } else {
            //     midgoal.set_value(HIGH);
		    // }
        }

        if (current_button_Y_state && !last_button_Y_state) {
            midgoal_state = !midgoal_state; // Toggle the state
            
            midgoal.set_value(LOW);
            midgoal2.set_value(LOW); 

            // if(midgoal_state) {				
            // } else {
            //     midgoal.set_value(HIGH);
		    // }
        }

		if (current_button_L1_state && !last_button_L1_state) {
            midgoal2_state = !midgoal2_state; // Toggle the state
            midgoal_state = !midgoal_state; // Toggle the state
            
            midgoal2.set_value(HIGH);
			midgoal.set_value(LOW);

            // if(midgoal2_state) {


            // } else {
            //     midgoal2.set_value(LOW);
			// 	midgoal.set_value(HIGH);
		    // }
        }

		// if (current_button_A_state && !last_button_A_state) {
        //     midgoal2_state = !midgoal2_state; // Toggle the state


        //     if(midgoal2_state) {
        //         midgoal2.set_value(HIGH);

        //     } else {
        //         midgoal2.set_value(LOW);
		//     }
        // }

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
        // if (current_button_L2_state && !last_button_L2_state) {
        //     back_intake_running = !back_intake_running;

        //     if (back_intake_running) {
        //         // intake_motor_back.move(127);
        //         intake_motor_back.move(-127);
        //     } else {
        //         // intake_motor_back.brake();
        //         // intake_motor_front.brake();
        //         // intake_motor_back.move(0);
        //         intake_motor_back.move(0);
            
        //         bool back_intake_running = true;
        //     }
        // }


        //back intake reverse
        // if (current_button_L1_state && !last_button_L1_state) {
        //     back_intake_running = !back_intake_running;

        //     if (back_intake_running) {
        //         intake_motor_back.move(127);
        //     } else {
        //         intake_motor_back.move(0);
        //         bool back_intake_running = true;
        //     }
        // }
		
        if (current_button_L2_state && !last_button_L2_state) {
            midgoal_state = !midgoal_state; // Toggle the state
            
            midgoal2.set_value(LOW);
			midgoal.set_value(HIGH);


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
        // last_button_A_state = current_button_A_state;
        // last_button_X_state = current_button_X_state;

		
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