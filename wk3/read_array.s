.data
numbers:
        .word 0,1,2,3,4,5,6,7,8,9

.text
main:
        # i in $t0
        li      $t0, 0
while_0:
        bge     $t0, 10, end_0

        # &numbers[i] = &numbers + (i * 4)
        # la      $t2, numbers
        # mul     $t3, $t0, 4
        # add     $t4, $t2, $t3
        # lw      $t1, ($t4)

        mul     $t3, $t0, 4
        lw      $t1, numbers($t3)

        li      $v0, 1
        move    $a0, $t1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 1
        j       while_0
end_0:
        li      $v0, 0
        jr      $ra
