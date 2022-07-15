void free_memory()
{
  free(queue_cpu);
  pthread_mutex_destroy(&watchdog_timer_mutex);
  pthread_mutex_destroy(&logger_mutex);
  pthread_mutex_destroy(&lock_x);
}
