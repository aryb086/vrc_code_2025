#pragma once

void intake_front_reverse(void);
void intake_front(void);
void intake_front_stop(void);
void intake_back(void);
void intake_back_stop(void);
void matchloaderOut(void);
void matchloaderIn(void);
void wingOut(void);
void wingIn(void);
void midgoalOut(void);
void midgoalIn(void);
void pidDriveForward(double distanceInches, int timeoutMs = 3000, int maxSpeed = 127, bool async = false);
void pidDriveBackward(double distanceInches, int timeoutMs = 3000, int maxSpeed = 127, bool async = false);
void wallReset(double wallHeadingDeg = 0, double sensorSpacing = 7.5, double alpha = 0.8);