#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <assert.h>
#include "headers/global_varibles.h"
#include "lib/function_prototypes.h"
#include "lib/free_memory.c"
#include "lib/term_signal.c"
#include "lib/queue_logger.c"
#include "lib/create_threads.c"
#include "lib/init_varibles.c"
#include "lib/init_mutex.c"


int main()
{
  init_varibles();
  if(init_mutex() == 1)
   return 1;
  if (create_threads()!=0)
  {
      printf("\n Error creating threads \n");
      pthread_mutex_destroy(&lock_x);
      free(queue_cpu);
      pthread_mutex_destroy(&watchdog_timer_mutex);
      add_to_logger_queue(3);
      flush_logger_queue_to_file();
      pthread_mutex_destroy(&logger_mutex);
    return 1;
  }

  free_memory();
  add_to_logger_queue_without_mutex(4);
  flush_logger_queue_to_file_without_mutex();

  return 0;
}
