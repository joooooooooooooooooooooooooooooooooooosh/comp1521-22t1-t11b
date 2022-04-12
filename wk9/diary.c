#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // 1. get the value of $HOME
    char *home = getenv("HOME");

    // 2. append '/.diary' to $HOME
    char path[100];
    snprintf(path, 100, "%s%s", home, "/.diary");

    // 3. open that file
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        perror(path);
        return EXIT_FAILURE;
    }

    // 4. print contents to stdout
    int byte;
    while ((byte = fgetc(f)) != EOF) {
        fputc(byte, stdout);
    }

    fclose(f);
    return EXIT_SUCCESS;
}
