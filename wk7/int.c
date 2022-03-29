#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv) {
    uint16_t a = 30000 + 30000;
    printf("%d\n", a);

    int16_t b = 0x8234;
    printf("%d\n", b);
    return EXIT_SUCCESS;
}

// 5
// 0000 0101
//
// -5
// 1111 1010 (flip all bits)
// 1111 1011 (add one)
//
// 6 + -4
// 0000 0110 (6)
// 1111 1100 (-4) (two's complement)
// 0000 0010 (2)
//
// pretend -4 is 1000 0100
// 6 + -4
// 0000 0110 (6)
// 1000 0100 (-4) (flip sign bit)
// 1000 1010
// = -10
//
//
// Represent 0x1234 as a 16 bit two-complement integer
// 0001 0010 0011 0100
// = 4660
//
// Represent 0x8234 as a 16 bit two-complement integer
// 1000 0010 0011 0100 = -(some number) = -32204
// flip all bits
// 0111 1101 1100 1011
// add one
// 0111 1101 1100 1100
// = 32204
