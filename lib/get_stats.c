void get_stats(void)
{
  FILE *fp = fopen("/proc/stat", "r");
  assert(fp != NULL); //testing ifopen function dont't fail
  int lskip = 1;
  skip_lines(fp, lskip);

  struct cpustat *st = malloc(sizeof(struct cpustat));
  while(fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d", (st->t_core), &(st->t_user), &(st->t_nice),
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
