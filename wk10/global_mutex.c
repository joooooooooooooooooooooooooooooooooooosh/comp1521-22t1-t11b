#include <stdio.h>
#include <pthread.h>

// in MIPS:
// global_total_label: .word 0
int global_total = 0;
pthread_mutex_t global_total_mutex = PTHREAD_MUTEX_INITIALIZER;

void *add_5000_to_counter(void *data) {
    // could put a mutex_lock here but it's around twice as slow
    // pthread_mutex_lock(&global_total_mutex);
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
        
        pthread_mutex_lock(&global_total_mutex);
        global_total++;
        pthread_mutex_unlock(&global_total_mutex);
    }
    // pthread_mutex_unlock(&global_total_mutex);

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
