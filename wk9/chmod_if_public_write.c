#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void chmod_if_public_write(char *path);

int main(int argc, char **argv) {
    // call chmod_if_public_write on every argument
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_public_write(argv[arg]);
    }
    return EXIT_SUCCESS;
}

void chmod_if_public_write(char *path) {
    struct stat info;
    if (stat(path, &info) != 0) {
        perror(path);
        return;
    }

    // 0111
    // 0010
    // XOR
    // 0101

    mode_t mode = info.st_mode;
    if ((mode & S_IWOTH) != 0) {
        // publically writeable
        printf("removing public write from %s\n", path);
        mode ^= S_IWOTH;
        if (chmod(path, mode) != 0) {
            perror(path);
            return;
        }
    } else {
        printf("%s is not publically writeable\n", path);
    }
}
