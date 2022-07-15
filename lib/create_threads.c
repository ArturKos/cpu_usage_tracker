#include "queue.c"
#include "printer.c"
#include "reader.c"
#include "analyzer.c"
#include "logger.c"
#include "watchdog.c"


int create_threads(void)
{
  int        rc;

  /* create a new thread that will execute reader */
  rc = pthread_create(&reader_id, NULL, reader, NULL);
  if(rc)			/* could not create thread */
  {
      printf("\n ERROR: return code from pthread_create is %d for reader\n", rc);
      add_to_logger_queue(5);
      return 1;
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[READER_WATCHDOG] = time(NULL);
  pthread_mutex_unlock(&watchdog_timer_mutex);

  printf("\n Created new thread (%lu) for reader \n", reader_id);
  add_to_logger_queue(6);

  /* create a new thread that will execute analyzer */
  rc = pthread_create(&analyzer_id, NULL, analyzer, NULL);
  if(rc)			/* could not create thread */
  {
      printf("\n ERROR: return code from pthread_create is %d for analyzer\n", rc);
      add_to_logger_queue(7);
      return 1;
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[ANALYZER_WATCHDOG] = time(NULL);
  pthread_mutex_unlock(&watchdog_timer_mutex);

  printf("\n Created new thread (%lu) for analyzer \n", analyzer_id);
  add_to_logger_queue(8);
  /* create a new thread that will execute printer */
  rc = pthread_create(&printer_id, NULL, printer, NULL);
  if(rc)			/* could not create thread */
  {
      printf("\n ERROR: return code from pthread_create is %d for printer\n", rc);
      add_to_logger_queue(9);
      return 1;
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[PRINTER_WATCHDOG] = time(NULL);
  pthread_mutex_unlock(&watchdog_timer_mutex);
  printf("\n Created new thread (%lu) for printer \n", printer_id);
  add_to_logger_queue(10);
  /* create a new thread that will execute logger */
  rc = pthread_create(&logger_id, NULL, logger, NULL);
  if(rc)			/* could not create thread */
  {
      printf("\n ERROR: return code from pthread_create is %d for logger\n", rc);
      add_to_logger_queue(11);
      return 1;
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[LOGGER_WATCHDOG] = time(NULL);
  pthread_mutex_unlock(&watchdog_timer_mutex);
  printf("\n Created new thread (%lu) for logger \n", logger_id);
  add_to_logger_queue(12);
  /* create a new thread that will execute reader */
  rc = pthread_create(&watchdog_id, NULL, watchdog, NULL);
  if(rc)			/* could not create thread */
  {
      printf("\n ERROR: return code from pthread_create is %d for watchdog\n", rc);
      add_to_logger_queue(13);
      return 1;
  }
  printf("\n Created new thread (%lu) for watchdog \n", reader_id);
  add_to_logger_queue(14);

  pthread_join(watchdog_id, NULL);

  return 0;
}
