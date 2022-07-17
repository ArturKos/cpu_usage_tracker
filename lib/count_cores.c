unsigned long count_cores(void)
{
  FILE *fp = fopen("/proc/stat", "r");
  assert(fp != NULL); //testing ifopen function dont't fail
  skip_lines(fp, 1);
  unsigned long number_cores=0;
  struct cpustat *st = malloc(sizeof(struct cpustat));

  while(fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d", (st->t_core), &(st->t_user), &(st->t_nice),
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
