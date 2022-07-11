void* reader(void* data)
{
  pthread_detach(pthread_self());
  for(;;)
   printf("Hello from new thread - reader");
  pthread_exit(NULL);
}
