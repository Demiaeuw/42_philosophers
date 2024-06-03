#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


int sharedValue = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* incrementThread(void* arg) 
{
    for (int i = 0; i < 1000; ++i) 
    {
        pthread_mutex_lock(&mutex);
        sharedValue++;
	if (i == 500)
		printf("%d\n", i);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() 
{
	pthread_t thread1, thread2;

	// printf("%d, Normalement 0\n", sharedValue);
	// sleep(1);
	pthread_create(&thread1, NULL, incrementThread, NULL);
	// sleep(1);
	// printf("%d, Normalement 1000 Après thread 1\n", sharedValue);
	// sleep(1);
	// printf("changement de thread\n");
	// sleep(1);
	// printf("%d, Normalement 1000\n", sharedValue);
	// sleep(1);
	pthread_create(&thread2, NULL, incrementThread, NULL);
	// sleep(1);
	// printf("%d, Normalement 2000 Après thread 2\n", sharedValue);
	// sleep(2);
	// printf("%d -> avant Join 1\n", sharedValue);
	pthread_join(thread1, NULL);
	// sleep(2);
	// printf("%d -> avant Join 2 \n", sharedValue);
	pthread_join(thread2, NULL);
	// sleep(1);
	printf("Shared value: %d\n", sharedValue);
	return 0;
}


