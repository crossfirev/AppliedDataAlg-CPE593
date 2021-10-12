// Original Tony Hoare algorithm
bool quicksort(int[] x, int L, int R)
{
    int middle = partition(x, L, R); // middle is the leftmsot element of right half or the Rightmost element of the left half.

    if (middle > L)
        quicksort(x, L, middle);
    if (middle+1 < R)
        quicksort(x, middle+1, R);
}
//

// Lomuto Partition
bool quicksort(int[] x, int L, int R)
{
    int middle = partition(x, L, R); // middle is location of the pivot

    if (middle-1 > L)
        quicksort(x, L, middle-1);
    if (middle+1 < R)
        quicksort(x, middle+1, R);
}
//

// Knuth Optimized Quicksort
bool knuthOptimizedQuicksort(int[] x)
{
    partialQuicksort(x, 0, x.length-1);

    insertionSort(x);
}

bool partialQuicksort(int[] x, int L, int R)
{
    int middle = partition(x, L, R); // middle is the Rightmost element of the left half.
    int k = ????; // k is the number of elements when insertion sort will be more effecient to sort the partition than 

    if (middle - L > k)
        quicksort(x, L, middle);
    if (r - middle - 1 < k)
        quicksort(x, middle+1, R);
}
//

// PARTITION EXAMPLE 
partition(int[] x, int L, int R)
{
    int pivot = x[random(L,R)]; // PIVOT SELECTION PART <<<<
    int i = L;
    int j = R;
    
    while (i < j)
    {
        while (i < j && x[i] < pivot)
            i++;
        while (i < j && x[j] >= pivot)
            j--;
        if (i < j)
            swap(x[i], x[j]);
    }
}


// Heap Sort
//
// x[i] is the parent of x[2i+1] and x[2i+2]
//
void heapsort (int[] x)
{
    ??  
}

// Merge sort
//  BEST ON SEQUENTIAL DATA
// Special purpose: sorting when data is larger than physical RAM
//  data is stored on devices for which sequenctial access is much faster
//  i.e. Hard Drives, and Tape Drives
void mergesort(dest[], a[], b[], partitionSize)
{
    int i = 0, j = 0, k = 0;

    while (i < partitionSize && j < partitionSize)
    {
        if(a[i] <= b[j])
        {
            dest[k] = a[i];
            i++;
        }
        else
        {
            dest[k] = b[j];
            j++;
        }
        k++;
    }
}
//      \/ THIS CODE IS JUNK LOL, LOOK IT UP MYSELF ^^^^^^^^^^
mergesortDriver(int[] x, n) // n is number of elements
{
    int[] y = ???; //array the same size of x
    for (int partitionSize = 1; partitionSize )
        mergesort(y, x+i, x + i + partitionSize)
}


//
//  SEARCHING & SHUFFLING ALGORITHMS
//
//  EQUALLY DISTRIBUTE (fairness) THE DATA THROUGHOUT THE ARRAY

// don't use this, it is bad.
void badShuffle(int[] x, n) // n is # of elements
{
    for (int i = 0; i < n; i++)
    {
        pick = random(0, n);
        swap(x[i], x[pick]);
    }
}


// slow shuffle, but it is fair 
void slowshuffle(int[] x, int n)
{
    int[] y = ???; // array of same size as x
    for (int i = 0; i < n; i++)
    {
        pick = random(0, n);
        while (x[pick] < 0)
        {
            y[i] = x[pick];
            x[pick] = -1; // ??? WTF
        }
    }
}

// Fisher-Yates
void fisherYatesShuffle(int[] x, n)
{
    for (int i = n; i >= 0; i--) // O(n)
    {
        int pos = abs(rand() % i); // O(1)
        swap(x[i], x[pos]); // O(1)
    }
}

// SEARCH ------------------------------------------------------------------------------------
//
//

int binary_search(const int a[], int n, int target)
{
    int L = 0, R = n-1;


    if (target < a[L] || target > a[R]) // OPTIMIZATION: to catch target that is out of range of the data.
        return -1;

    while (L < R)
    {
        int mid = (L + R) / 2;

        if (a[mid] > target) // If mid is > target half the dataset.
            R = mid - 1;

        else if (a[mid] < target) // If mid is < target half the dataset.
            L = mid + 1;

        else
            return mid; // FOUND IT!
    }
    return -1; // NOT FOUND.
}

int binary_searchMAIN()
{
    int list[] = {1,3,9,16,17,17,17,18,21,100,103,210};
    const int n = sizeof(list)/sizeof(int);
}

// Golden Mean Search
// Φ = (1+sqrt(5))/2 = 1.618...

/*
n = 10^6
L = 0   R = n-1
S = (R-L) / phi = 600k
a = 600k, b = 400k
R = a
b = a
S = (R-L) / phi
a = R - S
... continue ... ??? wtf happened above ??? Might literally be unhelpful as hell.
*/

