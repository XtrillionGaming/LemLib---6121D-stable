

#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"

namespace Red {

namespace Right {
    // align to closest mobile goal right up against the wall (4 points)
    static void TwoRingOneStakeLadderAuton(lemlib::Chassis& chassis) {
        chassis.moveToPose(0, -41, 0, 1500, {.forwards = false}, false);
        mogo_clamp();
        pros::delay(500);
        chassis.turnToPoint(-28.17, -40.09, 1000);
        chassis.moveToPoint(-28.17, -40.09, 1000);
        chassis.waitUntilDone();
        run_intake(-127);
        chassis.turnToHeading(180, 750);
        chassis.moveToPoint(16, -41.74, 1000);
        chassis.waitUntilDone();
        mogo_unclamp();
        halt_intake();
    }
};

namespace Left {
    // align to closest mobile goal right up against the wall (6 points) // TODO at Sugar Rush!!!!
    static void FourRingOneStakeLadderAuton(lemlib::Chassis& chassis) {
        chassis.moveToPose(0, -42, 0, 1000, {.forwards = false}, false);
        mogo_clamp();
        pros::delay(500);
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
