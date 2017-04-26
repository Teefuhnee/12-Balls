// ============================================================================
// File Name: ArrSumAndSwap.c
// ============================================================================
// Written by: Tiffany Tran
// Date: 4/24/2017
//
// Description: 
//		This file contains the implementation of ArraySum and SwapBalls.
// ============================================================================
#include "12balls.h"

int		ArraySum(int arr[], int numElems)
{
	auto int		index;
	auto int		sum = 0;

	for (index = 0; index < numElems; ++index) {
		sum += arr[index];
	}

	return sum;
} // end of "ArraySum"



void	SwapBalls(int *ptr1, int *ptr2)
{
	*ptr1 ^= *ptr2;
	*ptr2 ^= *ptr1;
	*ptr1 ^= *ptr2;
} // end of "SwapBalls"