.data
numbers:
        .word 0,0,0,0,0,0,0,0,0,0

.text
main:
        # i in $t0
        li      $t0, 0
while_0:
        bge     $t0, 10, end_0

        li      $v0, 5
        syscall
        move    $t1, $v0

        # &numbers[i] = &numbers + (i * 4)
        # la      $t2, numbers
        # mul     $t3, $t0, 4
        # add     $t4, $t2, $t3
        # sw      $t1, ($t4)

        mul     $t3, $t0, 4
        sw      $t1, numbers($t3)

        addi    $t0, $t0, 1
        j       while_0
end_0:
        li      $v0, 0
        jr      $ra
