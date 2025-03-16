
#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"
#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"

double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

namespace skills {
    static void odom_testing(lemlib::Chassis& chassis) {
        while (true) {
            chassis.moveToPoint(0, 20, 1000);
            chassis.turnToPoint(20, 20, 1000);
            chassis.moveToPoint(20, 20, 1000);
            chassis.turnToPoint(20, 0, 1000);
            chassis.moveToPoint(20, 0, 1000);
            chassis.turnToPoint(0, 0, 1000);
            chassis.moveToPoint(0, 0, 1000);
            chassis.turnToPoint(0, 20, 1000);
            chassis.waitUntilDone();
        }
    }

    static void auton_skills(lemlib::Chassis& chassis) {
        // Place bot up against alliance stake
        // First Side - 1st mogo + allaince
        // run_intake(127);
        chassis.moveToPoint(0, 25 * 0.03803125, 1000);
        chassis.waitUntilDone();
        run_intake(127);
        pros::delay(500);
        chassis.moveToPoint(0, 13.24, 1000);  
        chassis.turnToPoint(-20.67, 10.24, 750, {.forwards=false});
        chassis.moveToPoint(-20.67, 10.24, 1000, {.forwards=false, .maxSpeed=70});
        chassis.waitUntilDone();
        pros::delay(500);
        mogo_clamp();
        run_intake(127);
        pros::delay(100);
        chassis.turnToPoint(-22.47, 36.25, 750);
        chassis.moveToPoint(-22.47, 36.25, 1000);
        chassis.waitUntilDone();
        // pros::delay(1000);
        chassis.turnToPoint(-48.26, 35.25, 750);
        chassis.moveToPoint(-48.26, 35.25, 1000);
        chassis.waitUntilDone();
        // pros::delay(1000);
        chassis.turnToPoint(-56.70, 61.90, 750);
        chassis.moveToPoint(-56.70, 61.9, 1500);
        chassis.waitUntilDone();
        // pros::delay(1000);
        chassis.turnToPoint(-45.0, -5, 1000);
        chassis.moveToPoint(-45.0, -5, 2000, {.maxSpeed=100});
        chassis.waitUntilDone();
        // pros::delay(2000);
        chassis.moveToPose (-37.98, 11.24, -90, 1500, {.forwards=false});
        chassis.turnToPoint(-60.00, 11.24, 750);
        chassis.moveToPoint(-60.00, 11.24, 1000);
        chassis.turnToPoint(-62.00, 5.24, 750, {.forwards=false});
        chassis.waitUntilDone();
        rightMotors.move(-35);
        leftMotors.move(-35);
        pros::delay(1000);
        mogo_unclamp();
        run_outtake(-127);
        chassis.turnToPoint(0, 13.24, 750);
        chassis.moveToPoint(0, 13.24, 1000);
        chassis.turnToHeading(0, 750);
        chassis.waitUntilDone();
        pros::delay(1000);
        run_intake(127);

        const double angle = chassis.getPose().theta + 180;
        const double length = distance_sensor_back.get() * 0.03803125;
        
        const double Y = abs(length * cos(degreesToRadians(angle)));
        
        chassis.setPose(chassis.getPose().x, Y, chassis.getPose().theta);

        // TODO: IMPLEMENT SECOND SENSOR

        // second side 2.0:
        chassis.turnToPoint(20.67, 10.24, 750, {.forwards=false});
        chassis.moveToPoint(20.67, 10.24, 1000, {.forwards=false, .maxSpeed=70});
        chassis.waitUntilDone();
        pros::delay(500);
        mogo_clamp();
        run_intake(127);
        pros::delay(100);
        chassis.turnToPoint(22.47, 35.25, 750);
        chassis.moveToPoint(22.47, 35.25, 1000);
        chassis.waitUntilDone();
        // pros::delay(1000);
        chassis.turnToPoint(47.26, 35.25, 750);
        chassis.moveToPoint(47.26, 35.25, 1000);
        chassis.waitUntilDone();
        // pros::delay(1000);
        chassis.turnToPoint(55, 61.90, 750);
        chassis.moveToPoint(55, 61.9, 1500);
        chassis.waitUntilDone();
        // pros::delay(1000);
        chassis.turnToPoint(47.5, -5, 1000);
        chassis.moveToPoint(47.5, -5, 2000, {.maxSpeed=100});
        chassis.waitUntilDone();
        // pros::delay(2000);
        chassis.moveToPose (39.98, 11.24, 90, 1500, {.forwards=false});
        chassis.turnToPoint(64.00, 11.24, 750);
        chassis.moveToPoint(64.00, 11.24, 1000);
        chassis.turnToPoint(64.00, 5.24, 750, {.forwards=false});
        chassis.waitUntilDone();
        rightMotors.move(-35);
        leftMotors.move(-35);
        pros::delay(1000);
        mogo_unclamp();
        run_outtake(-127);

        // Maybe recalibrate odom here?
        chassis.moveToPoint(60, 11.24, 750);
        chassis.turnToHeading(0, 500);
        chassis.waitUntilDone();
        halt_intake();

        const double angle2 = chassis.getPose().theta;
        const double length2 = distance_sensor_back.get() * 0.03803125;
        
        const double Y2 = abs(length2 * cos(degreesToRadians(angle2)));

        const double angle3 = chassis.getPose().theta;
        const double length3 = distance_sensor_back.get() * 0.03803125;
        
        const double X = 1706*0.03803125 - abs(length3 * cos(degreesToRadians(angle3)));
        
        chassis.setPose(X, Y2, chassis.getPose().theta);


        run_intake(127);
        chassis.moveToPoint(10.9, 112.33, 2000); // TODO
        chassis.waitUntilDone();
        doinker.set_value(1);
        chassis.turnToPoint(4.07, 113.71, 750, {.forwards=false});
        chassis.waitUntilDone();
        doinker.set_value(0);
        pros::delay(500);
        run_outtake(-127);
        rightMotors.move(70);
        leftMotors.move(70);
        pros::delay(2000);
        rightMotors.move(0);
        leftMotors.move(0);
        pros::delay(500);
        chassis.moveToPoint(4.07, 110.71, 1000, {.forwards=false, .maxSpeed=70});
        chassis.waitUntilDone();
        mogo_clamp();
        pros::delay(500);
        chassis.turnToPoint(-10.19, 114.72, 750);
        chassis.waitUntilDone();
        mogo_unclamp();
        run_outtake(-127);
        rightMotors.move(125);
        leftMotors.move(125); 
        pros::delay(2000);
        rightMotors.move(0);
        leftMotors.move(0);
        pros::delay(500);
        chassis.moveToPoint(4.07, 110.71, 1000, {.forwards=false, .maxSpeed=70});
        chassis.waitUntilDone();
        mogo_clamp();
        run_intake(127);
        chassis.turnToPoint(-29.62, 75.67, 750);
        chassis.moveToPoint(-29.62, 75.67, 1000);
        chassis.turnToPoint(-47.76, 75.01, 750);
        chassis.moveToPoint(-47.76, 75.01, 1000);
        chassis.waitUntilDone();

        halt_intake();

        // // 3rd Part: middle mogo
        // chassis.turnToPoint(29.78, 103.37, 750);
        // chassis.moveToPoint(29.78, 103.37, 2000, {.maxSpeed=100});
        // chassis.waitUntilDone();
        // halt_intake();
        // chassis.turnToPoint(12.78, 104.16, 750, {.forwards=false});
        // chassis.moveToPoint(12.78, 104.16, 1000, {.forwards=false, .maxSpeed=80});
        // chassis.waitUntilDone();
        // mogo_clamp();
        // pros::delay(250);
        // run_intake(127); 
        // chassis.turnToPoint(26.62, 70.97, 1000);
        // chassis.moveToPoint(26.62, 70.97, 1000);
        
        // chassis.turnToPoint(52.07, 70.97, 1000);
        // chassis.moveToPoint(52.07, 70.97, 1000);
        
        // chassis.turnToPoint(49.84, 103.37, 1000);
        // chassis.moveToPoint(49.84, 103.37, 1000);
        
        // chassis.turnToPoint(50.11, 112.57, 1000);
        // chassis.moveToPoint(50.11, 112.57, 1000);

        // chassis.turnToPoint(62.83, 101.20, 1000);
        // chassis.moveToPoint(62.83, 101.20, 1000);

        // chassis.turnToPoint(-7.22, 53.13, 1000);
        // chassis.moveToPoint(-7.22, 53.13, 1000);
        
        // chassis.waitUntilDone();
        // mogo_unclamp();
        // run_outtake(-127);

        // push rest

        // chassis.turnToPoint(-28.78, 92.92, 750);
        // chassis.waitUntilDone();
        // run_intake(127);
        // chassis.moveToPoint(-28.78, 92.92, 1000);

        // chassis.turnToPoint(-23.39, 107.42, 750);
        // chassis.moveToPoint(-23.39, 107.42, 1000);
        // chassis.waitUntilDone();
        // halt_intake();

        // chassis.turnToPoint(-45.81, 118.41, 750);
        // chassis.moveToPoint(-45.81, 118.41, 1000);

        // chassis.turnToPoint(60.34, 116.04, 750);
        // chassis.moveToPoint(60.34, 116.04, 1000);

        // chassis.turnToPoint(49.46, 55.36, 750);
        // chassis.moveToPoint(49.46, 55.36, 1000);
    }

    static void auton_skills_better(lemlib::Chassis& chassis) {
        wall.move(127);
        pros::delay(500);
        chassis.moveToPoint(-0.26, -23.14, 1000, {.forwards=false});
        wall.move(0);
        chassis.waitUntilDone();
        mogo_clamp();
        pros::delay(250);

        // intake
        run_intake(127);
        wall.move(-127);
        chassis.turnToPoint(-19.33, -40.39, 500);
        chassis.waitUntilDone();
        chassis.moveToPoint(-19.33, -40.39, 750);
        wall.move(0);

        chassis.turnToPoint(-44.62, -119.24, 500);
        chassis.moveToPoint(-44.62, -119.24, 2100, {.maxSpeed=70});
        pros::delay(2200);
        while (chassis.isInMotion()) {
            int wallstake_pid_output = wallstakePID.update(100 - wall.get_position());
		    wall.move(wallstake_pid_output);
            pros::delay(10);
        }

        chassis.turnToPoint(-23.88, -74.62, 750, {.forwards=false});
        chassis.moveToPoint(-23.88, -74.62, 1500, {.forwards=false, .maxSpeed=60});
        
        // ladybrown
        chassis.turnToPoint(-9.11, -86.78, 500);
        chassis.moveToPoint(-9.11, -86.78, 1000);
        chassis.waitUntilDone();

        rightMotors.move(127/5);
        leftMotors.move(127/5);
        pros::delay(500);
        wall.move(127);
        pros::delay(750);
        for (int i = 0; i < 75; ++i) {
            int wallstake_pid_output = wallstakePID.update(100 - wall.get_position());
		    wall.move(wallstake_pid_output);
            pros::delay(10);
        }
        run_intake(127);
        pros::delay(750);
        intake.move(-127/9);
        wall.move(127);
        pros::delay(750);
        wall.move(0);

        rightMotors.move(0);
        leftMotors.move(0);
        
        // intake rest of rings
        rightMotors.move(-127/5);
        leftMotors.move(-127/5);
        wall.move(-127);
        pros::delay(600);
        rightMotors.move(0);
        leftMotors.move(0);
        wall.move(0);

        chassis.turnToPoint(25.76, -28.41, 750);
        chassis.moveToPoint(25.76, -28.41, 1500, {.maxSpeed=100});
        chassis.waitUntilDone();

        rightMotors.move(-127/5);
        leftMotors.move(-127/5);
        pros::delay(500);
        rightMotors.move(0);
        leftMotors.move(0);

        // push in corner
        chassis.turnToPoint(21.72, -53.81, 750);
        chassis.moveToPoint(21.72, -53.81, 1000);

        chassis.turnToPoint(26.91, -47.16, 1250, {.forwards=false});
        chassis.moveToPoint(26.91, -47.16, 900, {.forwards=false});
        chassis.waitUntilDone();
        mogo_unclamp();
        run_outtake(-127);

        // recalibrate: (by setting heading to be theta)
        double theta = -45.10;
        double x = 6.84;
        double y = -27.11;

        chassis.moveToPose(x, y, theta, 1000);
        chassis.waitUntilDone();
        double Dx = distance_sensor_right.get() * 0.03803125;
        double Dy = distance_sensor_back.get() * 0.03803125 + 608 * 0.03803125;

        y = -Dy / cos(degreesToRadians(chassis.getPose().theta - theta));
        x = Dx / cos(degreesToRadians(chassis.getPose().theta - theta));

        pros::lcd::print(4, "%f", x);
        pros::lcd::print(5, "%f", y);
        pros::lcd::print(6, "%f", chassis.getPose().theta);

        halt_intake();
        chassis.setPose(x, y, chassis.getPose().theta);
        
        // move on to next mogo
        chassis.turnToPoint(-18.95, 3.27, 500, {.forwards=false});
        chassis.moveToPoint(-18.95, 3.27, 2000, {.forwards=false, .maxSpeed=70});
        chassis.waitUntilDone();

        // intake
        run_intake(127);
        mogo_clamp();
        pros::delay(250);
        chassis.turnToPoint(-52.16, -3.67, 1000);
        chassis.moveToPoint(-52.16, -3.67, 2000);

        chassis.turnToPoint(-122.85, -32.06, 1000);
        chassis.moveToPoint(-122.85, -32.06, 2100, {.maxSpeed=70});

        chassis.turnToPoint(-86.45, -11.10, 1000, {.forwards=false});
        chassis.moveToPoint(-86.45, -11.10, 2000, {.forwards=false, .maxSpeed=70});

        // // ladybrown
        // chassis.turnToPoint(-93.49, 5.24, 1000);
        // chassis.moveToPoint(-93.49, 5.24, 2000);
        // chassis.waitUntilDone();

        // // intake rest of rings
        // rightMotors.move(-127/5);
        // leftMotors.move(-127/5);
        // pros::delay(500);
        // rightMotors.move(0);
        // leftMotors.move(0);

        // chassis.turnToPoint(-41.47, 38.35, 1000);
        // chassis.moveToPoint(-41.47, 38.35, 2000, {.maxSpeed=100});
        // chassis.waitUntilDone();

        // // rightMotors.move(-127/5);
        // // leftMotors.move(-127/5);
        // // pros::delay(500);
        // // rightMotors.move(0);
        // // leftMotors.move(0);

        // // put in the corner
        // chassis.turnToPoint(-66.39, 38.26, 1000);
        // chassis.moveToPoint(-66.39, 38.26, 2000);

        // chassis.turnToPoint(-61.30, 39.54, 1250, {.forwards=false});
        // chassis.moveToPoint(-61.30, 39.54, 900, {.forwards=false});
        // chassis.waitUntilDone();
        // mogo_unclamp();
    }
}