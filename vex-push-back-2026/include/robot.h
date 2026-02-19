// robot.h
#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "pros/distance.hpp"

// Controller and drivetrain declarations
extern pros::Controller controller;
extern lemlib::Chassis chassis;
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern pros::Motor intake_motor_front;
extern pros::Motor intake_motor_back;
extern pros::Rotation v_tracking;
extern pros::Rotation h_tracking;
extern pros::ADIDigitalOut matchloader;
extern pros::ADIDigitalOut midgoal;
extern pros::ADIDigitalOut midgoal2;
extern pros::ADIDigitalOut wing;
extern pros::Distance distanceLeft;
extern pros::Distance distanceRight;
extern pros::Imu imu;