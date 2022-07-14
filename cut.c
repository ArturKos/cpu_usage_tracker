#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include "headers/global_varibles.h"
#include "lib/create_threads.c"


void term()
{
    sigterm_received = 1;
}

int main()
{
  sigterm_received = 0;
  struct sigaction action;
  memset(&action, 0, sizeof(struct sigaction));
  action.sa_handler = term;
  sigaction(SIGTERM, &action, NULL);

  rear_queue = 0;
  ready_to_print = false;
  number_of_cores = count_cores();
  queue_cpu = malloc(QUEUE_SIZE * number_of_cores * sizeof(struct cpustat)); /* VLA Variable-length array applied */

  if (pthread_mutex_init(&lock_x, NULL) != 0)
  {
      printf("\n Mutex init has failed\n");
    return 1;
  }
  if (pthread_mutex_init(&watchdog_timer_mutex, NULL) != 0)
  {
      printf("\n Mutex init has failed\n");
    return 1;
  }
  if (create_threads()!=0)
  {
    printf("\n Error creating threads \n");
    pthread_mutex_destroy(&lock_x);
    free(queue_cpu);
    pthread_mutex_destroy(&watchdog_timer_mutex);
    return 1;
  }
  pthread_join(watchdog_id, NULL);
  free(queue_cpu);
  pthread_mutex_destroy(&watchdog_timer_mutex);
  pthread_mutex_destroy(&lock_x);

  return 0;
}
