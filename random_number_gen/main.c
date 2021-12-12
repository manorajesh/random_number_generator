#include <stdio.h>
#include <time.h>

#define MAXLINE 1000        // Max length of output
#define CHARLENGTH 44       // Max length of available characters 

void keygen(long int seed1, long int seed2, char key[]);

int counter = 0;            // Multi-function variable to maintain array position

int main(void)
{
    int c;                  // Largely unnecessary variable (stores character from stdin)
    long int i, l = 0;      // Random numbers
    char key[MAXLINE];      // Output character array

    printf(">");
    i = clock();            // Cycles since epoch
    while ((c = getchar()) != '\n' || counter > MAXLINE) {
        i += clock();       // Adding previous random number greatly increases entropy
        l += clock();
        keygen(i, l, key);
    }

    printf("\n\n%s\n", key);
}

void keygen(long int randnum1, long int randnum2, char key[])
{
    char avaichar[CHARLENGTH] = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%&?/"; // characters available when generating

    key[counter++] = avaichar[(randnum1 + randnum2) % CHARLENGTH];  // Adding greatly increases entropy
    // printf("\n%ld, %ld, %ld\n", randnum1, randnum2, ((randnum1+randnum2)%CHARLENGTH));   // debugging (shows pattern)
    printf("\n%ld\n", ((randnum1 + randnum2) % CHARLENGTH));
}