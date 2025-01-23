
#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"

namespace skills {
    static void auton_skills(lemlib::Chassis& chassis) {
        //place bot up againts alliance stake
        pros::delay(1000);
        chassis.setPose(0, 0, 90);
        chassis.moveToPoint(14.619, 0.532, 1000);
        chassis.moveToPoint(38.275, 0.797, 1000);
        chassis.moveToPoint(38.275, 23.656, 1000);
        chassis.moveToPoint(14.619, 23.39, 1000);
        chassis.moveToPoint(15.151, 35.617, 1000);
        chassis.moveToPoint(3.19, 24.454, 1000);
        chassis.moveToPoint(-0.266, 36.415, 1000);
        chassis.moveToPoint(8.24, -17.543, 1000);
        chassis.moveToPoint(14.619, -46.249, 1000);
        chassis.moveToPoint(2.924, -70.703, 1000);
        chassis.moveToPoint(14.619, -71.234, 1000);
        chassis.moveToPoint(14.885, -81.601, 1000);
        chassis.moveToPoint(0.532, -86.917, 1000);
    }
}