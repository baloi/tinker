#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct termios orig_termios; /* save terminal's original attributes */

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {

    /* entering raw mode where keypresses will not be echoed on the
       terminal. To get out of it and see what you are typing again,
       press

       Ctrl-c ENTER
       type "reset" ENTER
    */
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    /* we use the NOT operator to set the ECHO bitflag and then use the bitwise
       AND flag to set the fourth bit to zero and causes every other bit to
       retain its value
    */
    raw.c_lflag &= ~(ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');

    return 0;
}
