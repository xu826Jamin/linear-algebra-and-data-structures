#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


// this is the very first question without hints in the comments.  read the manual to develop your own algorithm

// Read Questions.h to understand the definition of Q3Struct

void efficient(const int source[], struct Q3Struct effVector[], int size)
{
    int currentPos;
    int destIndex = 0;  // next non-zero element
    
    // Iterate through the source array
    currentPos = 0;
    while (currentPos < size) {
        // Look for non-zero elements
        int currentValue = source[currentPos];
        if (currentValue != 0) {
            // store it with its position
            effVector[destIndex].val = currentValue;
            effVector[destIndex].pos = currentPos;
            destIndex++;
        }
        currentPos++;
    }
    
    // Clear any unused entries in the efficient vector
    while (destIndex < size) {
        effVector[destIndex].val = 0;
        effVector[destIndex].pos = 0;
        destIndex++;
    }
}

void reconstruct(int source[], int m, const struct Q3Struct effVector[], int n)
{
    int arrayPos;
    
    // First, initialize all elements of source array to zero
    arrayPos = 0;
    while (arrayPos < m) {
        source[arrayPos] = 0;
        arrayPos++;
    }
    
    // Then, fill in the non-zero values from the efficient representation
    arrayPos = 0;
    while (arrayPos < n) {
        // Get current element from efficient vector
        int currentVal = effVector[arrayPos].val;
        int targetPos = effVector[arrayPos].pos;
        
        // Only process non-zero values within valid bounds
        if (currentVal != 0 && targetPos >= 0 && targetPos < m) {
            source[targetPos] = currentVal;
        }
        arrayPos++;
    }
}