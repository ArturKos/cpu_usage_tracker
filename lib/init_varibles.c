void init_varibles(void)
{
  sigterm_received = 0;
  struct sigaction action;
  memset(&action, 0, sizeof(struct sigaction));
  action.sa_handler = term;
  sigaction(SIGTERM, &action, NULL);

  rear_queue = 0;
  rear_queue_logger = 0;
  ready_to_print = false;
  number_of_cores = count_cores();
  queue_cpu = malloc(QUEUE_SIZE * number_of_cores * sizeof(struct cpustat)); /* VLA Variable-length array applied */

}
