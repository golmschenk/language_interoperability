#include <stdio.h>
#include "robot.h"

int main() {
    printf("Message from C.\n");
    void* robot = create_robot();
    move_robot_forward(robot, 3.2f);
    float position = get_robot_position(robot);
    printf("Position in C taken from the C++ object: %f", position);
    destroy_robot(robot);
    return 0;
}
