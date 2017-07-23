#include <unistd.h>
int main() {
    /* clears the screen */
    write(STDOUT_FILENO, "\x1b[2J", 4);
    /* brings cursor back to top */
    //write(STDOUT_FILENO, "\x1b[H", 3);

    return 0;
}
