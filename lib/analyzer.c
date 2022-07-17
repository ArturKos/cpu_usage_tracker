void calculate_percent_cpu_usage(void)
{
  for(unsigned long i = 0; i<number_of_cores; i++)
  {
    unsigned int prev_sum = queue_cpu[i]->t_user+queue_cpu[i]->t_nice+
    queue_cpu[i]->t_system+queue_cpu[i]->t_idle+queue_cpu[i]->t_iowait+
    queue_cpu[i]->t_irq+queue_cpu[i]->t_softirq+queue_cpu[i]->t_steal+
    queue_cpu[i]->t_guest+queue_cpu[i]->t_guest_nice;

    unsigned int sum = queue_cpu[i+number_of_cores]->t_user+queue_cpu[i+number_of_cores]->t_nice+
    queue_cpu[i+number_of_cores]->t_system+queue_cpu[i+number_of_cores]->t_idle+queue_cpu[i+number_of_cores]->t_iowait+
    queue_cpu[i+number_of_cores]->t_irq+queue_cpu[i+number_of_cores]->t_softirq+queue_cpu[i+number_of_cores]->t_steal+
    queue_cpu[i+number_of_cores]->t_guest+queue_cpu[i+number_of_cores]->t_guest_nice;
    unsigned int delta = sum - prev_sum;
    unsigned int idle =  queue_cpu[i+number_of_cores]->t_idle-queue_cpu[i]->t_idle;
    unsigned int core_used = delta - idle;
    unsigned int core_percent_usage = 0;
    if(delta!=0)
    core_percent_usage = (100 * core_used )/delta;
    queue_cpu[i+number_of_cores]->percent_usage = core_percent_usage;
  }
  ready_to_print = true;
  delete_most_older_reads();
}
void* analyzer(void *t)
{
  assert(t == NULL);
  for(;;)
  {
    pthread_mutex_lock(&watchdog_timer_mutex);
    watchdog_timer[ANALYZER_WATCHDOG] = time(NULL);
    pthread_mutex_unlock(&watchdog_timer_mutex);

    pthread_mutex_lock(&lock_x);
    if(rear_queue>=2*number_of_cores && !ready_to_print)
    calculate_percent_cpu_usage();
    pthread_mutex_unlock(&lock_x);
    sleep(1);
  }
  pthread_exit(NULL);
}
