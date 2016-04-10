// Do algorithm Routine
#include <stdio.h>

int add_ordered(int i, int k, int* best);
int compareAndSwap(int i , int j, int k, int* best);



int doalg(int n, int k, int* best)
{
	// n -> number of elements in array
	// k -> size 


	// Initialize best array to -1
	int i; 
	for ( i = 0; i < n; i++) { best[i] = -1; }

	// Iterate over each index in array and test to see if it belongs in best
	for ( i = 1; i <= k; i++ ) 
	{
		add_ordered(i, k, best);
		//printf("%d\n", i);
	}

	// // // print out shit
	// for ( i = 1; i < k; i++)
	// {
	// 	printf("%d\n", best[i]);
	// 	COMPARE(-69, best[i]);
	// }

	// COMPARE(-68,11);


	for ( i = k+1; i <= n; i++ )
	{
		add_ordered(i, k, best);
		//printf("%d\n", i);
	}

	// // print out shit
	// for ( i = 0; i < k; i++)
	// {
	// 	//printf("%d\n", best[i]);
	// 	COMPARE(-69, best[i]);
	// }






	return 1;
}

int add_ordered( int outsideIndex, int k, int* best)
{
	// Returns 0 -> Value Was Not Added
	//         1 -> Value Was Added


	// Compares Index values to see if outsideIndex belongs in best array
		// Starts at end of best array * Lowest Values
	if ( best[k-1] == -1 || COMPARE(best[k-1], outsideIndex) == 2 )
	{
		best[k-1] = outsideIndex;
	}
	else
	{
		// Return Do not need to percolate value up was not added to array
		return 0;
	}



	// If Index value was placed in last index of array now percolate up.
	int i;

	for ( i = k-1; i > 0; i--)
	{
		//printf("i: %d, j: %d\n", i-1, i);
		if ( compareAndSwap(i-1, i, k, best) == 0 )
		{
			// if compareAndSwap returns 0 the value was not swapped
			// no further comparisons need to be made
			//printf("Broke Early\n");
			return 1; 
		}
	}

	//printf("Added to 0 index\n");


}

int compareAndSwap(int i, int j, int k, int* best)
{
	if ( best[i] == -1 || COMPARE(best[i], best[j]) == 2 )
	{
		//printf("                Swap\n");

		int temp = best[i];
		best[i] = best[j];
		best[j] = temp;

		return 1;
	}
	else
	{
		// Return Do not need to percolate value up was not added to array
		return 0;
	}

}
