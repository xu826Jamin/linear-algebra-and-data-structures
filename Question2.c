#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr [])
{

    // This is the first programming (scripting) question without any initial setup as hints.

    // This is also the first question requiring you to come up with an algorithm on paper 
    // with mathematical analysis before implementing the code.

    // High Level Hint:
    //  Assume a 3x3 square matrix, look at the SUM of the row and column indices of each element.
    //  You should be able to see a numerical pattern after doing so.

    int outputPos = 0;  // Index for the output array
    int diagSum;        // Sum of row and column indices
    int currentRow, currentCol;   // Loop variables for row and column
    
    // Traverse anti-diagonally by sum of indices
    // For a 3x3 matrix, sum ranges from 0 to 4 (2*(N3-1))
    for (diagSum = 0; diagSum <= (N3-1)*2; diagSum++) {
        // For each sum, find all valid (row, col) pairs where row + col = sum
        currentRow = 0;
        while (currentRow < N3) {
            currentCol = diagSum - currentRow;  // Calculate column from sum and row
            
            // Check if column is within valid bounds
            if (currentCol >= 0 && currentCol < N3) {
                // Store current element and move to next position
                arr[outputPos++] = mat[currentRow][currentCol];
            }
            currentRow++;
        }
    }
}