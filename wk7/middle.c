#include <stdio.h>
#include <stdlib.h>

// 1000 1000 1000 1000 1000 1000 1000 1000
// 0000 0000 0000 0111 111 = 0b0011 1111 = 0x3f
// 0000 0000 0000 0000 100
//                 ^     ^                
int middle_six_bits(int32_t x) {
    x >>= 13;
    x &= 0x3f;
    return x;
}

int main(int argc, char **argv) {
    printf("%d\n", middle_six_bits(0x88888888));
    return EXIT_SUCCESS;
}
