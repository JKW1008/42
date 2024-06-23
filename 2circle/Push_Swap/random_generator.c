#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 10  // Number of numbers to generate
#define MAX_NUM 1000   // Maximum value of generated numbers

int main() {
    srand(time(NULL)); // Initialize random seed
    int generated[NUM_COUNT] = {0}; // Array to store generated numbers
    int count = 0; // Count of generated numbers

    while (count < NUM_COUNT) {
        int num = rand() % MAX_NUM; // Generate a random number

        // Check if the number is already generated
        int isDuplicate = 0;
        for (int i = 0; i < count; i++) {
            if (generated[i] == num) {
                isDuplicate = 1;
                break;
            }
        }

        // If the number is not a duplicate, store it and print
        if (!isDuplicate) {
            generated[count] = num;
            printf("%d ", num);
            count++;
        }
    }

    return 0;
}