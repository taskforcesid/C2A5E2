//
// Aladin Sidahmed U08614258 
// aladin.sidahmed@gmail.com
// C/C++ Programming II 
// Section 145010 Ray Mitchell 
// 15 FEB 2020
// C2A5E2_Create2D.c
// Operating System: Windows 7 
// Visual Studio Community 2019 Version 16.3.2 
//
// Implements Create2D which allocates memory and maps
// a 2D array in 1D
// Implements Free2D which Frees up memory created by the
// Create2D
//

#include <stdlib.h>
#include <stdio.h>
#include "C2A5E2_Type-Driver.h"

Type **Create2D(size_t rows, size_t cols)
{
    // Calculates the amount of memory needed for data, 
    //and the pointers to the data
    size_t totalMemory = ((rows * cols) * sizeof(Type)) + 
        (rows * sizeof(Type *));
    // allocates all the memory needed to a void pointer
    void *blockpointer = (Type *)malloc(totalMemory);
    if (blockpointer == NULL) 
    {
        fprintf(stderr, "FAILED TO ALLOCATE MEMORY");
        exit(EXIT_FAILURE);
    }
    //Allocates memory to hold the pointers
    Type **Array2D = (Type **)blockpointer;
    //Allocates memory to hold the data
    Type *Array1D = (Type *)(Array2D + rows);
    //maps the pointers to the start of the rows
    for (int rowIndex = 0; rowIndex < (int)rows; rowIndex++)
    {
        int arrayOffset = rowIndex * (int)cols;
        Array2D[rowIndex] = &Array1D[arrayOffset];
    }
    return Array2D;
}

void Free2D(void *p) 
{
    free(p);
}
