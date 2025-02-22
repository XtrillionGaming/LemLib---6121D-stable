
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
        chassis.moveToPoint(0, 28 * 0.03803125, 1000);
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
        chassis.turnToPoint(4.07, 110.71, 750, {.forwards=false});
        chassis.waitUntilDone();
        doinker.set_value(0);
        rightMotors.move(70);
        leftMotors.move(70);
        pros::delay(1500);
        rightMotors.move(0);
        leftMotors.move(0);
        pros::delay(500);
        chassis.moveToPoint(4.07, 110.71, 1000, {.forwards=false, .maxSpeed=70});
        chassis.waitUntilDone();
        mogo_clamp();
        pros::delay(500);
        chassis.turnToPoint(-10.19, 110.72, 750);
        chassis.waitUntilDone();
        mogo_unclamp();
        rightMotors.move(70);
        leftMotors.move(70);
        pros::delay(1500);
        rightMotors.move(0);
        leftMotors.move(0);
        pros::delay(500);
        chassis.moveToPoint(4.07, 110.71, 1000, {.forwards=false, .maxSpeed=70});
        chassis.waitUntilDone();
        mogo_clamp();
        run_intake(127);
        chassis.turnToPoint(-22.62, 75.67, 750);
        chassis.moveToPoint(-22.62, 75.67, 1000);
        chassis.turnToPoint(-47.76, 75.01, 750);
        chassis.moveToPoint(-47.76, 75.01, 1000);

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
}