#include <stdio.h>
#include <stdlib.h>

void selectionSort(int array[], int size)
{
    for (int index = 0; index < size - 1; index++)
    {
        int minIndex = index;
        for (int nestedIndex = index + 1; nestedIndex < size; nestedIndex++)
        {
            if (array[nestedIndex] < array[minIndex])
            {
                minIndex = nestedIndex;
            }
        }
        int temporaryValue = array[index];
        array[index] = array[minIndex];
        array[minIndex] = temporaryValue;
    }
}

int main()
{
    int size;
    int array[100];
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        perror("Getting error while opening the input file...");
        return 1;
    }
    fscanf(inputFile, "%d", &size);
    for (int index = 0; index < size; index++)
    {
        fscanf(inputFile, "%d", &array[index]);
    }
    fclose(inputFile);
    selectionSort(array, size);
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        perror("Getting error while opening the output file...");
        return 1;
    }
    for (int index = 0; index < size; index++)
    {
        fprintf(outputFile, "%d ", array[index]);
    }
    fclose(outputFile);
    return 0;
}
