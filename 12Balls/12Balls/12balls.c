// ============================================================================
// File Name: 12balls.c
// ============================================================================
// Written by: Tiffany Tran
// Writen on: 4/21/2017
// Project: 12 Balls
//
// Description:
//		This program contains the algorithm of the 12 Ball Problem which 
//		finds the odd ball in three measurements and weight of it.
//		There are three arrays that represents three piles of the balls and
//		one of them will be a different value, whether it's bigger or smaller
//		than the rest of the balls.
// ============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "12balls.h"
#define	 NUM_BALLS 4

// ==== main ==================================================================
//
// ============================================================================

int		main(void)
{	
	// Three arrays representing three piles with four balls each
	auto int	ballArr1[NUM_BALLS] = { 0, 1, 1, 1 };
	auto int	ballArr2[NUM_BALLS] = { 1, 1, 1, 1 };
	auto int	ballArr3[NUM_BALLS] = { 1, 1, 1, 1 };

	auto int		sum1; 
	auto int		sum2;
	auto Result*	resultPtr;
	auto int		index;
	auto int		swapped = 0;  // flag if piles were swapped

	// Getting the weights of the first two piles
	sum1 = ArraySum(ballArr1, NUM_BALLS);
	sum2 = ArraySum(ballArr2, NUM_BALLS);

	// If the first two piles are equal, then odd ball is in the third pile
	if (sum1 == sum2)
		{
		resultPtr = EqualPiles(ballArr1, ballArr3);
		}
	// Odd ball is in first/second pile
	else if (sum1 > sum2)
		{
		resultPtr = DiffPiles(ballArr1, ballArr2, swapped);
		}
	// The two piles will be swapped so the same func can be used
	else 
		{
		for (index = 0; index < NUM_BALLS; ++index) {
			SwapBalls(&ballArr1[index], &ballArr2[index]);
			}
		swapped = 1;
		resultPtr = DiffPiles(ballArr1, ballArr2, swapped);
		}

	printf("Ball %d was the %s ball.\n", resultPtr->m_result, resultPtr->m_weight);
	free(resultPtr);
	return 0;
} // end of "main"
