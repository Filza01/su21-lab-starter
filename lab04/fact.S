.text              
// start code here
.globl main   # linker starts from here 
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial
    la t0, ans
    sw a0, 0(t0)
    j write_tohost

factorial:
    # YOUR CODE HERE
    # value is in a0 
    addi sp, sp, -8
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
// end code here
write_tohost:
li x1, 1
sw x1, tohost, t5
j write_tohost
.data 
// start data section here      
n: .word 3
ans: .word 0
// end data section here
.align 12
.section ".tohost","aw",@progbits;                            
.align 4; .global tohost; tohost: .dword 0;                     
.align 4; .global fromhost; fromhost: .dword 0;
