program fortran_calling_c_max
    use, intrinsic :: iso_c_binding, only : c_ptr, c_float
    implicit none
    interface
        function create_robot() bind(c, name = 'create_robot')
            import :: c_ptr
            implicit none
            type(c_ptr) :: create_robot
        end function
    end interface
    interface
        subroutine destroy_robot(robot) bind(c, name = 'destroy_robot')
            import :: c_ptr
            implicit none
            type(c_ptr) :: robot
        end subroutine
    end interface
    interface
        function get_robot_position(robot) bind(c, name = 'get_robot_position')
            import :: c_ptr, c_float
            implicit none
            type(c_ptr) :: robot
            real(c_float) :: get_robot_position
        end function
    end interface
    interface
        subroutine move_robot_forward(robot, distance) bind(c, name = 'move_robot_forward')
            import :: c_ptr, c_float
            implicit none
            type(c_ptr) :: robot
            real(c_float), value :: distance
        end subroutine
    end interface
    type(c_ptr) :: robot_
    real :: position_
    real :: distance_
    distance_ = 3.2
    write(*, *) "Message from Fortran."
    robot_ = create_robot()
    call move_robot_forward(robot_, distance_)
    position_ = get_robot_position(robot_)
    write(*, *) "Position in Fortran taken from the C++ object ", position_, "."
    call destroy_robot(robot_)
end program fortran_calling_c_max
