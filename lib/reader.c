
void skip_lines(FILE *fp, int numlines)
{
    int cnt = 0;
    char ch;
    while((cnt < numlines) && ((ch = getc(fp)) != EOF))
    {
        if (ch == '\n')
            cnt++;
    }
    return;
}
int count_cores()
{
    FILE *fp = fopen("/proc/stat", "r");
    skip_lines(fp, 1);
    int number_cores=0;
    struct cpustat *st = malloc(sizeof(struct cpustat));

    while(fscanf(fp, "%s %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", (st->t_core), &(st->t_user), &(st->t_nice),
        &(st->t_system), &(st->t_idle), &(st->t_iowait), &(st->t_irq),
        &(st->t_softirq), &(st->t_steal), &(st->t_guest), &(st->t_guest_nice))!=EOF)
        {
          if(st->t_core[0]!='c') break;
          number_cores++;
        }
    free(st);
    fclose(fp);
	return number_cores;
}
void get_stats()
{
    FILE *fp = fopen("/proc/stat", "r");
    int lskip = 1;
    skip_lines(fp, lskip);

    struct cpustat *st = malloc(sizeof(struct cpustat));
    while(fscanf(fp, "%s %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", (st->t_core), &(st->t_user), &(st->t_nice),
        &(st->t_system), &(st->t_idle), &(st->t_iowait), &(st->t_irq),
        &(st->t_softirq), &(st->t_steal), &(st->t_guest), &(st->t_guest_nice))!=EOF)
        {
          if(st->t_core[0]!='c')
           {
            free(st);
            break;
           }
          add_into_queue(st);
          st = malloc(sizeof(struct cpustat));
        }
    fclose(fp);
	return;
}

void* reader()
{

  for(;;)
  {
   pthread_mutex_lock(&watchdog_timer_mutex);
   watchdog_timer[READER_WATCHDOG] = time(NULL);
   pthread_mutex_unlock(&watchdog_timer_mutex);

   pthread_mutex_lock(&lock_x);
   get_stats();
   pthread_mutex_unlock(&lock_x);
   sleep(1);
  }
  pthread_exit(NULL);
}
