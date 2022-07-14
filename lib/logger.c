void* logger()
{
  time_t     time_now = time(NULL);

  for(;;)
  {
   pthread_mutex_lock(&watchdog_timer_mutex);
   watchdog_timer[LOGGER_WATCHDOG] = *localtime(&time_now);
   pthread_mutex_unlock(&watchdog_timer_mutex);

   pthread_mutex_lock(&lock_x);

   pthread_mutex_unlock(&lock_x);
   sleep(1);
  }
  pthread_exit(NULL);
}
