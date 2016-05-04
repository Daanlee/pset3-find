/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include <math.h>

/**
 * Returns true if value is in array of n values, else false.
 */
 //Loop runs log(n) times maximum - 
bool search(int value, int values[], int n)
{
    //Binary search for sorted array values[]
    int middle = (n+1)/2;
    int min = 0;
    int max = n-1;
    //double index = log2(n);
    //int n2 = (int) (index+0.5);
    while (min<=max)
    {
        if(value > values[middle])
        {
            min = middle+1;
        }
        else if(value < values[middle])
        {
            max = middle-1;
        }
        else if (value==values[middle])
        {
            return true;
        }
        middle = (min+max)/2;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    //Try inplement a bubble sort?
    int temp;//allows us to swap the values of two indices of thh array
    bool swap;//check whether swaps have been done, if not, we are sorted, break
    for(int i = 0; i <n ; i++)
    {//Need a possible max number of loops of n*n
        for (int j = 0; j<n-1 ; j++)
        {
            swap = false;
            if(values[j]>values[j+1])
            {
                swap = true;
                //Compare values. If they are in the wrong order, swap them
                //Continue until no swaps are made
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        //if there are no swaps in an iteration, we are done
        //}if (!swap)
        //{
        //    break;
        }
    }
    //for (int z = 0; z<n;z++)
    //{
    //    printf("%i\n", values[z]);
    //}
    return;
}