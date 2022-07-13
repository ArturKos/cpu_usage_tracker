void* watchdog()
{
  pthread_detach(pthread_self());
  for(;;)
  {
    pthread_mutex_lock(&lock_x);
    
    pthread_mutex_unlock(&lock_x);
   sleep(1);
  }
  pthread_exit(NULL);
}
