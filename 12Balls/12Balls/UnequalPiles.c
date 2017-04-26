// ============================================================================
// File Name: UnequalPiles.c
// ============================================================================
// Written by: Tiffany Tran
// Writen on: 4/24/2017
//
// Description:
//		This file contains the implementation of DiffPiles and ComparingDiff.
// ============================================================================
#include "12balls.h"


Result*	DiffPiles(int arr1[], int arr2[], int swap)
{
	// 3rd ball from first pile switched with 1st ball in second pile
	// 4th ball from first pile switched with 3rd ball in second pile
	SwapBalls(&arr1[2], &arr2[0]);
	SwapBalls(&arr1[3], &arr2[2]);

	auto int	sum1 = ArraySum(arr1, 3);
	auto int	sum2 = ArraySum(arr2, 3);
	auto Result *ptr = malloc(sizeof(Result));

// Comparing sum of balls #1, 2, 5 and # 3, 4, 6
	if (sum1 > sum2)
	{
		ComparingDiff(&ptr, arr1[0], arr1[1]); // comparing #1, 2
		if (swap) {
			ptr->m_result += 4;
		}
		if (!strcmp("lighter", ptr->m_weight)) {
			ptr->m_result = swap ? 2 : 6;
		}
	}

	else if (sum1 < sum2)
	{
		ComparingDiff(&ptr, arr2[0], arr2[2]); // comparing #3, 4

		// to get the correct ball #
		ptr->m_result += 2;
		if (swap) {
			ptr->m_result += 4;
		}
		if (!strcmp("lighter", ptr->m_weight)) {
			ptr->m_result = swap ? 1 : 5;
		}
	}
	else {
		ptr->m_weight = "lighter";
		if (swap) {
			ptr->m_result = arr1[3] > arr2[3] ? 4 : 3;
		}
		else {
			ptr->m_result = arr2[2] > arr2[3] ? 8 : 7;
		}
	}
	return ptr;
} // end of "DiffPiles"



void	ComparingDiff(Result** ptr, int val1, int val2)
{
	if (val1 > val2) {
		(*ptr)->m_weight = "heavier";
		(*ptr)->m_result = 1;
	}
	else if (val1 < val2) {
		(*ptr)->m_weight = "heavier";
		(*ptr)->m_result = 2;
	}
	else {
		(*ptr)->m_weight = "lighter";
	}

} // end of "ComparingDiff"

