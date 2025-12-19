#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


// Debugging Report Question
// 1 Syntatic Error - Fix it through compiler message
// 2 Semantic Errors, Debugger Report Required
// EVEN IF you see the error by code reading / by inspection, you need to still
//  1. Set up the breakpoint at the right place
//  2. Set up the watches over the relevant variables
//  3. Use stepping in debugger to show the exact moment where the bug occurs, and how it deviates from the expected behaviour
//  4. Show how your proposed fix defeats the bug.

void sortDatabyBubble(struct Q4Struct array[], int size)
{
    // Initialize variables for sorting
    struct Q4Struct swapHelper;
    swapHelper.intData = 0;
    swapHelper.charData = 0;

    int pos;
    int currentVal, nextVal;
    int needsMorePasses = 1;
    
    // Debug: Print initial array state
    printf("\nInitial array state:\n");
    {
        int i;
        for(i = 0; i < size; i++) {
            printf("array[%d]: intData=%d, charData=%c\n", 
                   i, array[i].intData, array[i].charData);
        }
    }

    while(needsMorePasses)
    {
        needsMorePasses = 0;
        printf("\n=== Starting new pass ===\n");
        
        pos = 0;
        // Bug #1: Using <= causes array bounds violation
        while(pos <= size - 1)        // BREAKPOINT #1 HERE - Array bounds check
        { 
            printf("\nChecking elements at positions %d and %d (size=%d)\n", pos, pos+1, size);
            
            // BREAKPOINT #2 HERE - Before accessing array elements
            currentVal = array[pos].intData;
            nextVal = array[pos + 1].intData;   // Will cause bounds violation when pos = size-1

            // Swap two elements whenever current element value is larger than the value of the next element.
            if(currentVal > nextVal)
            {
                // BREAKPOINT #3 HERE - Before swap operation
                printf("\n--- Swap Operation Start ---\n");
                printf("Before swap:\n");
                printf("  array[%d]: intData=%d, charData=%c\n", 
                       pos, array[pos].intData, array[pos].charData);
                printf("  array[%d]: intData=%d, charData=%c\n", 
                       pos+1, array[pos+1].intData, array[pos+1].charData);
                
                // Bug #2: Incorrect swap implementation
                // BREAKPOINT #4 HERE - During swap
                swapHelper.intData = array[pos].intData;    // Step 1: Store first value
                swapHelper.charData = array[pos].charData;
                printf("\nStep 1 - Stored in temp:\n");
                printf("  swapHelper: intData=%d, charData=%c\n", 
                       swapHelper.intData, swapHelper.charData);
                
                array[pos].intData = swapHelper.intData;    // Step 2: BUG - Copying same value back
                array[pos].charData = swapHelper.charData;
                printf("\nStep 2 - Copied back to same location (BUG):\n");
                printf("  array[%d]: intData=%d, charData=%c\n", 
                       pos, array[pos].intData, array[pos].charData);
                
                array[pos + 1].intData = array[pos].intData;    // Step 3: BUG - Duplicating value
                array[pos + 1].charData = array[pos].charData;
                printf("\nStep 3 - Copied to next position (BUG):\n");
                printf("  array[%d]: intData=%d, charData=%c\n", 
                       pos+1, array[pos+1].intData, array[pos+1].charData);
                
                printf("After swap: array[%d]=%d, array[%d]=%d\n", 
                       pos, array[pos].intData, pos+1, array[pos+1].intData);

                needsMorePasses = 1;
            }
            pos++;
        }

    }    
}


void sortDatabySelection(struct Q4Struct array[], int size)
{
    // Selection Sort is an alternative to Bubble Sort, with the intention to lower the number of swapping operations.

    // Read the lab manual to understand the general process of Selection Sort, then implement it here:
    
    // Step 1:  From the start of the array, visit every element
    // Step 2:  For every visited element at index i (current element), check all the subsequent elements *AFTER* index i.  
    //          Find the element with the smallest value among the current element, and all the subsequent elements, and denote it as target element
    // Step 3:  If the target element is not the current element, swap the target element and the current element.
    // Step 4:  Move on to the next element, repeat Step 2 and 3.
    // When reaching the last element in the array, DONE.

    int i, j, minIndex;
    struct Q4Struct temp;
    
    // Step 1: Visit each element from start to end
    for (i = 0; i < size - 1; i++) {
        // Step 2: Find the smallest element in the remaining unsorted portion
        minIndex = i;  // Assume current element is the smallest
        
        for (j = i + 1; j < size; j++) {
            // Compare with subsequent elements to find the actual minimum
            if (array[j].intData < array[minIndex].intData) {
                minIndex = j;  // Update index of minimum element
            }
        }
        
        // Step 3: Swap if the minimum element is not the current element
        if (minIndex != i) {
            temp.intData = array[i].intData;
            temp.charData = array[i].charData;
            
            array[i].intData = array[minIndex].intData;
            array[i].charData = array[minIndex].charData;
            
            array[minIndex].intData = temp.intData;
            array[minIndex].charData = temp.charData;
        }
        // Step 4: Move to next element (handled by for loop increment)
    }
}