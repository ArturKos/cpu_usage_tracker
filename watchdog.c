void* watchdog(void* data)
{
  pthread_detach(pthread_self());
  for(;;)
   printf("Hello from new thread - watchdog");
  pthread_exit(NULL);
}
