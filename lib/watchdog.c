void* watchdog(void *t)
{
  assert(t == NULL);
  for(;;)
  {
    long     time_now = time(NULL);

    pthread_mutex_lock(&watchdog_timer_mutex);

    if( (time_now - watchdog_timer[LOGGER_WATCHDOG]) > 2 ||
        (time_now - watchdog_timer[READER_WATCHDOG]) > 2 ||
        (time_now - watchdog_timer[ANALYZER_WATCHDOG]) > 2 ||
        (time_now - watchdog_timer[PRINTER_WATCHDOG]) > 2  ||
        (sigterm_received == 1))
        {
          if(sigterm_received == 1)
           {
            add_to_logger_queue(15);
            printf("SIGTERM signal  received. I close all threads, free memory, quit the program. Signum %d\n", signal_number);
           }else
           {
            add_to_logger_queue(16);
            printf("One of the threads has crashed, I close all threads, free memory, quit the program. \n");
           }
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
