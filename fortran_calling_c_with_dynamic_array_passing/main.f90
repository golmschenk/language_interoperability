program fortran_calling_c_max
    use, intrinsic :: iso_c_binding, only : c_ptr, c_double, c_int, c_loc
    implicit none
    interface
        subroutine two_dimensional_array_manipulation(input_array_pointer, output_array_pointer, shape0, shape1) &
                bind(c, name = 'two_dimensional_array_manipulation')
            import :: c_ptr, c_int
            type(c_ptr), intent(in), value :: input_array_pointer
            type(c_ptr), intent(in), value :: output_array_pointer
            integer(c_int), intent(in), value :: shape0
            integer(c_int), intent(in), value :: shape1
        end subroutine
    end interface
    integer(c_int), parameter :: shape0_ = 3
    integer(c_int), parameter :: shape1_ = 2
    integer :: index
    real(c_double), allocatable, target :: input_array(:, :)
    real(c_double), allocatable, target :: output_array(:, :)
    type(c_ptr) :: input_array_pointer_
    type(c_ptr) :: output_array_pointer_
    allocate(input_array(shape0_, shape1_))
    allocate(output_array(shape0_, shape1_))
    input_array_pointer_ = c_loc(input_array(1, 1))
    output_array_pointer_ = c_loc(output_array(1, 1))
    write(*, *) "Message from Fortran."
    input_array = reshape((/0, 1, 2, 3, 4, 5/), (/shape0_, shape1_/))
    write(*, *) "Input array in Fortran:"
    do index = 1, size(input_array, 1)
        write(*,*) input_array(index, :)
    end do
    call two_dimensional_array_manipulation(input_array_pointer_, output_array_pointer_, shape0_, shape1_)
    write(*, *) "Output array in Fortran:"
    do index = 1, size(output_array, 1)
        write(*,*) output_array(index, :)
    end do
end program fortran_calling_c_max
