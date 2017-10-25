
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[10];
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


int main(int arga, char * argv [])
{
    
        int i=0,err;
        while (i<arga) 
        {
                while(status!=i)
                {

                }
                pthread_create(&(tid[i]), NULL, &wordss, (void*)argv[i+1]);
                i++;
        }
        for(i=0;i<arga-1;i++)
        {
           pthread_join(tid[i],NULL);
        }

        return 0;
}


