#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "data.h"
#include "clean.h"
#include "main.h"

int main(int argc, char* argv[]) {
    int rows, cols;
    float** data = read_data(&rows, &cols); //reads the file and stores data in 2D-float-array called data. (updates rows and cols as a side effect as well)

    if (argc > 1 && strcmp(argv[1], "-d") == 0) { //if there exists an arg and the first arg is -d then...
        int new_rows; //var to store new rows
        float** cleaned_data = clean_delete(data, rows, cols, &new_rows); //passes new rows as pointer since its being updated (also stores cleaned array in 2D array called cleaned_data)
        output_data(cleaned_data, new_rows, cols);

        for (int i = 0; i < new_rows; i++) {
            free(cleaned_data[i]);
        }
        free(cleaned_data);
    } else {
        clean_impute(data, rows, cols);
        output_data(data, rows, cols);
    }

    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}
