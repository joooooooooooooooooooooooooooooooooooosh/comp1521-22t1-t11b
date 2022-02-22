main:
        # x = $t0
        li      $t0, 24

for_0:
        bge     $t0, 42, end_0

        li      $v0, 1
        move    $a0, $t0
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 3
        j       for_0

end_0:
        li      $v0, 0
        jr      $ra
