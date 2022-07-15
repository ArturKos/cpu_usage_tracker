int init_mutex()
{
  if (pthread_mutex_init(&lock_x, NULL) != 0)
  {
      printf("\n Mutex init has failed - lock_x\n");
      add_to_logger_queue_without_mutex(0);
      flush_logger_queue_to_file_without_mutex();
    return 1;
  }
  if (pthread_mutex_init(&logger_mutex, NULL) != 0)
  {
      printf("\n Mutex init has failed - logger_mutex\n");
      add_to_logger_queue_without_mutex(1);
      flush_logger_queue_to_file_without_mutex();
      free(queue_cpu);
      pthread_mutex_destroy(&lock_x);
    return 1;
  }
  if (pthread_mutex_init(&watchdog_timer_mutex, NULL) != 0)
  {
      free(queue_cpu);
      add_to_logger_queue_without_mutex(2);
      flush_logger_queue_to_file_without_mutex();
      pthread_mutex_destroy(&logger_mutex);
      pthread_mutex_destroy(&lock_x);
      printf("\n Mutex init has failed - watchdog_timer_mutex\n");
    return 1;
  }
return 0;
}
