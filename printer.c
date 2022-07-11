void* printer(void* data)
{
  pthread_detach(pthread_self());
  for(;;)
   printf("Hello from new thread - printer");
  pthread_exit(NULL);
}
