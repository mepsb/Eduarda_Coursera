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
 * @file <stats.h> 
 * @brief <Declarations and documentation for the functions from the stats.c file>
 *
 * @author <Eduarda Barbosa>
 * @date <22/08/2023>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Function to print the elements of an array>
 *
 * @param <Array named data> <array that contains the dataset that will be analyzed>
 * @param <Length> <number of elements that the array contains>
 *
 * @return <I opted for a void function, so it return anything, only prints the array when the function is called.>
 */

void print_array(unsigned char data[], int length);

/**
 * @brief <Function to find the median value of an array>
 *
 * @param <Array named data> <array that contains the dataset that will be analyzed>
 * @param <Length> <number of elements that the array contains>
 *
 * @return <Returns a float that has the median value of the array.>
 */
float find_median(unsigned char data[], int length);

/**
 * @brief <Function to find the mean value of an array>
 *
 * @param <Array named data> <array that contains the dataset that will be analyzed>
 * @param <Length> <number of elements that the array contains>
 *
 * @return <Returns a float that has the mean value of the array.>
 */
float find_mean(unsigned char data[], int length);

/**
 * @brief <Function to find the maximum value of an array>
 *
 * @param <Array named data> <array that contains the dataset that will be analyzed>
 * @param <Length> <number of elements that the array contains>
 *
 * @return <Returns a unsigned char that contains the max value of the array.>
 */
unsigned char find_maximum(unsigned char data[], int length);

/**
 * @brief <Function to find the minnimum value of an array>
 *
 * @param <Array named data> <array that contains the dataset that will be analyzed>
 * @param <Length> <number of elements that the array contains>
 *
 * @return <Returns a unsigned char that contains the min value of the array.>
 */
unsigned char find_minimum(unsigned char data[], int length);

/**
 * @brief <Function to sort an array in descending order >
 *
 * @param <Array named data> <array that contains the dataset that will be analyzed>
 * @param <Length> <number of elements that the array contains>
 *
 * @return <It's a void function, so it won't return anything. But will sort the array in descending order>
 */
void sort_array(unsigned char data[], int length);

#endif /* __STATS_H__ */
