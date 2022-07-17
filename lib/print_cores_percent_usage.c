void print_cores_percent_usage(void)
{
  system("clear");
  for(unsigned int i=0; i<number_of_cores; i++)
  printf("%s: %u %%\n", queue_cpu[i]->t_core, queue_cpu[i]->percent_usage);
}
