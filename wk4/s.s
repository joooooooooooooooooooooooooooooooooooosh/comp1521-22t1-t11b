main:
main_prologue:
        begin
        push    $ra
        push    $s0

main_body:
        # i in s0
        li      $s0, 0

        # call foo()
        # jal modifies $ra so that foo knows
        # where to jump back to
        jal     foo

        # printf("%d\n", i)
        li      $v0, 1
        # ^-- $ra points to here from jal
        move    $a0, $s0
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        # return 0
        li      $v0, 0
main_epilogue:
        pop     $s0
        pop     $ra
        end
        jr      $ra


foo:
foo_prologue:
        begin
        push    $s0

foo_body:
        # i in s0
        li      $s0, 1

foo_epilogue:
        pop     $s0
        end
        jr      $ra
