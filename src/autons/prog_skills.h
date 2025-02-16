
#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"
#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"

namespace skills {
    static void auton_skills(lemlib::Chassis& chassis) {
        //place bot up against alliance stake
        //place bot up against alliance stake
        pros::delay(1000);
        while(true) {
            colorCheck(true);
        }
        chassis.setPose(0, 0, 90);
        intake.move(-127);
        pros::delay(1000);
        chassis.moveToPoint(14.506, -0.734, 1000);
        chassis.turnToPoint(14.506, -22.768, 1000);        
        chassis.moveToPoint(14.138, 24.053, 1000, {.forwards = false}, false);
        chassis.waitUntilDone();
        mogo_clamp();
        chassis.turnToPoint(38.008, 24.421, 1000);
        chassis.moveToPoint(38.008, 24.421, 1000);
        chassis.turnToPoint(37.825, 48.291, 1000);
        chassis.moveToPoint(37.825, 48.291, 1000);
        chassis.turnToPoint(61.511, 59.675, 1000);
        chassis.moveToPoint(61.511, 59.675, 1000);
        chassis.turnToPoint(14.322, 59.675, 1000);
        chassis.moveToPoint(14.322, 59.675, 1000);
        chassis.turnToPoint(14.689, 48.107, 1000);
        chassis.moveToPoint(14.689, 48.107, 1000);
        chassis.turnToPoint(2.571, 47.923, 1000);
        chassis.moveToPoint(2.571, 47.923, 1000);
        chassis.turnToPoint(7.528, 8.813, 1000);
        chassis.moveToPoint(1.102, 59.491, 1000, {.forwards=false}, false);
        chassis.waitUntilDone();
        mogo_unclamp();
        chassis.turnToPoint(7.528, 8.813, 1000);
        chassis.moveToPoint(7.528, 8.813, 1000);
        chassis.turnToPoint(1.102, 59.491, 1000);
        chassis.moveToPoint(14.506, -22.768, 1000, {.forwards=false}, false);
        chassis.waitUntilDone();
        mogo_clamp();
        chassis.turnToPoint(38.008, -22.952, 1000);
        chassis.moveToPoint(38.008, -22.952, 1000);
        chassis.turnToPoint(61.511, -58.206, 1000);
        chassis.moveToPoint(61.511, -58.206, 1000);
        chassis.turnToPoint(38.008, -46.271, 1000);
        chassis.moveToPoint(38.008, -46.271, 1000);
        chassis.turnToPoint(14.322, -58.022, 1000);
        chassis.moveToPoint(14.322, -58.022, 1000);
        chassis.turnToPoint(14.322, -46.454, 1000);
        chassis.moveToPoint(14.322, -46.454, 1000);
        chassis.turnToPoint(2.571, -46.454, 1000);
        chassis.moveToPoint(2.571, -46.454, 1000);
        chassis.turnToPoint(14.506, -0.734, 1000);
        chassis.moveToPoint(-0.734, -57.104, 1000, {.forwards=false}, false);
        chassis.waitUntilDone();
        mogo_unclamp();
        chassis.turnToPoint(85.381, -46.087, 1000);
        //wall stake ready
        chassis.moveToPoint(85.381, -46.087, 1000);
        chassis.moveToPoint(61.511, -47.372, 1000);
        chassis.turnToPoint(61.327, -67.386, 1000);
        chassis.moveToPoint(61.327, -67.386, 1000);
        //wall stake score
        chassis.moveToPoint(96.765, -54.166, 1000);
        chassis.turnToPoint(95.112, -62.062, 1000);
        chassis.moveToPoint(108.883, 0.551, 1000, {.forwards=false});
        chassis.waitUntilDone();
        mogo_clamp();
        chassis.turnToPoint(85.381, -22.952, 1000);
        chassis.moveToPoint(85.381, -22.952, 1000);
        chassis.turnToPoint(61.511, 0.918, 1000);
        chassis.moveToPoint(61.511, 0.918, 1000);
        chassis.turnToPoint(84.83, 24.237, 1000);
        chassis.moveToPoint(84.83, 24.237, 1000);
        chassis.turnToPoint(85.013, 47.556, 1000);
        chassis.moveToPoint(85.013, 47.556, 1000);
        intake.move(0);
        mogo_unclamp();
    }
}