void add_to_logger_queue(int message_number)
{
  assert(message_number >= 0);
  pthread_mutex_lock(&logger_mutex);
  if(rear_queue_logger < QUEUE_LOGGER_SIZE)
    logger_queue[rear_queue_logger++] = message_number;
  pthread_mutex_unlock(&logger_mutex);
}
void add_to_logger_queue_without_mutex(int message_number)
{
  if(rear_queue_logger < QUEUE_LOGGER_SIZE)
   logger_queue[rear_queue_logger++] = message_number;
}
int flush_logger_queue_to_file_without_mutex()
{
  if(rear_queue_logger == 0) return 0; //nothing to write

  FILE* logger_file;
  logger_file= fopen(logger_file_name, "a");

  if(logger_file == NULL) return 1; //error opening file

  for(unsigned int i = 0; i < rear_queue_logger; i++)
   fprintf(logger_file, "%s", logger_messages[logger_queue[i]]);

  rear_queue_logger = 0;

  fclose(logger_file);
 return 0;
}
int flush_logger_queue_to_file(void)
{
  if(rear_queue_logger == 0) return 0; //nothing to write
  pthread_mutex_lock(&logger_mutex);

  FILE* logger_file;
  logger_file= fopen(logger_file_name, "a");

  if(logger_file == NULL) return 1; //error opening file

  for(unsigned int i = 0; i < rear_queue_logger; i++)
   fprintf(logger_file, "%s", logger_messages[logger_queue[i]]);

  rear_queue_logger = 0;
  fclose(logger_file);

  pthread_mutex_unlock(&logger_mutex);
 return 0;
}
