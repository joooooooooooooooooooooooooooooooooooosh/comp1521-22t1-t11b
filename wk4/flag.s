        .data
flag:
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

        .text
main:

        # row in $t0
        li      $t0, 0
for_0:
        bge     $t0, 6, end_0

        # col in $t1
        li      $t1, 0
for_1:
        bge     $t1, 12, end_1

        # get flag[row][col] into $a0
        # step 1: get addr of flag[row]
        # &flag[row] = &flag + row * sizeof(char[12])
        #            = &flag + row * 12
        la      $t2, flag
        mul     $t3, $t0, 12
        add     $t4, $t2, $t3

        # step 2: get addr of flag[row][col]
        # &flag[row][col] = &flag[row] + col * sizeof(char)
        # &flag[row][col] = &flag[row] + col * 1

        add     $t5, $t4, $t1

        # step 3: load byte from flag[row][col] into $a0
        # printf ("%c", flag[row][col]);
        li      $v0, 11
        lb      $a0, ($t5)
        syscall

        addi    $t1, $t1, 1
        b       for_1
end_1:
        # printf("\n");
        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 1
        b       for_0
end_0:
        # return 0
        li      $v0, 0
        jr      $ra
