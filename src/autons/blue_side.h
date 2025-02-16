

#include "api.h"
#include "chassis.hpp"
#include "lemlib/api.hpp"
#include "common_definitions.h"
#include "main.h"

namespace Blue {

namespace Right {
    // align to closest mobile goal right up against the wall (4 points)
    static void TwoRingOneStakeLadderAuton(lemlib::Chassis& chassis) {
        chassis.moveToPose(-0, -41, 0, 1500, {.forwards = false}, false);
        mogo_clamp();
        pros::delay(500);
        while (true) {
            colorCheck(true);
        }
        chassis.turnToPoint(28.17, -40.09, 1000);
        chassis.moveToPoint(28.17, -40.09, 1000);
        chassis.waitUntilDone();
        run_intake(-127);
        chassis.turnToPoint(35.7, -1, 750);
        chassis.moveToPoint(35.7, -1, 1000);
        chassis.waitUntilDone();
        pros::delay(2000);
        rightMotors.move(-127/2);
        leftMotors.move(-127/2);
        pros::delay(1000);
        chassis.turnToPoint(-16, -41.74, 750);
        chassis.moveToPoint(-16, -41.74, 1000);
        chassis.waitUntilDone();
        mogo_unclamp();
        halt_intake();
    }

    static void RingRush(lemlib::Chassis& chassis) {
        pros::delay(500);
        intake.move(-127);
        chassis.setPose(0, 0, 90);
        chassis.moveToPoint(0, 0, 5000);
        chassis.moveToPoint(-35.617, 0.542, 5000, {.forwards = false});
        mogo_clamp();
        chassis.waitUntilDone();
        chassis.turnToPoint(-48.816, -14.102, 5000);
        chassis.moveToPoint(-48.816, -14.102, 5000);
        chassis.turnToPoint(-50.443, -21.153, 5000);
        chassis.moveToPoint(-50.443, -21.153, 5000);
        chassis.turnToPoint(-49.358, -32.182, 5000);
        chassis.moveToPoint(-49.358, -32.182, 5000);
        chassis.turnToPoint(-35.437, -23.142, 5000);
        chassis.moveToPoint(-35.437, -23.142, 5000);
        chassis.turnToPoint(-35.075, -23.865, 5000);
        mogo_unclamp();
        chassis.moveToPoint(-35.075, 23.865, 5000);
    }
};

namespace Left {
    // align to closest mobile goal right up against the wall (6 points) // TODO at Sugar Rush!!!!
    static void FourRingOneStakeLadderAuton(lemlib::Chassis& chassis) {
        chassis.moveToPose(-0, -42, 0, 1000, {.forwards = false}, false);
        mogo_clamp();
        pros::delay(500);
        while (true) {
            colorCheck(true);
        }
        run_intake(-127);
        chassis.turnToPoint(-17.61, -63.31, 750);
        chassis.moveToPoint(-17.61, -63.31, 2000);
        chassis.turnToPoint(-29, -60.9, 750);
        chassis.moveToPoint(-29, -60.9, 2000);
        chassis.moveToPoint(-16.65, -59.94, 1500, {.forwards = false});
        chassis.turnToPoint(-24.82, -40.75, 750);
        chassis.moveToPoint(-24.82, -40.75, 1250);
        chassis.moveToPoint(-7.59, -50.18, 2000);
        chassis.waitUntilDone();
        halt_intake();
        mogo_unclamp();
    }

    static void MogoRush(lemlib::Chassis& chassis) {
        chassis.setPose(0, 0, 90);
        chassis.moveToPoint(0, 0, 5000);
        chassis.moveToPoint(-49.177, 19.888, 5000, {.forwards = false});
        mogo_clamp();
        chassis.waitUntilDone();
        chassis.turnToPoint(-12.475, -0.362, 5000);
        chassis.moveToPoint(-12.475, -0.362, 5000);
        chassis.turnToPoint(-35.075, -23.865, 5000);
        mogo_unclamp();
        chassis.moveToPoint(-35.075, -23.865, 5000);
    }
};

namespace Solo {
    static void SoloAWP (lemlib::Chassis& chassis) {
        pros::delay(1000);
        intake.move(-127);
        chassis.setPose(0, 0, 90);
        chassis.moveToPoint(0, 0, 5000);
        chassis.moveToPoint(-34.894, -0.362, 5000, {.forwards = false});
        mogo_clamp();
        chassis.waitUntilDone();
        chassis.turnToPoint(-35.437, 23.685, 5000);
        chassis.moveToPoint(-35.437, 23.685, 5000);
        chassis.turnToPoint(-22.781, -23.323, 5000);
        chassis.moveToPoint(-22.781, -23.323, 5000);
        mogo_unclamp();
        chassis.turnToPoint(0, 0, 5000);
        chassis.moveToPoint(-34.894, -47.55, 5000, {.forwards = false});
        mogo_clamp();
        chassis.waitUntilDone();
        chassis.turnToPoint(-35.256, -71.054, 5000);
        chassis.moveToPoint(-35.256, -71.054, 5000);
        chassis.turnToPoint(-35.256, -24.227, 5000);
        chassis.moveToPoint(-35.256, -24.227, 5000);
        mogo_unclamp();
    }
    
}

};