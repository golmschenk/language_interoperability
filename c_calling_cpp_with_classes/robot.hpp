#ifndef C_CALLING_CPP_WITH_CLASSES_ROBOT_HPP
#define C_CALLING_CPP_WITH_CLASSES_ROBOT_HPP

namespace robot {
    class Robot {
    public:
        Robot();
        float position;
        void move_forward(float distance);
    };

}

#endif //C_CALLING_CPP_WITH_CLASSES_ROBOT_HPP
