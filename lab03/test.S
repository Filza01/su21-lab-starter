// From riscv-tests and torture repo. See relevant LICENSE for details

#include "riscv_test.h"

RVTEST_RV32M
RVTEST_CODE_BEGIN

	j test_start

crash_backward:
	RVTEST_FAIL

test_start:

    li t0, 0xdeadbeef
    li t1, 0xcafebabe

    j test_end

mtvec_handler:
    csrr t0, mepc
    addi t0, t0, 4
    csrw mepc, t0
    mret

crash_forward:
	RVTEST_FAIL

test_end:
	RVTEST_PASS

RVTEST_CODE_END

  .data
RVTEST_DATA_BEGIN
 
.balign 16
ld_addr:
.dword 0xdeadbeefcafebabe
.dword 0xdeadbeefcafebabe

RVTEST_DATA_END
