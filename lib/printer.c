#include "print_stats.c"
#include "print_cores_percent_usage.c"

void* printer(void *t)
{
  assert(t == NULL);
  for(;;)
  {
    pthread_mutex_lock(&watchdog_timer_mutex);
    watchdog_timer[PRINTER_WATCHDOG] = time(NULL);
    pthread_mutex_unlock(&watchdog_timer_mutex);
    add_to_logger_queue(18);
    pthread_mutex_lock(&lock_x);
    if(ready_to_print)
    {
      print_cores_percent_usage();
      delete_most_older_reads();
      ready_to_print = false;
    }
    pthread_mutex_unlock(&lock_x);
    sleep(1);
  }
  pthread_exit(NULL);
}
