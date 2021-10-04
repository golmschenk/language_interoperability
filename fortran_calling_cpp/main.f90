program fortran_calling_c_max
    use, intrinsic :: iso_c_binding, only : c_int
    implicit none
    interface
        integer(c_int) function cppMin(number0, number1) bind(c, name = 'cppMin')
            import :: c_int
            integer(c_int), value :: number0
            integer(c_int), value :: number1
        end function
    end interface
    write(*, *) "Message from Fortran."
    write(*, *) "Minimum in Fortran is ", cppMin(5, 7), "."
end program fortran_calling_c_max
