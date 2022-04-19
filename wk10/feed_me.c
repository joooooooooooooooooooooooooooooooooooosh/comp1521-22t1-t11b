#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *feed_me() {
    while (1) {
        puts("feed me input!");
        sleep(1);
    }
}

int main(int argc, char **argv) {
    pthread_t thread;
    pthread_create(&thread, NULL, feed_me, NULL);

    char str[50];
    while (scanf("%50s", str) != EOF) {
        pthread_cancel(thread);
        printf("you entered: %s\n", str);
    }

    return EXIT_SUCCESS;
}
