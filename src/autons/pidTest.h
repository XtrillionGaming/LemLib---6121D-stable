#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"
#include "api.h"
#include "lemlib/api.hpp"
#include "common_definitions.h"

namespace test {
    static void PIDTest(lemlib::Chassis& chassis) {
        chassis.moveToPoint(0, 0, 5000);
        chassis.moveToPose(-23, -23, 180, 6000);
    }
}