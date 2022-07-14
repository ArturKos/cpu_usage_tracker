#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "headers/global_varibles.h"
#include "lib/create_threads.c"

int main()
{

  rear_queue = 0;
  ready_to_print = false;
  number_of_cores = count_cores();
  queue_cpu = malloc(QUEUE_SIZE * number_of_cores * sizeof(struct cpustat));

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
