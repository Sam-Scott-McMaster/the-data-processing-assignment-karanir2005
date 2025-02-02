#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "clean.h"


float** clean_delete(float** data, int rows, int cols, int* new_rows) {
    float** cleaned_data = malloc(rows * sizeof(float*)); //2D float array allocated the memory of rows * size of float pointers
    *new_rows = 0; //new rows innitialized to 0

    for (int i = 0; i < rows; i++) { //loops through each row of data
        int has_nan = 0; //var to check if row has NaN, innitialized to false
        for (int j = 0; j < cols; j++) { //loops thorugh all cols of each row
            if (isnan(data[i][j])) { //checks if index [i][j] is NaN
                has_nan = 1; //makes has_nan = 1 (or true)
                break; //exits for loop without checking for more NaN values.
            }
        }

        //if there is no NaN value in the row, then...
        if (!has_nan) {
            cleaned_data[*new_rows] = malloc(cols * sizeof(float)); //allocate memory in the row of cleaned data (starts from row 0 since new_rows is innitialized to 0)
            for (int j = 0; j < cols; j++) { //loops through all cols in the row
                cleaned_data[*new_rows][j] = data[i][j]; //copys the row from data to cleaned data, in top most possible row (since rows would be removed in clean data)
            }
            (*new_rows)++; //increment new_rows by 1 for future reference and calculations. (changes value in main as well since its a pointer.)
        }
    } //does the same with all rows in data.

    return realloc(cleaned_data, (*new_rows) * sizeof(float*)); //reallocats memory to match the new rows and returns the new cleaned_data pointer 2D array.
}

void clean_impute(float** data, int rows, int cols) { //has no return type since the data array is being changed directly using pointers
    for (int j = 0; j < cols; j++) { //loop though each coloumn
        float sum = 0; //innitialize sum and count
        int count = 0; //counts the number of non NaN values in the coloumn

        for (int i = 0; i < rows; i++) { //loops through contents of each coloumn (goes down the coloumn)
            if (!isnan(data[i][j])) { //checks if any value in a coloumn is NaN
                sum += data[i][j]; //then increments sum by the number in data
                count++; //also increases count by 1
            }
        }

        float replacement = (count > 0) ? (sum / count) : 0; //if count is > 0 then set replacement = sum/count, else set replacement to 0

        for (int i = 0; i < rows; i++) { //loops through each coloumn by going down.
            if (isnan(data[i][j])) { //if there exists a NaN value then...
                data[i][j] = replacement; //replace it with the replacement number. (since data is a pointer, it replaces it directly in main)
            }
        }
    }
}
