
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[100];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread
int status = 0;

void* wordss(void *arg)
{
        char *jeneng;
        jeneng = (char *) arg;
        char command[1000]; 
        sprintf(command, "grep -o '%s' Novel.txt | wc -l", jeneng);
        char result[10];
        printf("%s : ",jeneng);
        FILE *A;
        A=popen(command,"r");
        while (fgets(result, sizeof(result), A)) 
        {
                printf("%s", result);
        }
        pclose(A);
        status++;

        return NULL;
}

