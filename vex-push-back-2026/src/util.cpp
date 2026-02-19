#include "lemlib/pose.hpp"
#include "pros/llemu.hpp"
#include "robot.h"
#include <cmath>

void intake_front_reverse(){
	intake_motor_front.move(-127);
    intake_motor_back.move(-127);
}

void intake_front(){
	intake_motor_front.move(127);
	intake_motor_back.move(127);

}

void intake_front_stop(){
	intake_motor_front.move(0);
	intake_motor_back.move(0);

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

void wallReset(
    double wallHeadingDeg,        // field heading of wall (ex: 0, 90, 180)
    double sensorSpacing,     // inches between sensors
    double alpha        // IMU trust weight (0.7–0.9 recommended)
) {
    // Ensure robot is stopped
    chassis.waitUntilDone();
    pros::delay(50);

    // Average sensor readings
    double sumL = 0;
    double sumR = 0;
    const int samples = 10;

    for(int i = 0; i < samples; i++) {
        sumL += distanceLeft.get();
        sumR += distanceRight.get();
        pros::delay(10);
    }

    double dL = sumL / samples;
    double dR = sumR / samples;

    // Convert mm → inches (VEX distance returns mm)
    dL /= 25.4;
    dR /= 25.4;

    // Reject bad readings (too far from wall)
    if(dL > 18 || dR > 18) return;

    // Compute wall-relative angle (radians)
    double thetaWallRad = atan((dR - dL) / sensorSpacing);

    // Convert to degrees
    double thetaWallDeg = thetaWallRad * 180.0 / M_PI;

    // Absolute field heading from wall reference

    double computedHeading = wallHeadingDeg + thetaWallDeg;

    // Get IMU heading
    double imuHeading = imu.get_heading();

    // Blend (complementary filter)
    double fusedHeading =
        alpha * imuHeading +
        (1.0 - alpha) * computedHeading;

    // Normalize 0–360
    if(fusedHeading < 0) fusedHeading += 360;
    if(fusedHeading >= 360) fusedHeading -= 360;

    // Reset pose while preserving X/Y
    lemlib::Pose pose = chassis.getPose();
    chassis.setPose(pose.x, pose.y, fusedHeading);
}

void debugWallReadings(
    double sensorSpacing,
    double wallHeadingDeg,
    double alpha
) {
    pros::lcd::clear();

    // Average readings
    double sumL = 0;
    double sumR = 0;
    const int samples = 10;

    for(int i = 0; i < samples; i++) {
        sumL += distanceLeft.get();
        sumR += distanceRight.get();
        pros::delay(10);
    }

    double dL = (sumL / samples) / 25.4; // mm → inches
    double dR = (sumR / samples) / 25.4;

    double thetaWallRad = atan((dR - dL) / sensorSpacing);
    double thetaWallDeg = thetaWallRad * 180.0 / M_PI;

    double imuHeading = imu.get_heading();
    double computedHeading = wallHeadingDeg + thetaWallDeg;

    double fusedHeading =
        alpha * imuHeading +
        (1.0 - alpha) * computedHeading;

    // Normalize
    if(fusedHeading < 0) fusedHeading += 360;
    if(fusedHeading >= 360) fusedHeading -= 360;

    // Print to Brain
    pros::lcd::print(1, "WallTheta: %.2f deg", thetaWallDeg);
    pros::lcd::print(2, "IMU: %.2f deg", imuHeading);
    pros::lcd::print(3, "Fused: %.2f deg", fusedHeading);
}

