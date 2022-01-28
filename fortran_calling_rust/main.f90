program main
    use, intrinsic :: iso_c_binding, only : c_float
    implicit none
    interface
        real(c_float) function multiply(factor0, factor1) bind(c, name = 'multiply')
            import :: c_float
            real(c_float), value, intent(in) :: factor0
            real(c_float), value, intent(in) :: factor1
        end function
    end interface
    write(*, *) "Message from Fortran."
    write(*, *) "Product in Fortran:", multiply(4.5, 3.0)
end program main
