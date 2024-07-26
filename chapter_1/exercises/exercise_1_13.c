/* Write a program to print a histogram of the lengths of words in its input.
    Make both a horizontal and a vertical version. */

#include <stdio.h>

#define MAX_WORD_LEN 1024


void words_histogram_h();
void words_histogram_v();


int main() {
    // words_histogram_h();
    words_histogram_v();
    return 0;
}


void words_histogram_h()
{
    // count word frequencies
    int lengths[MAX_WORD_LEN] = {0};

    int c, l = 0;
    while ((c = getchar()) != EOF) {
        if ((c == '\n' || c == '\t' || c == ' ') && l > 0) {
            lengths[l - 1]++;
            l = 0;
        } else {
            l++;
        }
    }

    // print rows
    for (int l = 0; l < MAX_WORD_LEN; l++) {
        if (lengths[l] == 0)
            continue;

        printf("%5d ", l + 1);
        for (int i = 0; i < lengths[l]; i++)
            putchar('*');
        putchar('\n');
    }
}

void words_histogram_v()
{
    // count word frequencies
    int lengths[MAX_WORD_LEN] = {0};

    int c, l = 0;
    while ((c = getchar()) != EOF) {
        if ((c == '\n' || c == '\t' || c == ' ') && l > 0) {
            lengths[l - 1]++;
            l = 0;
        } else {
            l++;
        }
    }

    // find maximum frequency
    int max = 0;
    for (int i = 0; i < MAX_WORD_LEN; i++)
        if (lengths[i] > max)
            max = lengths[i];

    // print columns
    for (; max > 0; max--) {
        for (int i = 0; i < MAX_WORD_LEN; i++) {
            if (lengths[i] >= max)
                printf("%5c", '*');
            else
                printf("%5c", ' ');
        }
        putchar('\n');
    }

    // print numbers
    for (int i = 0; i < MAX_WORD_LEN; i++)
        if (lengths[i] > 0)
            printf("%5d", i + 1);
    putchar('\n');
}