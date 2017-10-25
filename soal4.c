#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd>

void *fact(void *arg) {
        int n; 
        n = *((int *) arg);

        int i;
        long double result = 1;
        for (i = 2; i <= n; i++) {  //loop factorial
                result =result*i;
        }

        

}


int main(int argc, char *argv[]) {
	pthread_t tid[argc-1];
	int i;

	

	return 0;
}
