.data
a: .space 3

// if we don't align 2, this program fails
    .align 2
b: .byte 1, 2, 3, 4

.text
main:
        lw      $t0, b
        jr      $ra
