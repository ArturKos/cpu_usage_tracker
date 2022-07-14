void* watchdog()
{
  for(;;)
  {
    unsigned long     time_now = time(NULL);

    pthread_mutex_lock(&watchdog_timer_mutex);

    if( (time_now - watchdog_timer[LOGGER_WATCHDOG]) > 2 ||
        (time_now - watchdog_timer[READER_WATCHDOG]) > 2 ||
        (time_now - watchdog_timer[ANALYZER_WATCHDOG]) > 2 ||
        (time_now - watchdog_timer[PRINTER_WATCHDOG]) > 2  )
        {
          printf("One of the threads has crashed, I close all threads, free memory, quit the program. \n");
          pthread_detach(reader_id);
          pthread_detach(printer_id);
          pthread_detach(analyzer_id);
          pthread_detach(logger_id);
          break;
        }
    pthread_mutex_unlock(&watchdog_timer_mutex);
    sleep(0.5);
  }
  pthread_exit(NULL);
}
