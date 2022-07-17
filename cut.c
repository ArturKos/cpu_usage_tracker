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
#include "headers/function_prototypes.h"
#include "lib/skip_lines.c"
#include "lib/count_cores.c"
#include "lib/free_memory.c"
#include "lib/term_signal.c"
#include "lib/queue_logger.c"
#include "lib/create_threads.c"
#include "lib/init_varibles.c"
#include "lib/init_mutex.c"
#include "lib/testing.c"

int main()
{
  init_varibles();
  init_varibles_test();
  if(init_mutex() == 1)
  return 1;
  if (create_threads()!=0)
  {
    pthread_mutex_destroy(&lock_x);
    free(queue_cpu);
    pthread_mutex_destroy(&watchdog_timer_mutex);
    add_to_logger_queue(3);
    flush_logger_queue_to_file();
    pthread_mutex_destroy(&logger_mutex);
    return 1;
  }
  create_thread_test();
  free_memory();
  free_memory_test();
  add_to_logger_queue_without_mutex(4);
  flush_logger_queue_to_file_without_mutex();

  return 0;
}
