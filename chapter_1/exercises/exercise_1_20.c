/* write a program 'detab' that replaces tabs in the input with the proper number of blanks
    to space to the next tab stop. Assume a fixed set of tab stops, say every 'n' columns. */

#include <stdio.h>
#define TAB_SPACES 4

int main() {
    int c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (; i < TAB_SPACES; i++)
                putchar(' ');
            i = 0;
        } else if (c == '\n') {
            putchar(c);
            i = 0;
        } else {
            putchar(c);
            i = (i + 1) % TAB_SPACES;
        }
    }
}