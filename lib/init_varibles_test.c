//testing values
void init_varibles_test(void)
{
  assert(sigterm_received == 0);
  assert(rear_queue == 0);
  assert(rear_queue_logger == 0);
  assert(ready_to_print == false);
  assert(number_of_cores > 0);
  assert(queue_cpu!=NULL);
}
