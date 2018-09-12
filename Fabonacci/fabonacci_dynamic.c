#include <stdio.h>
#include <time.h>
#include <stdlib.h> // for atoi
#define DEFAULT_NO (10)

unsigned int fabonacci(int n, unsigned int container[]);

int main(int argc, char * argv[]) {
    int num;
    (argc > 1) ? num = atoi(argv[1]) : DEFAULT_NO;
    unsigned int arrayOfFabs[num]; 
    arrayOfFabs[0] = 0;
    arrayOfFabs[1] = 1;
    
    time_t t, t1;
    time(&t);
    unsigned int number = fabonacci(num, arrayOfFabs);
    time(&t1);

    printf("%dth Fabonacci no.: %u\n", num, number);
    printf("It took (%f seconds)\n", difftime(t1, t));
    return 0;
}

unsigned int fabonacci(int n, unsigned int container[]) {

    if(n == 0 || n == 1) {
        return n;
    } 
    for(int i = 2; i <= n; i++) {
        container[i] = container[i - 1] + container[i - 2];
    }
    return container[n];
}