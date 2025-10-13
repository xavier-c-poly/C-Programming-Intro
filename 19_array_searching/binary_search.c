#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));

    // loop and create random elemtns element ints for each element and then do binary searhc on that, and also implement the print array function from the previous file "array_searching.c"
    return 0;
}

int returnRandomInclusive(int min, int max) {
    return rand() % (max - min + 1) + min;
}

size_t binarySearch(const int b[], int searchKey, size_t low, size_t high)
{
    // loop until low index is greater than high index
    while (low <= high) {
        
        // determine middle elemtn of subarray being searched
        size_t middle = (low + high) / 2;

        // if searchKey matched middle element, return middle
        if (searchKey == b[middle]) {
            return middle;
        }
        
        // if searchKey is less than middle element, set new high
        else if (searchKey < b[middle]) {
            high = middle - 1; // search low end of array
        }
        
        // if searchKey is greater than middle element, set new low
        else {
            low = middle + 1;  // search high end of array 
        }
    }  // end while

    return -1; // searchKey not found
}
