void* logger(void* data)
{
  pthread_detach(pthread_self());
  for(;;)
   printf("Hello from new thread - logger");
  pthread_exit(NULL);
}
