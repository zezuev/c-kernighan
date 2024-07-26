/* write a program to print all input lines that are longer than 80 characters */

#include <stdio.h>
#define MINLINE 81


void print_long_lines();


int main()
{
    print_long_lines();
    return 0;
}


void print_long_lines()
{
    int c;
    int i = 0;
    char buffer[MINLINE];
    buffer[MINLINE - 1] = '\0';

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            if (i > 0)
                putchar(c);
            i = 0;
            continue;
        }

        if (i < MINLINE - 1) {
            buffer[i] = c;
        } else if (i == MINLINE - 1) {
            printf("%s", buffer);
            putchar(c);
        } else {
            putchar(c);
        }
        i++;
    }
}