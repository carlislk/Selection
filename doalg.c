// Do algorithm Routine
// Kevin Carlisle 82682616
// Jared Napoli 31666553
// binarySearch algorithm adapted from Jeffery Stedfast 
// at http://jeffreystedfast.blogspot.com/2007/02/binary-insertion-sort.html
#include <stdio.h>

int add_ordered(int i, int k, int* best);
int compareAndSwap(int i , int j, int k, int* best);
int getPos(int k, int* best);
void swapAtP(int p, int k, int* best);



int doalg(int n, int k, int* best)
{
	// n -> number of elements in array
	// k -> size 

	// Initialize best array to -1
	int i; 
	for ( i = 0; i < k; i++) 
	{ 
		best[i] = -1; 
	}

	for ( i = 1; i <= n; i++ )
	{
		add_ordered(i, k, best);
	}

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

	// Index value was placed in last index of aray now we need to 
	// determine where it belongs in the sorted array
	int p = getPos(k, best);

	// Insert Last element into P place and move the rest of the array down one index
	swapAtP(p, k, best);

	return 1;
}

int compareAndSwap(int i, int j, int k, int* best)
{
	if ( best[i] == -1 || COMPARE(best[i], best[j]) == 2 )
	{
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

// adapted from Jeffery Stedfast 
// at http://jeffreystedfast.blogspot.com/2007/02/binary-insertion-sort.html
int binarySearch (int* best, int low, int high, int key)
{
	int mid;

	if ( low == high ) { return low; }

	mid = low + ((high-low) / 2);

	//else if (key < best[mid])
	if (best[mid] == -1 || COMPARE(best[key], best[mid]) == 1)
	{
		return  binarySearch( best, low, mid, key);
	}
	//if (key > best[mid])
	else if ( COMPARE(best[key], best[mid]) == 2)
	{
		return binarySearch(best, mid+1, high, key);
	}
	return mid;
}

int getPos(int k, int* best)
{
	// Determines where to place last item in array
	// Array is currently sorted except for the last value
	return binarySearch(best, 0, k-1, k-1);
}

void swapAtP ( int p, int k,  int* best)
{
	// Swap Last element to place p
	// Move elements of array down

	// Add check if no swap needed

	int temp = best[k-1];

	int i;

	if(p == k-1)
	{
		return;
	}

	for ( i = k-1; i > p; i--)
	{
		best[i] = best[i-1];
	}

	best[p] = temp;
}
