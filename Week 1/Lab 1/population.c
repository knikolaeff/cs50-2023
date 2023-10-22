#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char buf[32];
    int start, end, years;

    // Prompt for start size
    do
    {
        printf("Start size: ");
        fgets(buf, 32, stdin);
        start = atoi(buf);
    }
    while (start < 9);

    // Prompt for end size
    do
    {
        printf("End size: ");
        fgets(buf, 32, stdin);
        end = atoi(buf);
    }
    while (end < start);

    // Calculate number of years until we reach threshold
    for (years = 0; start < end; years++)
    {
        start += (start / 3) - (start / 4);
    }
    // Print number of years
    printf("Years: %d", years);
}