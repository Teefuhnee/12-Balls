// ============================================================================
// File Name: EqualPiles.c
// ============================================================================
// Written by: Tiffany Tran
// Date: 4/24/2017
//
// Description:
//		This file contains the implementation of EqualPiles and ComparingEqual.
// ============================================================================
#include "12balls.h"

Result* EqualPiles(int arr1[], int arr3[])
{
	auto Result		*ptr = malloc(sizeof(Result));
	auto int		sum1 = ArraySum(arr1, 3); // The sums of three balls
	auto int		sum3 = ArraySum(arr3, 3); // Fourth ball in 3rd pile left out

											  // If true, the odd ball is lighter
	if (sum1 > sum3)
	{
		ptr->m_weight = "lighter";
		ComparingEqual(&ptr, arr3[0], arr3[1]);
	}

	// If true, the odd ball is heavier
	else if (sum1 < sum3)
	{
		ptr->m_weight = "heavier";
		ComparingEqual(&ptr, arr3[0], arr3[1]);
	}

	else // If true, the fourth ball is odd
	{
		ptr->m_result = 4;
		ptr->m_weight = "equal";
		ComparingEqual(&ptr, arr1[0], arr3[3]);
	}
	ptr->m_result += 8; // to get the correct ball #
	return ptr;

} // end of "EqualPiles"


void	ComparingEqual(Result** ptr, int val1, int val2)
{

	// Comparing to get the lighter ball
	if (!(strcmp("lighter", (*ptr)->m_weight)))
	{
		if (val1 < val2) { // If true -> 1st ball of pile
			(*ptr)->m_result = 1;
		}
		else if (val1 > val2) { // If true -> 2nd ball of pile
			(*ptr)->m_result = 2;
		}
		else { // If true -> 3rd ball of pile
			(*ptr)->m_result = 3;
		}
	}

	// Comparing to get the heavier ball
	else if (!(strcmp("heavier", (*ptr)->m_weight)))
	{
		if (val1 > val2) { // If true -> 1st ball of pile
			(*ptr)->m_result = 1;
		}
		else if (val1 < val2) { // If true -> 2nd ball of pile
			(*ptr)->m_result = 2;
		}
		else { // If true -> 3rd ball of pile
			(*ptr)->m_result = 3;
		}
	}

	// Comparing to see if odd ball is heavier/lighter
	else
	{
		if (val1 > val2) {
			(*ptr)->m_weight = "lighter";
		}
		else {
			(*ptr)->m_weight = "heavier";
		}
	}
} // end of "ComparingEqual"