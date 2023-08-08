.import lotsofaccumulators.s

.data
inputarray: .word 0,2,3,4,5,6,7,0      # make first index zero to fail accumulatorfive

TestPassed: .asciiz "Test Passed!"
TestFailed: .asciiz "Test Failed!"

.text
# Tests if the given implementation of accumulate is correct.
#Input: a0 contains a pointer to the version of accumulate in question. See lotsofaccumulators.s for more details
#
#
#
#The main function currently runs a simple test that checks if accumulator works on the given input array. All versions of accumulate should pass this.
#Modify the test so that you can catch the bugs in four of the five solutions!
main:
    la a0 inputarray
    addi t2, x0, 26       # adding random value in t2 to fail accumulatorfour
    addi s0, x0, 7        # adding no zero value in s0 to fail accumulatorone
    add t4, x0, s0        # storing s0 value in t4 to fail accumulatorone
    addi sp, sp, -4       
    sw t2, 0(sp)          # putting value of t2 on stack for checking accumulatortwo
    jal accumulatorone
    lw t3, 0(sp)          # getting value back from stack to check whether its same or not for accumulatortwo
    addi sp, sp, 4
    li t0 0
    bne t2, t3, Fail     # fail accumulatortwo
    bne t4, s0, Fail     # fail accumulatorone
    beq a0 t0 Pass
    
Fail:
    la a0 TestFailed
    jal print_string
    j End
Pass:
    la a0 TestPassed
    jal print_string
End:
    jal exit

print_int:
	mv a1 a0
    li a0 1
    ecall
    jr ra
    
print_string:
	mv a1 a0
    li a0 4
    ecall
    jr ra
    
exit:
    li a0 10
    ecall