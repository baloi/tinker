#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

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
       retain its value */
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON); 
    raw.c_oflag &= ~(OPOST); 
    raw.c_cflag |= ~(CS8); 
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG); 
                /* ICANON flag allows us to turn off canonical mode and be 
                reading input byte-by-byte */
    /* set timeout */
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;


    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();

    while (1) {
        char c;
        while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
            if (isprint(c)) {
                printf("%d ('%c')\r\n", c, c);
            } else {
                printf("%d\r\n", c);
            }
        }
        if (c == 'q') break;
    }
    return 0;
}
