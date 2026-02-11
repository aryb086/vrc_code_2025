#include "robot.h"
#include <cmath>

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

void pidDriveForward(double distanceInches, int timeoutMs, int maxSpeed, bool async) {
    lemlib::Pose current = chassis.getPose(); // current x,y,theta

    double radians = current.theta * (3.1415926535 / 180.0);
    double targetX = current.x + distanceInches * std::cos(radians);
    double targetY = current.y + distanceInches * std::sin(radians);

    chassis.moveToPose(
        targetX,
        targetY,
        current.theta,
        timeoutMs,
        {.forwards = true, .maxSpeed = (float)maxSpeed},
        async
    );
}

void pidDriveBackward(double distanceInches, int timeoutMs, int maxSpeed, bool async) {
    lemlib::Pose current = chassis.getPose();

    double radians = current.theta * (3.1415926535 / 180.0);
    double targetX = current.x - distanceInches * std::cos(radians);
    double targetY = current.y - distanceInches * std::sin(radians);

    chassis.moveToPose(
        targetX,
        targetY,
        current.theta,
        timeoutMs,
        {.forwards = false, .maxSpeed = (float)maxSpeed},
        async
    );
}

