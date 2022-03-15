#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv) {
    int w = 15; // w = 0b1111
    int x = 0xf; // x = 0b1111
    // 1 * 8^1 + 7 * 8^0 = 15
    int y = 017; // y = 0b1111
    int z = 0b1111; // z = 0b1111

    printf("%d %d %d %d\n", w, x, y, z);


    uint16_t a = 0x5555, b = 0xAAAA, c = 0x0001;
    // 0 = 0b0000
    // F = 0b1111
    // 5 in binary = 2^2 + 2^0
    // A in decimal = 10
    // 10 in binary = 8 + 2 = 2^3 + 2^1
    // a = 0b0101010101010101
    // b = 0b1010101010101010
    // r = 0b1111111111111111 = 0xFFFF
    printf("a | b = 0x%04x\n", a | b);

    // a = 0b0101010101010101
    // b = 0b1010101010101010
    // r = 0b0000000000000000
    printf("a & b = 0x%04x\n", a & b);

    // a = 0b0101010101010101
    // c = 0b0000000000000001
    // r = 0b0101010101010100
    printf("a ^ c = 0x%04x\n", a ^ c);

    // a = 0b0101010101010101
    //~b = 0b0101010101010101
    // r = 0b0101010101010101
    printf("a & ~b = 0x%04x\n", a & ~b);

    // c = 0b0000000000000001
    // r = 0b0000000001000000
    printf("c << 6 = 0x%04x\n", c << 6);

    // b = 0b1010101010101010
    // r = 0b0101010101010100 = 0x5554
    // uint16_t b should be 16 bits long
    // ints are 32 bits long
    // the expression b << 1 gets turned into an integer
    printf("b << 1 = 0x%04x\n", b << 1); // prints 0x15554
    printf("b << 1 = 0x%04x\n", (uint16_t)(b << 1)); // prints 0x5554

    uint16_t e = b << 1;
    printf("e << 1 = 0x%04x\n", e); // prints 0x5554

    return EXIT_SUCCESS;
}
