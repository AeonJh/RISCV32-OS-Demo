#include "user.h"


void main(void) {
    while (1) {
prompt:
        printf("> ");
        char cmdline[128];
        for (int i = 0;; i++) {
            char ch = getchar();
            if (ch == 127) {
                if (i > 0) {
                    printf("\b \b");  // Move cursor back, print space, move cursor back again
                    i -= 2;           // Adjust index (subtracting 2 because loop will increment i)
                } else {
                    i--;              // Prevent underflow by canceling the loop's increment
                }
            } else if (i == sizeof(cmdline) - 1) {
                printf("\nCommand line too long! T_T\n");
                goto prompt;
            } else if (ch == '\r') {
                printf("\n");
                cmdline[i] = '\0';
                break;
            } else {
                putchar(ch);
                cmdline[i] = ch;
            }
        }

        if (strcmp(cmdline, "hello") == 0)
            printf("Hello, world form shell!\n");
        else if (strcmp(cmdline, "readfile") == 0) {
            char buf[128];
            int len = readfile("hello.txt", buf, sizeof(buf));
            buf[len] = '\0';
            printf("%s\n", buf);
        }
        else if (strcmp(cmdline, "writefile") == 0) {
            writefile("hello.txt", "Hello from shell!\n", 19);
        }
        else if (strcmp(cmdline, "exit") == 0)
            exit();
        else
            printf("Unknown command: %s\n", cmdline);
    }
}
