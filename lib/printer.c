void print_stats(struct cpustat *st)
{
    printf("%s: %ld %ld %ld %ld %ld %ld %ld\n", (st->t_core), (st->t_user), (st->t_nice),
        (st->t_system), (st->t_idle), (st->t_iowait), (st->t_irq),
        (st->t_softirq));
}
void print_cores_percent_usage()
{
  printf("\e[1;1H\e[2J");
  for(unsigned int i=0; i<number_of_cores; i++)
   printf("%s: %ld %%\n", queue_cpu[i]->t_core, queue_cpu[i]->percent_usage);

}
void* printer()
{
  for(;;)
  {
   pthread_mutex_lock(&lock_x);
   if(ready_to_print)
     {
      print_cores_percent_usage();
      delete_most_older_reads();
      ready_to_print = false;
     }
   pthread_mutex_unlock(&lock_x);
   sleep(1);
  }
  pthread_exit(NULL);
}
