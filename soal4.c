
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
void *fact(void *arg) {
        int n; 
        n = *((int *) arg);

        int i;
        long double result = 1;
        for (i = 2; i <= n; i++) {  //loop factorial
                result =result*i;
        }

        printf("Hasil %d! = %.0Lf\n", n, result);

}


