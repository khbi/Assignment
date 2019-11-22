#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "mythreads.h"
#include <unistd.h>
#include <string.h>

static volatile int counter = 0;

struct Mthread  
{
	char n[5];
	int t; 
};

void *
mythread(void *mthread)
{
	struct Mthread *my_mthread = (struct Mthread *)mthread; 

	int i;
	for(i= 0; i < 1e6; i++){
	
		printf("[%s] %dusec\n", my_mthread->n, my_mthread->t);
		usleep(my_mthread->t);
		counter = counter + 1;
	
	}
	printf("[%s] done, counter = %d\n", my_mthread->n, counter);
	
	return NULL;
}

int
main(int argc, char *argv[])
{	
	int i;
	struct Mthread *mthread[5];
	for(i = 0; i<5; i++){

	mthread[i] = (struct Mthread *)malloc(sizeof(struct Mthread));
	}

	strcpy(mthread[0]->n, "A");
	mthread[0]->t = 100;
	strcpy(mthread[1]->n, "B");
	mthread[1]->t = 50;
	strcpy(mthread[2]->n, "C");
	mthread[2]->t = 30;
	strcpy(mthread[3]->n, "D");
	mthread[3]->t = 30;
	strcpy(mthread[4]->n, "E");
	mthread[4]->t = 10;

	pthread_t p1, p2, p3, p4, p5;
	printf("main: begin (counter = %d)\n", counter);

	pthread_create(&p1, NULL, mythread, (void *)mthread[0]);
	pthread_create(&p2, NULL, mythread, (void *)mthread[1]);
	pthread_create(&p3, NULL, mythread, (void *)mthread[2]);
	pthread_create(&p4, NULL, mythread, (void *)mthread[3]);
	pthread_create(&p5, NULL, mythread, (void *)mthread[4]);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);
	pthread_join(p4, NULL);
	pthread_join(p5, NULL);
	return 0;
}
