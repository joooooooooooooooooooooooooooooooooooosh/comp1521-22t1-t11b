#include <stdio.h>
#include <stdlib.h>

#define READING   0x01 // 0b0000 0001
#define WRITING   0x02 // 0b0000 0010
#define AS_BYTES  0x04 // 0b0000 0100
#define AS_BLOCKS 0x08 // 0b0000 1000
#define LOCKED    0x10 // 0b0001 0000

// unsigned char flags = 0b0001 1111 // all flags are on

int main(int argc, char **argv) {
    unsigned char device = 0;

    // mark the device as locked for reading bytes
    // turn on LOCKED and READING and AS_BYTES
    // not good practice, hard to read and debug
    device = 0b00010101;

    // mark the device as locked for writing blocks
    // device = 0b00011010
    // need a more readable version
    device = LOCKED;  // device = 0b0001 0000
    // device = WRITING; // device = 0b0000 0010 we've lost the LOCKED flag


    // a = a + 1 and a += 1 are equivalent
    // device = device | WRITING and device |= WRITING are equivalent

    // device  = 0b0001 0000
    // WRITING = 0b0000 0010
    // result  = 0b0001 0010
    device |= WRITING;
    device |= AS_BLOCKS;

    // alternative: device = LOCKED | WRITING | AS_BLOCKS

    // remove the lock on a device, leaving other flags unchanged
    // device  = 0b0001 1010
    // ~LOCKED = 0b1110 1111
    // result  = 0b0000 1010
    device &= ~LOCKED;

    // switch a device from writing to reading, leaving other flags unchanged
    // device currently = WRITING | AS_BLOCKS
    // device = 0b0000 1010
    // result = 0b0000 1001

    device &= ~WRITING;
    device |= READING;

    // toggle a device being locked, leaving other flags unchanged
    // 2 cases:
    // device = 0b0001 1010 || device = 0b0000 1010
    // LOCKED = 0b0001 0000 || LOCKED = 0b0001 0000
    // result = 0b0000 1010 || result = 0b0001 1010 
    device ^= LOCKED;

    // swap a device between reading and writing, leaving other flags unchanged
    // 2 cases:
    // device = 0b0000 1010 || device = 0b0000 1001
    // ?????? = 0b0000 0011 || ?????? = 0b0000 0011
    // result = 0b0000 1001 || result = 0b0000 1010 
    // WRITING | READING = 0b0000 0011
    device ^= (WRITING | READING);


    return EXIT_SUCCESS;
}
