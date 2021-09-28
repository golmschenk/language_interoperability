program fortran_calling_c_max
    use, intrinsic :: iso_c_binding, only : c_int
    implicit none
    interface
        integer(c_int) function cMax(number0, number1) bind(c, name = 'cMax')
            import :: c_int
            integer(c_int), value :: number0
            integer(c_int), value :: number1
        end function
    end interface
    write(*, *) "Message from Fortran."
    write(*, *) "Maximum calculated in C with values passed from and returned to Fortran:", cMax(5, 7)
end program fortran_calling_c_max
