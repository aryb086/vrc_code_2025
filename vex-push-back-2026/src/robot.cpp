#include "robot.h"

// Controller and drivetrain declarations
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_motors({13, -3, -14}, pros::MotorGearset::blue); //-13,-15, 12
pros::MotorGroup right_motors({-17, 18, 19}, pros::MotorGearset::blue); //10,2,-9
pros::Motor intake_motor_front(-6, pros::MotorGearset::green);//R1, R2
pros::Motor intake_motor_back(11, pros::MotorGearset::red);// L1, 

// Sensors
pros::Rotation h_tracking(-16);
pros::Imu imu(8);

// Pneumatics
pros::ADIDigitalOut matchloader ('A');
pros::ADIDigitalOut midgoal ('H');
pros::ADIDigitalOut midgoal2 ('G');
pros::ADIDigitalOut wing ('C');

// Tracking wheels
lemlib::TrackingWheel horizontal_tracking_wheel(&h_tracking, lemlib::Omniwheel::NEW_2, -4.5);

lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                              &right_motors, // right motor group
                              12, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 4" omnis
                              450, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);


lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to nullptr as we are using IMEs
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller
/*
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)//10
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);
*/

lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)//10
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                                20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2.2, //2
                                              .08, // integral gain (kI)
                                              10.1, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors
);