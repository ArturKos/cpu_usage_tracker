void* logger(void *t)
{
  assert(t == NULL);
  for(;;)
  {
   pthread_mutex_lock(&watchdog_timer_mutex);
   watchdog_timer[LOGGER_WATCHDOG] = time(NULL);
   pthread_mutex_unlock(&watchdog_timer_mutex);
   flush_logger_queue_to_file();
   sleep(1);
  }
  pthread_exit(NULL);
}
