.globl factorial

.data
n: .word 3
ans: .word 0

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial
    la t0, ans
    sw a0, 0(t0)
    
    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
    # value is in a0 
    addi sp, sp -8
    sw ra, 0(sp)
    sw a0, 4(sp)
    addi t0, x0, 1
    sub a0, a0, t0
    beq a0, t0, done
    jal ra, factorial
    mv t0, a0
    lw ra, 0(sp)
    lw a0, 4(sp)
    addi sp, sp, 8
    mul a0, a0, t0
    
done:
    jr ra

# how to load them as immediates
# 29
# -214
# -2999
# 0xABCDE000
# 0xEDCBA123
# 0xEEEEEFAB
    
    
    

