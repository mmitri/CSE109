#include <stdbool.h>
#include <unistd.h>

bool file_exists(char* path) {
    // We only need to use the X_OK flag, which tests if the file is executable
    // If the file does not exist, it is going to fail this. If the file exists
    // but is not executable, it will also fail this.
    if (access(path, X_OK) == 0) {
        return true;
    } else {
        return false;
    }
}
