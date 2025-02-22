

#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"
#include "main.h"

namespace Blue {

namespace Right {
    // align to closest mobile goal right up against the wall (4 points)
    static void GoalRush(lemlib::Chassis& chassis) {
        chassis.turnToPoint(-0, -37.415, 500, {.forwards = false});
        chassis.moveToPoint(-0, -37.415, 1000, {.forwards = false});
        chassis.waitUntilDone();
        mogo_clamp();
        pros::delay(500);
        run_intake(-127);
        chassis.turnToPoint(27.184, -30.719, 1000);
        chassis.moveToPoint(27.184, -30.719, 1000);
        chassis.waitUntilDone();
        pros::delay(2000);
        intake.move(-127);
        mogo_unclamp();
        chassis.turnToPoint(32.036, -42.597, 750);
        chassis.moveToPoint(32.036, -42.597, 750);
        chassis.turnToHeading(-(47 + 180), 250);
        chassis.waitUntilDone();
        doinker.set_value(1);
        pros::delay(500);
        chassis.turnToPoint(-1.064, -16.969, 750, {.forwards=false});
        chassis.moveToPoint(-1.064, -16.969, 1000, {.forwards=false});
        chassis.waitUntilDone();
        doinker.set_value(0);
        chassis.turnToPoint(2.425, -53.003, 750);
        chassis.moveToPoint(2.425, -53.003, 1000);
        chassis.waitUntilDone();
        halt_intake();
        while (true) {
            int wallstake_pid_output = wallstakePID.update(SCORE_FULL - filter_angle(ladybrown_sensor.get_angle()/100));
            wall.move(wallstake_pid_output);
            pros::delay(10);
        }
    }
};

namespace Left {
    static void RingRush(lemlib::Chassis& chassis) {
        chassis.moveToPoint(0.362, -34.41, 1250, {.forwards=false, .maxSpeed=70});
        chassis.waitUntilDone();
        mogo_clamp();
        pros::delay(500);
        // chassis.turnToPoint(16.1, -60.77, 750);
        chassis.turnToHeading(-90, 750);
        chassis.waitUntilDone();
        intake.move(-127);
        chassis.moveToPose(-16.1, -70.00, 180, 1500);
        chassis.moveToPose(-1, -51.06, 57, 1000, {.forwards=false});
        chassis.turnToPoint(-22.7, -42.05, 500);
        chassis.moveToPoint(-22.7, -42.05, 1000);
        chassis.turnToPoint(-26.81, -60.74, 750);
        chassis.moveToPoint(-26.81, -60.74, 1500);
        chassis.moveToPoint(-16.53, -48.50, 1000, {.forwards=false});
        chassis.turnToPoint(29.227, -41.256, 750);
        chassis.moveToPoint(29.227, -41.256, 1000, {.maxSpeed = 50});
        chassis.waitUntilDone();
        while (true) {
            int wallstake_pid_output = wallstakePID.update(SCORE_FULL - filter_angle(ladybrown_sensor.get_angle()/100));
            wall.move(wallstake_pid_output);
            pros::delay(10);
        }
    }
};

namespace Solo {
    static void SoloAWP (lemlib::Chassis& chassis) {
        chassis.setPose(0, -0, 270);
        chassis.moveToPoint(36.894, 0.362, 1250, {.forwards = false, .maxSpeed = 70});
        chassis.waitUntilDone();
        mogo_clamp();
        pros::delay(750);
        intake.move(-127);
        chassis.turnToPoint(39.437, -23.685, 750);
        chassis.moveToPoint(39.437, -23.685, 2000);
        chassis.turnToPoint(22.781, 23.323, 750);
        intake.move(0);
        chassis.moveToPoint(20.781, 23.323, 1000);
        chassis.waitUntilDone();
        mogo_unclamp();
        chassis.waitUntilDone();
        chassis.turnToPoint(0, 0, 1000);
        chassis.moveToPoint(37.00, 48.00, 1500, {.forwards = false, .maxSpeed = 60});
        chassis.waitUntilDone();
        mogo_clamp();
        chassis.waitUntilDone();
        pros::delay(500);
        intake.move(-127);
        chassis.turnToPoint(35.256, 75.054, 750);
        chassis.moveToPoint(35.256, 75.054, 2000);
        chassis.turnToPoint(35.256, 29.227, 750);
        chassis.moveToPoint(37.256, 20.227, 1000, {.maxSpeed = 50});
        chassis.waitUntilDone();
        while (true) {
            int wallstake_pid_output = wallstakePID.update(SCORE_FULL - filter_angle(ladybrown_sensor.get_angle()/100));
            wall.move(wallstake_pid_output);
            pros::delay(10);
        }
    }
    
}

};