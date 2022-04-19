#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void thread_function(void *arg) {
    while (1) {
        printf("%s\n", (char *)arg);
    }
    /* return NULL; */
}

int main(int argc, char **argv) {
    pthread_t threadid;
    pthread_create(&threadid, NULL, (void *)thread_function, "thread");

    while (1) {
        printf("Hello\n");
    }

    return EXIT_SUCCESS;
}
