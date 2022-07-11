void* analyzer(void* data)
{
 pthread_detach(pthread_self());
 for(;;)
  printf("Hello from new thread - analyzer");
pthread_exit(NULL);
}
