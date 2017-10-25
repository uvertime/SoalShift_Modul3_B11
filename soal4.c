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

int main(int argb, char *arga[]) {
	pthread_t tid[argb];
	int j;

	for (j = 1; j < argb; j++) {  
		

		int *nmr = (int*) malloc(sizeof(*nmr)); //alokasi memori karna factorial nanti besar jadinya
		*nmr = atoi(arga[j]); //string to int 
		pthread_create(&(tid[j]), NULL, &fact, (void*) nmr);
	}

	for (j = 1; j < argb; j++) {
		pthread_join(tid[j], NULL);
	}

	return 0;
}

