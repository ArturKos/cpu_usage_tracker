#include "calculate_percent_cpu_usage.c"

void* analyzer(void *t)
{
  for(;;)
  {
    pthread_mutex_lock(&watchdog_timer_mutex);
    watchdog_timer[ANALYZER_WATCHDOG] = time(NULL);
    pthread_mutex_unlock(&watchdog_timer_mutex);
    add_to_logger_queue(19);
    pthread_mutex_lock(&lock_x);
    if(rear_queue>=2*number_of_cores && !ready_to_print)
    calculate_percent_cpu_usage();
    pthread_mutex_unlock(&lock_x);
    usleep(SLEEP_TIME*1000);
  }
  pthread_exit(NULL);
}
