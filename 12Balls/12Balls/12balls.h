// ============================================================================
// File Name: 12balls.h
// ============================================================================
// Written by: Tiffany Tran
// Writen on: 4/24/2017
//
// Description:
//		This is the header file of 12balls.c. It contains the structure that
//		holds the weight and odd ball number, and prototypes. 
// ============================================================================

typedef
struct Result
{
	char	*m_weight;	   // contains "heavier"/"lighter" 
	int		m_result;	   // contains ball #
}Result;

// Function prototypes

// ==== EqualPiles ============================================================
//
// This function does a 2nd comparison between two piles with three balls each
// when the 1st comparison with the eight balls were equal.
// Input:
//      arr1 [IN] -- the base address of the first pile, which contains the
//				  normal balls
//		arr3 [IN] -- the base address of the third pile, which contains the 
//				  odd ball
//
// Output:
//      A pointer to struct Result is returned, containing the weight and
//		the ball number of the odd ball (#9-12).
//
// ============================================================================
Result*	EqualPiles(int arr1[], int arr3[]);


// ==== ComparingEqual ========================================================
//
// This function does a 3rd comparison between two balls. If the weight was 
// known from the 2nd comparison, then the corresponding weight will decide
// which ball is the odd one. If the weight was unknown, then the odd ball
// is known (#12) and will be compared with another ball to get the weight.
//
// Input:
//      Result** [IN/OUT] -- a  pointer to a struct Result pointer;
//							 the weight or the number of the odd ball 
//							 will be updated
//		val1 [IN] -- an integer that represents a ball that's being compared
//		val2 [IN] -- an integer that represents a ball that's being compared
//
// Output:
//      Nothing is retured.
//
// ============================================================================
void	ComparingEqual(Result** ptr, int val1, int val2);


// ==== DiffPiles ============================================================
//
// This function does a 2nd comparison between two piles with three balls each
// when the 1st comparison with the eight balls were unequal.
// Input:
//      arr1 [IN] -- the base address of the first pile
//		arr2 [IN] -- the base address of the second pile
//		swap [IN] -- an integer that is set if the 1st comparison 
//					 needed the piles to switch
//
// Output:
//      A pointer to struct Result is returned, containing the weight and
//		the ball number of the odd ball (#1-8)
//
// ============================================================================
Result*	DiffPiles(int arr1[], int arr2[], int swap);


// ==== ComparingDiff =========================================================
//
// This function does a 3rd comparison between two balls for the heavier ball
// and returns the ball number. Unless the balls are equal, then the odd ball 
// will be lighter.
//
// Input:
//      Result** [IN/OUT] -- a  pointer to a struct Result pointer;
//							 the weight or the number of the odd ball 
//							 will be updated
//		val1 [IN] -- an integer that represents a ball that's being compared
//		val2 [IN] -- an integer that represents a ball that's being compared
//
// Output:
//      Nothing is retured.
//
// ============================================================================
void	ComparingDiff(Result** ptr, int val1, int val2);


// ==== ArraySum ==============================================================
//
// This function receives the address of an array and the number of elements
// to indicate how many numbers to add.
//
// Input:
//      arr [IN]   -- the input array's address
//		numElems [IN] -- an integer containing number of elements to be added
//
// Output:
//		The sum of the array is returned.
//
// ============================================================================
int		ArraySum(int arr[], int numElems);


// ==== SwapBalls ============================================================
//
// This function receives the addresses of two integers and swaps the values.
//
// Input:
//      ptr1* [IN/OUT] -- a pointer to an int containing the value of a ball
//		ptr2* [IN/OUT] -- a pointer to an int containing the value of 
//						  another ball
// Output:
//		Nothing is returned.
//
// ============================================================================
void	SwapBalls(int *ptr1, int *ptr2);
