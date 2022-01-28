program main
    use, intrinsic :: iso_c_binding, only : c_float
    implicit none
    interface
        real(c_float) function multiply(a, b) bind(c, name = 'multiply')
            import :: c_float
            real(c_float), value :: a
            real(c_float), value :: b
        end function
    end interface
    write(*, *) "Message from Fortran."
    write(*, *) "Product in Fortran:", multiply(4.5, 3.0)
end program main
