#ifndef C_CALLING_CPP_WITH_CLASSES_ROBOT_H
#define C_CALLING_CPP_WITH_CLASSES_ROBOT_H

#ifdef __cplusplus
extern "C" {
#endif
void *create_robot();
void destroy_robot(void *robot);
float get_robot_position(void *robot);
void move_robot_forward(void *robot, float distance);
#ifdef __cplusplus
}
#endif

#endif //C_CALLING_CPP_WITH_CLASSES_ROBOT_H
