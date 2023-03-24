/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c>
 * @brief <This is a stats.c file generated by Anthony Pipitone>
 *
 * <simple stats code>
 *
 * @author <Anthony Pipitone>
 * @date <3/24/23>
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "stats.h"
#define SIZE 40
int main()
{
    unsigned char test_data[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6,
                                    114, 88, 45, 76, 123, 87, 25, 23,
                                    200, 122, 150, 90, 92, 87, 177, 244,
                                    201, 6, 12, 60, 8, 2, 5, 67,
                                    7, 87, 250, 230, 99, 3, 100, 90};
    printf("Input Array:\n");
    print_array(test_data, SIZE);
    printf("\nStatistics:\n");
    print_statistics(test_data, SIZE);
    printf("\nSorted Array:\n");
    sort_array(test_data, SIZE);
    print_array(test_data, SIZE);
    return 0;
}
void print_statistics(unsigned char* r_a, unsigned int length)
{
    printf("Minimum: %d\n", find_minimum(r_a, length));
    printf("Maximum: %d\n", find_maximum(r_a, length));
    printf("Mean: %d\n", find_mean(r_a, length));
    printf("Median: %d\n", find_median(r_a, length));
}
void print_array(unsigned char* r_a, unsigned int length)
{
    printf("[ ");
    for(int i=0; i<length; i++)
    {
        printf("%d ", r_a[i]);
    }
    printf("]\n");
}
unsigned char find_median(unsigned char* r_a, unsigned int length)
{
    sort_array(r_a, length);
    if(length%2 == 0)
    {
        return (r_a[length/2 - 1] + r_a[length/2])/2;
    }
    else
    {
        return r_a[length/2];
    }
}
unsigned char find_mean(unsigned char* r_a, unsigned int length)
{
    unsigned int sum = 0;
    for(int i=0; i<length; i++)
    {
        sum += r_a[i];
    }
    return (unsigned char)(sum/length);
}
unsigned char find_maximum(unsigned char* r_a, unsigned int length)
{
    unsigned char max = r_a[0];
    for(int i=1; i<length; i++)
    {
        if(r_a[i] > max)
        {
            max = r_a[i];
        }
    }
    return max;
}
unsigned char find_minimum(unsigned char* r_a, unsigned int length)
{
    unsigned char min = r_a[0];
    for(int i=1; i<length; i++)
    {
        if(r_a[i] < min)
        {
            min = r_a[i];
        }
    }
    return min;
}
void sort_array(unsigned char* r_a, unsigned int length)
{
    for(int i=0; i<length-1; i++)
    {
        for(int j=i+1; j<length; j++)
        {
            if(r_a[j] > r_a[i])
            {
                unsigned char temp = r_a[i];
                r_a[i] = r_a[j];
                r_a[j] = temp;
            }
        }
    }
}