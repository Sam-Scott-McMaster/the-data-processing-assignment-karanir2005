#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "data.h"

float** read_data(int* rows, int* cols) {
    scanf("%d %d", rows, cols); //side effect: assigns values for the number of rows and columns to variables in main.c

    float** data = malloc((*rows) * sizeof(float*)); //2D float array allocated the memory of rows * size of float pointers
    for (int i = 0; i < *rows; i++) {
        data[i] = malloc((*cols) * sizeof(float)); //each "row" in data is allocated space for one float * the number of cols
        for (int j = 0; j < *cols; j++) {
            scanf("%f", &data[i][j]); //scans each float number in data and allocates it to data[i][j]
        }
    }
    return data; //returns data when everything is done
}

void output_data(float** data, int rows, int cols) {
    printf("%d %d\n", rows, cols); //prints the #of rows and cols

    for (int i = 0; i < rows; i++) { //loops through rows
        for (int j = 0; j < cols; j++) { //loops through each value in each row
            printf("%.3f ", data[i][j]); //prints the number with 3 decimal places
        }
        printf("\n"); //new line for formatting.
    }
}

