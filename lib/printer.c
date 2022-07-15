void print_stats(struct cpustat *st)
{
    printf("%s: %u %u %u %u %u %u %u\n", (st->t_core), (st->t_user), (st->t_nice),
        (st->t_system), (st->t_idle), (st->t_iowait), (st->t_irq),
        (st->t_softirq));
}
void print_cores_percent_usage(void)
{
  system("clear");
  for(unsigned int i=0; i<number_of_cores; i++)
   printf("%s: %u %%\n", queue_cpu[i]->t_core, queue_cpu[i]->percent_usage);

}
void* printer(void *t)
{
  assert(t == NULL);
  for(;;)
  {
   pthread_mutex_lock(&watchdog_timer_mutex);
   watchdog_timer[PRINTER_WATCHDOG] = time(NULL);
   pthread_mutex_unlock(&watchdog_timer_mutex);

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
