program hello
    use, intrinsic :: iso_c_binding, only : c_int
    implicit none
    interface
        integer(c_int) function cMax(number0, number1) bind(c, name = 'max')
            import :: c_int
            integer(c_int), value :: number0
            integer(c_int), value :: number1
        end function
    end interface
    write(*, *) cMax(5, 7)
    write(*, *) 'Hello world!'
end program hello
