#ifndef QUEUE_LIB
#define QUEUE_LIB

void delete_most_older_reads()
{
  for(unsigned int i=0; i<number_of_cores; i++)
   free(queue_cpu[i]);
  for(unsigned int i=0; i<(QUEUE_SIZE * number_of_cores)-number_of_cores; i++)
   queue_cpu[i] = queue_cpu[i+number_of_cores];
  rear_queue-=number_of_cores;
}
int add_into_queue(struct cpustat *st)
{
  if(rear_queue<QUEUE_SIZE * number_of_cores)
  {
      queue_cpu[rear_queue++] = st;
    return 0;
  } else if(ready_to_print == false)
  {
    delete_most_older_reads();
    queue_cpu[rear_queue++] = st;
  }
  return 1;
}

#endif
