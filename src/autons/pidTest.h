#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"
#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"

namespace test {
    static void PIDTest(lemlib::Chassis& chassis) {
        chassis.setPose(0, 0, 5000);
        chassis.moveToPoint(0.797, -93.296, 5000);
        chassis.moveToPoint(94.891, -93.296, 5000);
        chassis.moveToPoint(94.891, -0.266, 5000);
        chassis.moveToPoint(0.266, 0.266, 5000);
    }
}