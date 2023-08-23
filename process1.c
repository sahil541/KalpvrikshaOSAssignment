#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    int array[100];
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &array[index]);
    }
    FILE *inputFile = fopen("input.txt", "w");
    if (inputFile == NULL)
    {
        perror("Getting error while opening the input file...");
        return 1;
    }
    fprintf(inputFile, "%d\n", size);
    for (int index = 0; index < size; index++)
    {
        fprintf(inputFile, "%d ", array[index]);
    }
    fclose(inputFile);
    return 0;
}
