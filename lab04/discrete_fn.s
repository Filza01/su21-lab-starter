.globl f

.data
neg3:   .asciiz "f(-3) should be 6, and it is: "
neg2:   .asciiz "f(-2) should be 61, and it is: "
neg1:   .asciiz "f(-1) should be 17, and it is: "
zero:   .asciiz "f(0) should be -38, and it is: "
pos1:   .asciiz "f(1) should be 19, and it is: "
pos2:   .asciiz "f(2) should be 42, and it is: "
pos3:   .asciiz "f(3) should be 5, and it is: "

output: .word   6, 61, 17, -38, 19, 42, 5
.text
main:
    addi t0, x0, 0
    la a0, neg3
    jal print_str
    li a0, -3
    la a1, output
    addi sp, sp, -4
    sw t0, 0(sp)
    jal f               # evaluate f(-3); should be 6
    lw t0, 0(sp)
    addi sp, sp, 4
    addi t0, t0, 4
    jal print_int
    jal print_newline

    la a0, neg2
    jal print_str
    li a0, -2
    la a1, output
    addi sp, sp, -4
    sw t0, 0(sp)
    jal f               # evaluate f(-2); should be 61
    lw t0, 0(sp)
    addi sp, sp, 4
    addi t0, t0, 4
    jal print_int
    jal print_newline

    la a0, neg1
    jal print_str
    li a0, -1
    la a1, output
    addi sp, sp, -4
    sw t0, 0(sp)
    jal f               # evaluate f(-1); should be 17
    lw t0, 0(sp)
    addi sp, sp, 4
    addi t0, t0, 4
    jal print_int
    jal print_newline

    la a0, zero
    jal print_str
    li a0, 0
    la a1, output
    addi sp, sp, -4
    sw t0, 0(sp)
    jal f               # evaluate f(0); should be -38
    lw t0, 0(sp)
    addi sp, sp, 4
    addi t0, t0, 4
    jal print_int
    jal print_newline

    la a0, pos1
    jal print_str
    li a0, 1
    la a1, output
    addi sp, sp, -4
    sw t0, 0(sp)
    jal f               # evaluate f(1); should be 19
    lw t0, 0(sp)
    addi sp, sp, 4
    addi t0, t0, 4
    jal print_int
    jal print_newline

    la a0, pos2
    jal print_str
    li a0, 2
    la a1, output
    addi sp, sp, -4
    sw t0, 0(sp)
    jal f               # evaluate f(2); should be 42
    lw t0, 0(sp)
    addi sp, sp, 4
    addi t0, t0, 4
    jal print_int
    jal print_newline

    la a0, pos3
    jal print_str
    li a0, 3
    la a1, output
    addi sp, sp, -4
    sw t0, 0(sp)
    jal f               # evaluate f(3); should be 5
    lw t0, 0(sp)
    addi sp, sp, 4
    addi t0, t0, 4
    jal print_int
    jal print_newline

    li a0, 10
    ecall

# f takes in two arguments:
# a0 is the value we want to evaluate f at
# a1 is the address of the "output" array (defined above).
# Think: why might having a1 be useful?
f: 
    # -3 -2 -1 0 1 2 3
    # YOUR CODE GOES HERE!
    lw t0, 0(sp)
    add a1, a1, t0
    lw a0, 0(a1)
    # addi t0, t0, 4    # This line is commented to remove the CC checker warnings
    jr ra               # Always remember to jr ra after your function!

print_int:
    mv a1, a0
    li a0, 1
    ecall
    jr    ra

print_str:
    mv a1, a0
    li a0, 4
    ecall
    jr    ra

print_newline:
    li a1, '\n'
    li a0, 11
    ecall
    jr    ra
