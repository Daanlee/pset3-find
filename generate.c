/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // If the number of arguments is not 2 or 3, return an error code and give the correct usage as a mesage to the user
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    //Save the number of random numbers to be generated as an integer from a string
    int n = atoi(argv[1]);

    // iF there are three command line arguments (note that the this is optional), call the srand48() function with the last command line argument
    // as the input(root) to the random number generator function srand48
    // the else part of the function uses the time as a root, allowing it to be more random that choosing root numbers. The format looks like
    // it could be millseconds since 1970. Calling the time() function without putting a time as inputs returns the current time
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
        printf("%ld", time(NULL));
    }

    // Depending on the number n of random numbers, produce that many random numbers
    // drand48() produces a number between [0,1]
    // multiplying drand48() by LIMIT set to the maximum allowed number for a 32 bit integer makes sure that the random output
    // is always in the range allowed by usign an int. It also allows us the maximum resolution for a random integer and therefore
    // will make the likelyhood of two numbers beign the same far less; the number are therefore more random than if we used LIMIT = 10 for
    // a simple example. Finally, if we set LIMIT to one (or omitted it), "all" of the random numbers would be zero unless we mange to get a 1
    // - probabalistically impossible.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) ((drand48()) * LIMIT));
    }

    // success
    return 0;
}