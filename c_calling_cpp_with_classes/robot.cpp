#include <iostream>
#include "robot.hpp"
#include "robot.h"

namespace robot {
    Robot::Robot() {
        position = 0;
    }

    void Robot::move_forward(float distance) {
        std::cout << "Message from C++ object method." << std::endl;
        position += distance;
        std::cout << "Position in C++ is " << position << "." << std::endl;
    }
}


void *create_robot() { return new robot::Robot(); }

void destroy_robot(void *robot) {
    delete static_cast<robot::Robot *>(robot);
};

float get_robot_position(void *robot) {
    return static_cast<robot::Robot *>(robot)->position;
};

void move_robot_forward(void *robot, float distance) {
    static_cast<robot::Robot *>(robot)->move_forward(distance);
};
