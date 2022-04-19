#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

// in MIPS:
// global_total_label: .word 0
atomic_int global_total = 0;

void *add_5000_to_counter(void *data) {
    for (int i = 0; i < 5000; i++) {
        // sleep for 1 nanosecond
        nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);
        
        // increment the global total by 1
        // in MIPS:
        // // global_total in t0
        // lw   $t0, global_total_label
        // <--- switch here?
        // addi $t0, $t0, 1
        // <--- switch here?
        // sw   $t0, global_total_label
        
        atomic_fetch_add(&global_total, 1); // safe
        // global_total++; // safe
        // global_total += 1; // safe
        // global_total = global_total + 1; // unsafe
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_5000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_5000_to_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // if program works correctly, should print 10000
    printf("Final total: %d\n", global_total);
}
