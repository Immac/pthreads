// pthreads #1: Introduction  by DrBFraser
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// The sum computed by the background thread
long long sum = 0;

//Thread function to generate sum of 0 to N
void* sum_runnable(void *arg)
{
    long long *limit_ptr = (long long *) arg;
    long long limit = *limit_ptr;

    for (long long i = 0; i < limit; i++)
    {
        sum += i;
    }

    pthread_exit(0);
}

int main (int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Usage: %s <num>\n", argv[0]);
        exit(-1);
    }

    long long limit = atoll(argv[1]);

    //Thread ID:
    pthread_t tid;

    // Attributes:
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, sum_runnable, &limit);

    //Do Other Stuff Here!
    char *throw = "Doing Work! :(ノºДº)ノ ︵ ⌨  ";
    char *pickup = "Finished: ⌨  ノ( ゜-゜ノ)";
    
	for(int i = 0; i < 5000; i++)
	{
		fputs(throw,stdout);
	}
    // Wait until thread has done it's work
    pthread_join(tid,NULL);
    printf("\nSum is %lld\n",sum);
    puts(pickup);
}
