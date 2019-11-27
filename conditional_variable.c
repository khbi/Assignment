#include <stdio.h>
#include <pthread.h>

#define MAX 10
int buffer[MAX];
int fill = 0;
int use = 0;
int count = 0;

pthread_cond_t empty, empty2, empty3;
pthread_mutex_t mutex;

void put(int value) {
	buffer[fill] = value;
	fill = (fill + 1) % MAX;
	count++;
}

int get() {
	int tmp = buffer[use];
	use = (use + 1) % MAX;
	count--;
	return tmp;
}

void *producer(void *arg){ //Create producer 1
	int i;
	int loops = 91;
	int loops2 = 123;
	//Create A to Z
	for (i = 65; i < loops; i++){
		pthread_mutex_lock(&mutex);
		while(count ==MAX){
			pthread_cond_wait(&empty, &mutex);
		}
		put(i);
		pthread_cond_signal(&empty2);
		pthread_cond_signal(&empty3);
		pthread_mutex_unlock(&mutex);
	}
	//create a to z
	for (i = 97; i < loops2; i++){
		pthread_mutex_lock(&mutex);
		while(count ==MAX){
			pthread_cond_wait(&empty, &mutex);
		}
		put(i);
		pthread_cond_signal(&empty2);
		pthread_cond_signal(&empty3);
		pthread_mutex_unlock(&mutex);
	}

	return NULL;
}

void *producer2(void *arg){ //Create producer 2
	int i;
	int loops = 51;
	//create number 1 to 50
	for (i = 1; i < loops; i++){
		pthread_mutex_lock(&mutex);
		while(count ==MAX){
			pthread_cond_wait(&empty2, &mutex);
		}
		put(i);
		pthread_cond_signal(&empty);
		pthread_cond_signal(&empty3);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}


void *consumer(void *arg){ //Create consumer 
	int i;
	int loops=102;
	for (i = 0; i < loops; i++){
		pthread_mutex_lock(&mutex);
		while(count ==0){
			pthread_cond_wait(&empty3, &mutex);
			}
		int tmp = get();
		pthread_cond_signal(&empty);
		pthread_cond_signal(&empty2);
		pthread_mutex_unlock(&mutex);
		
		//a condition for creating a table
		//first character positioning
		if(tmp <=50 && i == 0){
		printf("%d", tmp);
		}
		else if(65<=tmp<=122 && i == 0){
		printf("%c", (char)tmp);
		}
		
		//Condition for inserting tabs in the middle of the table
		else if(tmp <=50 && i%10 != 0){
		printf("\t%d", tmp);
		}
		else if(65<=tmp<=122 && i%10 != 0){
		printf("\t%c",(char)tmp);
		}

		//Condition for row movement
		else if(tmp <=50 && i%10 == 0){
		printf("\n%d", tmp);
		}
		else if(65<=tmp<=122 && i%10 == 0){
		printf("\n%c",(char)tmp);
		}
		
	}		
return NULL;
}

int main(int argc, char *argv[]){
	printf("start\n");
	pthread_t p1, p2, p3;

	pthread_create(&p1, NULL, producer, NULL);
	pthread_create(&p2, NULL, producer2, NULL);
	pthread_create(&p3, NULL, consumer, NULL);

	pthread_join(p1, NULL);	
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);

	printf("\nend\n");
	return 0;
}

