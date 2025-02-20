

#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"
#include "main.h"

namespace Red {

namespace Right {
    // align to closest mobile goal right up against the wall (4 points)
    static void TwoRingOneStakeLadderAuton(lemlib::Chassis& chassis) {
        // 3.157
        chassis.turnToPoint(0, -37.415, 500, {.forwards = false});
        chassis.moveToPoint(0, -37.415, 1000, {.forwards = false});
        chassis.waitUntilDone();
        mogo_clamp();
        pros::delay(500);
        run_intake(-127);
        chassis.turnToPoint(-27.184, -30.719, 1000);
        chassis.moveToPoint(-27.184, -30.719, 1000);
        chassis.waitUntilDone();
        pros::delay(2000);
        intake.move(-127);
        mogo_unclamp();
        chassis.turnToPoint(-32.036, -42.597, 750);
        chassis.moveToPoint(-32.036, -42.597, 750);
        chassis.turnToHeading(47 + 180, 250);
        chassis.waitUntilDone();
        doinker.set_value(1);
        rightMotors.move(30);
        leftMotors.move(30);
        pros::delay(500);
        chassis.turnToPoint(1.064, -16.969, 750, {.forwards=false});
        chassis.moveToPoint(1.064, -16.969, 1000, {.forwards=false});
        chassis.waitUntilDone();
        doinker.set_value(0);
        chassis.turnToPoint(-2.425, -53.003, 750);
        chassis.moveToPoint(-2.425, -53.003, 1000);
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
    // align to closest mobile goal right up against the wall (6 points) // TODO at Sugar Rush!!!!
    static void FourRingOneStakeLadderAuton(lemlib::Chassis& chassis) {
        chassis.moveToPose(0, -42, 0, 1000, {.forwards = false}, false);
        mogo_clamp();
        pros::delay(500);
        while (true) {
            colorCheck(true);
        }
        run_intake(-127);
        chassis.turnToPoint(17.61, -63.31, 750);
        chassis.moveToPoint(17.61, -63.31, 2000);
        chassis.turnToPoint(29, -60.9, 750);
        chassis.moveToPoint(29, -60.9, 2000);
        chassis.moveToPoint(16.65, -59.94, 1500, {.forwards = false});
        chassis.turnToPoint(24.82, -40.75, 750);
        chassis.moveToPoint(24.82, -40.75, 1250);
        chassis.moveToPoint(-7.59, -50.18, 2000);
        chassis.waitUntilDone();
        halt_intake();
        mogo_unclamp();
    }
};

};
