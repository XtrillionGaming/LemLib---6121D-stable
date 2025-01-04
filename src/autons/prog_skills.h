
#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"

namespace skills {
    static void auton_skills {
        intake.move(-127);
        delay(1000);
        chassis.moveToPoint(0, 0,  5000);
        chassis.moveToPose(12.758, 23.656, 135, 5000, {.fowards = false}, false);
        mogo_clamp();
        chassis.turnToPoint(36.415, 23.39, 5000);
        chassis.moveToPoint(36.415, 23.39, 5000);
        chassis.moveToPoint(36.149, 46.781, 5000);
        chassis.moveToPoint(59.805, 59.805, 5000);
        chassis.moveToPoint(12.493, 58.476, 5000);
        chassis.moveToPoint(12.758, 47.578, 5000);
        chassis.moveToPoint(0.797, 47.312, 5000);
        chassis.moveToPoint(-2.924, 60.071, 5000);
        mogo_unclamp();
        chassis.moveToPoint(83.461, 47.312, 5000, {.fowards = true},  false);
        intake.move(0);
        chassis.moveToPoint(107.383, 0.266, 5000, {.fowards = false}, false);
        mogo_clamp();
        intake.move(-127);
        chassis.moveToPoint(83.727, 23.656, 5000);
        chassis.moveToPoint(60.071, 0.532, 5000);
        chassis.moveToPoint(83.727, -23.39, 5000);
        chassis.moveToPoint(83.461, -46.515, 5000);
        chassis.moveToPoint(59.273, -59.008, 5000);
        chassis.moveToPoint(-1.063, -61.134, 5000);
        chassis.moveToPoint(11.961, -58.21, 5000);
        mogo_unclamp();
        chassis.moveToPoint(13.29, -23.922, 5000);
        intake.move(0);
        chassis.moveToPoint(1.329, -46.781, 5000);
        mogo_clamp();
        intake.move(-127);
        chassis.moveToPoint(12.227, -46.249, 5000);
        chassis.moveToPoint(35.883, -47.047, 5000);
        chassis.moveToPoint(36.415, -23.39, 5000);
    }
}