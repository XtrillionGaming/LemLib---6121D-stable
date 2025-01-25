#ifndef COMMON_DEFINITIONS
#define COMMON_DEFINITIONS

#define INTAKE_SPEED -127

// motor groups
pros::MotorGroup leftMotors({-8, -14, -10}, pros::MotorGearset::blue); // left motor group - ports 3 (reversed), 4, 5 (reversed)
pros::MotorGroup rightMotors({19, 9, 20}, pros::MotorGearset::blue); // right motor group - ports 6, 7, 9 (reversed)

pros::adi::DigitalOut mogo('H');
pros::MotorGroup intake({18, -13});
pros::MotorGroup wall({-16});
lemlib::PID wallstakePID(1.5, 0, 0, 10, 0);

// Inertial Sensor on port 10
pros::Imu imu(15);

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

#endif