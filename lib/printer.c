void* printer(void* data)
{
  pthread_detach(pthread_self());
  for(;;)
  {
   pthread_mutex_lock(&lock_x);
   printf("Hello from new thread - printer");
   pthread_mutex_unlock(&lock_x);
  }
  pthread_exit(NULL);
}
