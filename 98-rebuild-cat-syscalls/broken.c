#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 4096

void print_error(const char *msg) {
    write(STDERR_FILENO, msg, strlen(msg));
    write(STDERR_FILENO, "\n", 1);
}

int cat_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        print_error("Error: cannot open file");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // BUG: Only reads once instead of looping until EOF
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        print_error("Error: cannot read file");
        close(fd);
        return -1;
    }

    // BUG: Should check return value of write and handle partial writes
    write(STDOUT_FILENO, buffer, bytes_read);

    close(fd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: cat <filename>");
        return 1;
    }

    return cat_file(argv[1]);
}
