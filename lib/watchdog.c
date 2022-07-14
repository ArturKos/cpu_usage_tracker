void* watchdog()
{
  time_t     time_now = time(NULL);
  struct tm  time;

  for(;;)
  {
    pthread_mutex_lock(&watchdog_timer_mutex);
    time = *localtime(&time_now);
    if( abs(time.tm_sec-watchdog_timer[LOGGER_WATCHDOG].tm_sec) > 2 ||
        abs(time.tm_sec-watchdog_timer[READER_WATCHDOG].tm_sec) > 2 ||
        abs(time.tm_sec-watchdog_timer[ANALYZER_WATCHDOG].tm_sec) > 2 ||
        abs(time.tm_sec-watchdog_timer[PRINTER_WATCHDOG].tm_sec) > 2  )
        {
          pthread_detach(reader_id);
          pthread_detach(printer_id);
          pthread_detach(analyzer_id);
          pthread_detach(logger_id);
          break;
        }
    pthread_mutex_unlock(&watchdog_timer_mutex);
   sleep(1);
  }
  pthread_exit(NULL);
}
