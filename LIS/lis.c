#include <stdio.h>

int length_of_LIS(int array[], int array_len);

int main() {
    int numbers[] = {5, 7, 4, -3, 9, 1, 10, 4, 5, 8, 9, 3};

    int length = length_of_LIS(numbers, (sizeof(numbers) / sizeof(numbers[0])));
    printf("Length of LIS: %d", length);

    return 0;
}

int length_of_LIS(int array[], int array_len) {
    int lengths[array_len];
    for(int i = 0; i < array_len; i++) {
        lengths[i] = 1;
        for(int j = 0; j < i; j++) {
            // If jth array element is strictly less than ith array element
            // and length of ithe(current) element is less the jth (previous but appendable) + 1
            if(array[j] < array[i] && lengths[i] < (1 + lengths[j])) {
                lengths[i] = 1 + lengths[j];
            }
        }
    }

    int max = 0;
    for(int k = 2; k < array_len; k++) {
        if(lengths[k] > lengths[max]) {
            max = k;
        }
    }

    return lengths[max];
}