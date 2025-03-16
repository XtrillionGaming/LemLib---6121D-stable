

#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"

namespace Red {

namespace Right {
    // align to closest mobile goal right up against the wall (4 points)
    static void GoalRush(lemlib::Chassis& chassis) {
        // chassis.setPose(3.502, -1.646, 4.51);
        chassis.turnToPoint(0, -37.415, 500, {.forwards = false});
        chassis.moveToPoint(0, -37.415, 1250, {.forwards = false, .maxSpeed=70});
        chassis.waitUntilDone();
        mogo_clamp();
        pros::delay(500);
        run_intake(-127);
        pros::delay(500);
        chassis.turnToPoint(-28.184, -34.719, 1000);
        chassis.moveToPoint(-28.184, -34.719, 1500);
        chassis.waitUntilDone();
        intake.move(-127);
        mogo_unclamp();
        chassis.turnToPoint(-34.036, -42.597, 750);
        chassis.moveToPoint(-34.036, -42.597, 750);
        chassis.turnToHeading(52.5 + 180, 250);
        chassis.waitUntilDone();
        doinker.set_value(1);
        pros::delay(500);
        chassis.moveToPoint(1.064, -16.969, 1000, {.forwards=false});
        chassis.waitUntilDone();
        doinker.set_value(0);
        chassis.turnToPoint(-2.425, -53.003, 750);
        chassis.moveToPoint(-2.425, -53.003, 1000);
        chassis.waitUntilDone();
        halt_intake();
        for (int i = 0; i < 10; ++i) {
            int wallstake_pid_output = wallstakePID.update(SCORE_FULL - filter_angle(ladybrown_sensor.get_angle()/100));
            wall.move(wallstake_pid_output);
            pros::delay(10);
        }
    }
};

namespace Left {
    static void RingRush(lemlib::Chassis& chassis) {
        // chassis.setPose(-14.55, -2.06, -53.08);
        // for (int i = 0; i < 100; i++) {
        //     int wallstake_pid_output = wallstakePID.update(SCORE_FULL - wall.get_position());
        //     wall.move(wallstake_pid_output);
        //     pros::delay(10);
        // }
        // for (int i = 0; i < 100; i++) {
        //     int wallstake_pid_output = wallstakePID.update(160 - wall.get_position());
        //     wall.move(wallstake_pid_output);
        //     pros::delay(10);
        // }
        // run_intake(127);
        // pros::delay(600);
        // halt_intake();
        
        // wall.move(127);
        // pros::delay(500);
        // wall.move(0);
        // pros::delay(250);
        // chassis.turnToHeading(5, 250);

        chassis.moveToPoint(-0.0, -38.41, 1250, {.forwards=false, .maxSpeed=70});
        chassis.waitUntilDone();
        // for (int i = 0; i < 500; i++) { 
        //     int wallstake_pid_output = wallstakePID.update(0 - wall.get_position());
        //     wall.move(wallstake_pid_output);
        //     pros::delay(1);
        // }
        
        mogo_clamp();
        pros::delay(500);
        chassis.turnToPoint(16.1, -60.77, 750);
        // chassis.turnToHeading(90, 750);
        chassis.waitUntilDone();
        intake.move(-127);
        chassis.moveToPose(16.1, -69.00, 180, 1500);
        chassis.moveToPose(1, -51.06, 57, 1000, {.forwards=false});
        chassis.turnToPoint(23.7, -42.05, 500);
        chassis.moveToPoint(23.7, -42.05, 1000);
        chassis.turnToPoint(26.81, -57.74, 750);
        chassis.moveToPoint(26.81, -57.74, 1500);
        chassis.moveToPoint(16.53, -48.50, 1000, {.forwards=false});
        chassis.turnToPoint(-29.227, -41.256, 750);
        chassis.moveToPoint(-10, -41.256, 1000, {.maxSpeed = 50});
        chassis.waitUntilDone();

        int wallstake_pid_output = wallstakePID.update(SCORE_FULL - wall.get_position());
        wall.move(wallstake_pid_output);
        pros::delay(500);
        wall.move(0);
    }
};

namespace Solo {
    static void SoloAWP (lemlib::Chassis& chassis) {
        chassis.setPose(0, 0, 270);
        chassis.moveToPoint(36.894, -0.362, 1250, {.forwards = false, .maxSpeed = 70});
        chassis.waitUntilDone();
        mogo_clamp();
        pros::delay(750);
        intake.move(-127);
        chassis.turnToPoint(39.437, 23.685, 750);
        chassis.moveToPoint(39.437, 23.685, 2000);
        chassis.turnToPoint(22.781, -23.323, 750);
        intake.move(0);
        chassis.moveToPoint(20.781, -23.323, 1000);
        chassis.waitUntilDone();
        mogo_unclamp();
        chassis.waitUntilDone();
        chassis.turnToPoint(0, 0, 1000);
        chassis.moveToPoint(37.00, -48.00, 1500, {.forwards = false, .maxSpeed = 60});
        chassis.waitUntilDone();
        mogo_clamp();
        chassis.waitUntilDone();
        pros::delay(500);
        intake.move(-127);
        chassis.turnToPoint(35.256, -75.054, 750);
        chassis.moveToPoint(35.256, -75.054, 2000);
        chassis.turnToPoint(35.256, -29.227, 750);
        chassis.moveToPoint(37.256, -20.227, 1000, {.maxSpeed = 50});
        chassis.waitUntilDone();
        while (true) {
            int wallstake_pid_output = wallstakePID.update(SCORE_FULL - ladybrown_sensor.get_angle()/100);
            wall.move(wallstake_pid_output);
            pros::delay(10);
        }
    }
}

};
