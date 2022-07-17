void* logger(void *t)
{
  assert(t == NULL);
  for(;;)
  {
    pthread_mutex_lock(&watchdog_timer_mutex);
    watchdog_timer[LOGGER_WATCHDOG] = time(NULL);
    pthread_mutex_unlock(&watchdog_timer_mutex);
    add_to_logger_queue(20);
    flush_logger_queue_to_file();
    usleep(SLEEP_TIME*1000);
  }
  pthread_exit(NULL);
}
