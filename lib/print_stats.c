void print_stats(struct cpustat *st)
{
  assert(st != NULL);
  printf("%s: %u %u %u %u %u %u %u\n", (st->t_core), (st->t_user), (st->t_nice),
  (st->t_system), (st->t_idle), (st->t_iowait), (st->t_irq),
  (st->t_softirq));
}
