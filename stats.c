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
 * @brief <Statistial Analytics on a Dataset>
 *
 * <Analyzis of an array of unsigned char data items and report analytics on the maximum, minimum, mean, and median of the data set.>
 *
 * @author <Eduarda Barbosa>
 * @date <22/08/2023>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/* Add other Implementation File Code Here */
void print_array(unsigned char data[], int length)
{
  for( int i = 0; i < length; i++)
  {
      printf("%u ", data[i]);
  }
}

// Compare function used for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float find_median(unsigned char data[], int length)
{
  // Sort the array
  qsort(data, length, sizeof(int), compare);

  // Calculate the median
  if (length % 2 == 1) {
      return data[length / 2];
  } else {
      int middle1 = data[length / 2 - 1];
      int middle2 = data[length / 2];
      return (float)(middle1 + middle2) / 2;
}
}

float find_mean(unsigned char data[], int length)
{
  int count = 0, sum = 0; 
  
  for(int i = 0; i < length; i++)
  {
      sum+=data[i];
      count++; 
  }

  return (float)sum/count;
}

unsigned char find_maximum(unsigned char data[], int length)
{
  unsigned char max = data[0];

  for(int i = 1; i < length; i++)
  {
    if (data[i] > max) max = data[i];
  }

  return max;
}


unsigned char find_minimum(unsigned char data[], int length)
{
  unsigned char min = data[0];

  for(int i = 1; i < length; i++)
  {
    if (data[i] < min) min = data[i];
  }

  return min;
}


void sort_array(unsigned char data[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (data[i] < data[j]) {
                unsigned char temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  float median_value = find_median(test, SIZE);
  float mean_value = find_mean(test, SIZE);
  unsigned char min_value = find_minimum(test, SIZE);
  unsigned char max_value = find_maximum(test,SIZE);
  sort_array(test, SIZE);

  printf("\nThe mean value of this array is: %.2f.", mean_value);
  printf("\nThe median value of this array is: %.2f.", median_value);
  printf("\nThe minimum value of this array is: %.2f.", min_value);
  printf("\nThe maximum value of this array is: %.2f.", max_value);

}

