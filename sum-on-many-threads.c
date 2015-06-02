// pthreads #1: Introduction  by DrBFraser
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The sum computed by the background thread
struct sum_runner_struct
{
        long long limit;
        long long answer;
};

//Thread function to generate sum of 0 to N
void* sum_runnable(void *arg)
{
    struct sum_runner_struct *arg_struct =
            (struct sum_runner_struct*) arg;
    long long limit = *limit_ptr;
    for (long long i = 0; i < arg_struct->limit; i++)
    {
        sum += i;
    }

    pthread_exit(0);
}

int main (int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Usage: %s <num_1> <num_2> ... <num_n>\n", argv[0]);
        exit(-1);
    }
    int num_args = argc - 1;
    pthread_t tids[num_args];
    struct sum_runner_struct args[num_args];

    for (int i = 0; i < num_args; i++)
    {
        args[i].limit = atoll(argv[i+1]);
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&tids[i], &attr, sum_runnable, &args[i]);
    }

    //Do Other Stuff Here!

    // Wait until thread has done it's work

    for (int i = 0; i < num_args; i++)
    {
        pthread_join(tids[i],NULL);
        printf("Sum is %lld\n",args[i].answer);
    }


}
