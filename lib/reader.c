#include "get_stats.c"

void* reader(void *t)
{
  assert(t == NULL);
  for(;;)
  {
    pthread_mutex_lock(&watchdog_timer_mutex);
    watchdog_timer[READER_WATCHDOG] = time(NULL);
    pthread_mutex_unlock(&watchdog_timer_mutex);
    add_to_logger_queue(17);
    pthread_mutex_lock(&lock_x);
    get_stats();
    pthread_mutex_unlock(&lock_x);
    usleep(SLEEP_TIME*1000);
    //sleep(1);
  }
  pthread_exit(NULL);
}
