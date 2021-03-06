#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <sys/time.h>

#define GLOBAL_TIMER  8 * 60 * 60


typedef struct protocol_type {
 int protocol_number;
 char *protocol_name;
 pthread_t thread_timer_id;
} protocol_type_t;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


/* call back function - inform the user the time has expired */
void timeout_call_back(pthread_t thread_id)
{
    printf("Welcome thread %ld, your time is up ===\n", pthread_self());
    // doing some other stuff
}

/* Go to sleep for a period of seconds */
static void* start_timer(void *args)
{
    /* function pointer */
    void (*finish_function)(pthread_t);


    int seconds = *((int*) args);

    finish_function = timeout_call_back;

 struct timeval now;
 struct timespec timeout;

 pthread_mutex_lock(&mut);
 printf("thread ID : %ld, are waiting for %d seconds to to expire\n", pthread_self(), seconds);
 gettimeofday(&now, NULL);
 timeout.tv_sec = now.tv_sec + seconds;
 timeout.tv_nsec = now.tv_usec * 1000;
 pthread_cond_timedwait(&cond, &mut, &timeout);
 (*finish_function)(pthread_self());
 pthread_mutex_unlock(&mut);
    pthread_exit(NULL);
}

// This function is in MT environnement and is running inside a daemon
int received_buffer_parser(char *received_buffer) {
 pthread_mutex_t mut_main = PTHREAD_MUTEX_INITIALIZER;
 protocol_type_t *my_protocol;

 // Identify protocol type
 my_protocol = protocol_identifier(received_buffer);

 // Check if i received it in the last 8 hours in safe
 pthread_mutex_lock(&mut_main);
    if (check_timer(my_protocol->thread_id) has expired) { // I want to write this function
  // I want to reset thread timer
   launch_new_timer(my_protocol->thread_id);
 }
 else {
  // doing some stuff
  // dump data to the disk
 }
 pthread_mutex_unlock(&mut_main);

 return 0;
}

int launch_new_timer(pthread_t thread_id)
{
 int rc;
 int seconds = GLOBAL_TIMER;

    rc =  pthread_create(&thread_id, NULL, start_timer, (void *) &seconds);
    if(rc)
     printf("Failed to create thread1\n");

    pthread_join(thread_id, NULL);

    return 0;
}
