#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motor_group.hpp"
#include "pros/optical.hpp"
#include "pros/rtos.hpp"
#include "lemlib/pid.hpp"
#include "autons/blue_side.h"
#include "autons/red_side.h"
#include "autons/common_definitions.h"

#define INTAKE_SPEED -127

// controller
pros::Controller Master(pros::E_CONTROLLER_MASTER);


//color sensor
pros::Optical ringSense(69);

// tracking wheels
// horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
pros::Rotation horizontalEnc(17);
// horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275, -3.5);
// vertical tracking wheel encoder. Rotation sensor, port 20, not reversed
pros::Rotation verticalEnc(7);
// vertical tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_275, 0);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              15, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 4" omnis
                              450, // drivetrain rpm is 360
                              2 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            3, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             10, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// sensors for odometry
lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            &horizontal, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);

bool ejectRed = false;
// Runs the intake in


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors

    // the default rate is 50. however, if you need to change the rate, you
    // can do the following.
    // lemlib::bufferedStdout().setRate(...);
    // If you use bluetooth or a wired connection, you will want to have a rate of 10ms

    // for more information on how the formatting for the loggers
    // works, refer to the fmtlib docs

    // thread to for brain screen and position logging
    pros::Task screenTask([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            // delay to save resources
            pros::delay(50);
        }
    });
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}

// get a path used for pure pursuit
// this needs to be put outside a function


/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */
void autonomous() {
    // Allaince Carry Rough Draft
    chassis.setPose(0, 0, 0);
    Red::Right::TwoRingOneStakeLadderAuton(chassis);
}
bool wallScore = true;

/**
 * Runs in driver control
 */
void opcontrol() {
    // autonomous();
    // controller
    // loop to continuously update motors
	bool is_intake_on = false;
    unsigned long long iter = 0;
    int goal_wallstake_angle = 0;
	wall.set_encoder_units_all(pros::MotorEncoderUnits::degrees);
    while (true) {
        // get joystick positions
        int leftY = Master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        int rightX = Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        // move the chassis with curvature drive
        chassis.arcade(leftY, rightX);

        if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			intake.move(-127);
		} else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			intake.move(127);
		} else {
			intake.move(0);
		}
        if (Master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
			is_intake_on = !is_intake_on;
		}

        if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			goal_wallstake_angle = 0;
		} else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
			goal_wallstake_angle = 65;
		} else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
			goal_wallstake_angle = 400;
		}

		// set PID for wallstake
		int wallstake_pid_output = wallstakePID.update(goal_wallstake_angle - wall.get_position(0));
		wall.move(wallstake_pid_output);

		mogo.set_value(is_intake_on);
        // delay to save resources
        pros::delay(10);    
        iter++;
    }
}
