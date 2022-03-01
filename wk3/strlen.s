.data
string:
        .asciiz "abcdefgabv"

.text
main:
        # *s is $t0
        # length is $t1
        la      $t0, string
        li      $t1, 0
while_0:
        # $t0 has address of string[i]
        # we need to compare the value
        # could also do lb      $t2, string($t1)
        lb      $t2, ($t0)
        beq     $t2, '\0', end_0

        addi    $t1, $t1, 1
        addi    $t0, $t0, 1
        j       while_0
end_0:
        # print length
        li      $v0, 1
        move    $a0, $t1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        li      $v0, 0
        jr      $ra
