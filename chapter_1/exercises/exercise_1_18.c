/* write a program to remove trailing blanks and tabs from each line of input,
    and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE 1024


void remove_trailing();


int main()
{
    remove_trailing();
}


void remove_trailing()
{
    int c;
    int i, j;
    i = j = 0;
    char buffer[MAXLINE + 1];

    while ((c = getchar()) != EOF) {
        buffer[j++] = c;
        if (!(c == ' ' || c == '\t'))
            i = j;

        if (j == MAXLINE) {
            if (i > 0) {
                buffer[i] = '\0';
                printf("%s\n", buffer);
            }
            i = j = 0;
        }
    }
}