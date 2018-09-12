#include <stdio.h>
#include <time.h>
#include <stdlib.h> // for atoi
#define DEFAULT_NO (10)

unsigned int fabonacci(int n);

int main(int argc, char * argv[]) {
    int num;
    (argc > 1) ? num = atoi(argv[1]) : DEFAULT_NO;
    
    time_t t, t1;
    time(&t);
    unsigned int number = fabonacci(num);
    time(&t1);

    printf("%dth Fabonacci no.: %u\n", num, number);
    printf("It took (%f seconds)\n", difftime(t1, t));
    return 0;
}

unsigned int fabonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    } else {
        return fabonacci(n - 1) + fabonacci(n - 2);
    }
}