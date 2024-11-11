#include <stdio.h>
#include <stdlib.h>

#define n 8

// Function to initialize the bit string from user input
void createBitString(int set[], int bitString[]) {
    // Clear the bit string
    for (int i = 0; i < n; i++) {
        bitString[i] = 0;
    }

    // Set bits according to the elements in the set
    for (int i = 0; set[i] != -1 && i < n; i++) {
        if (set[i] >= 0 && set[i] < n) {
            bitString[set[i]] = 1;
        }
    }
}

// Function to perform union operation
void unionSets(int A[], int B[], int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = A[i] | B[i];
    }
}

// Function to perform intersection operation
void intersectionSets(int A[], int B[], int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = A[i] & B[i];
    }
}

// Function to perform difference operation (A - B)
void differenceSets(int A[], int B[], int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = A[i] & ~B[i];
    }
}

// Function to print a bit string as a set
void display1(int set[]) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (set[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}
void display2(int set[]) 
{
    for (int i = 0; i < n; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}

// Function to input elements for a set
void inputSet(int set[], char setName) 
{
    printf("Enter elements for Set %c (enter -1 to stop): ", setName);
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &set[i]);
        if (set[i] == -1) {
            break;
        }
    }
}

int main() 
{
    int setA[n + 1], setB[n + 1]; // Arrays to hold the user inputs
    int bitStringA[n], bitStringB[n];
    int result[n];
    int ch;
 inputSet(setA, 'A');
        inputSet(setB, 'B');
    while (1) 
    {
        // Input for Set A and Set B
       

        // Create bit strings from user input sets
        createBitString(setA, bitStringA);
        createBitString(setB, bitStringB);

        printf("Set operation:\n 1. Union\n 2. Intersection\n 3. Difference\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                unionSets(bitStringA, bitStringB, result);
                printf("Union: ");
                display1(result);
                printf("Union in 0's & 1's: ");
                display2(result);
                break;
            case 2:
                intersectionSets(bitStringA, bitStringB, result);
                printf("Intersection: ");
                display1(result);
                printf("Intersection in 0's & 1's: ");
                display2(result);
                break;
            case 3:
                differenceSets(bitStringA, bitStringB, result);
                printf("Difference: ");
                display1(result);
                printf("Difference in 0's& 1's: ");
                display2(result);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}
