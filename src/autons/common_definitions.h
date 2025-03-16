#ifndef COMMON_DEFINITIONS
#define COMMON_DEFINITIONS

#include "pros/motor_group.hpp"
#define INTAKE_SPEED -127
#define SCORE_FULL 550

// motor groups
pros::MotorGroup leftMotors({-1, -4, -6}, pros::MotorGearset::blue); // left motor group - ports 3 (reversed), 4, 5 (reversed)
pros::MotorGroup rightMotors({8, 17, 18}, pros::MotorGearset::blue); // right motor group - ports 6, 7, 9 (reversed)

pros::adi::DigitalOut mogo('A');
pros::adi::DigitalOut doinker('B');
pros::MotorGroup intake({-3, 19});
pros::MotorGroup wall({11});
lemlib::PID wallstakePID(1.5, 0, 1, 10, 0);

pros::Rotation ladybrown_sensor(16);
pros::Distance distance_sensor_back(15);
pros::Distance distance_sensor_right(10);

// Inertial Sensor on port 10
pros::Imu imu(14);

// Runs the intake in
static void run_intake(int speed) {
    intake.move(INTAKE_SPEED);
}

// Runs the intake out
static void run_outtake(int speed) {
    intake.move(-INTAKE_SPEED);
}

// Stops the intake
static void halt_intake() {
    intake.move(0);
}

// Clamps the mogo
static void mogo_clamp() {
    mogo.set_value(1);
}

// Unclamps the mogo
static void mogo_unclamp() {
    mogo.set_value(0);
}

static double filter_angle(double angle) {
    if (angle > 180) {
        return 360 - angle;
    } else {
        return angle;
    }
}

#endif