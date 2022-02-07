#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex;
void* thread(void* arg)
{
    sem_wait(&mutex); //locks the semaphore

    int fork1 = fork();
    int fork2 = fork();
    //critical section
    sleep(4);
    //signal
    if (fork1 < 0) { //fork fails
   fprintf(stderr, "fork failed\n");
    } else if (fork1 == 0) { //new process (children)
   printf("Process (pid:%d) printing\n", (int) getpid());
   }
 else {  // parent(the main process)
   printf("process (pid:%d) printing\n", (int) getpid());
     }
    //printf("\nJust printing...\n");
	
  sem_post(&mutex);   //unlock the semaphore

}

int main()
{
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2,t3,t4;
    pthread_create(&t1,NULL,thread,NULL);
    sleep(2);
    pthread_join(t1,NULL);
    sem_destroy(&mutex);
    return 0;
}
