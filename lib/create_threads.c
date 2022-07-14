#include "queue.c"
#include "printer.c"
#include "reader.c"
#include "analyzer.c"
#include "logger.c"
#include "watchdog.c"


int create_threads(void)
{
  int        rc;
  time_t     time_now = time(NULL);

  /* create a new thread that will execute reader */
  rc = pthread_create(&reader_id, NULL, reader, NULL);
  if(rc)			/* could not create thread */
  {
      printf("\n ERROR: return code from pthread_create is %d for reader\n", rc);
      exit(1);
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[READER_WATCHDOG] = *localtime(&time_now);
  pthread_mutex_unlock(&watchdog_timer_mutex);

  printf("\n Created new thread (%lu) for reader \n", reader_id);

  /* create a new thread that will execute analyzer */
  rc = pthread_create(&analyzer_id, NULL, analyzer, NULL);
  if(rc)			/* could not create thread */
  {
      printf("\n ERROR: return code from pthread_create is %d for analyzer\n", rc);
      exit(1);
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[ANALYZER_WATCHDOG] = *localtime(&time_now);
  pthread_mutex_unlock(&watchdog_timer_mutex);

  printf("\n Created new thread (%lu) for analyzer \n", analyzer_id);

  /* create a new thread that will execute printer */
  rc = pthread_create(&printer_id, NULL, printer, NULL);
  if(rc)			/* could not create thread */
  {
      printf("\n ERROR: return code from pthread_create is %d for printer\n", rc);
      exit(1);
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[PRINTER_WATCHDOG] = *localtime(&time_now);
  pthread_mutex_unlock(&watchdog_timer_mutex);
  printf("\n Created new thread (%lu) for printer \n", printer_id);

  /* create a new thread that will execute logger */
  rc = pthread_create(&logger_id, NULL, logger, NULL);
  if(rc)			/* could not create thread */
  {
      printf("\n ERROR: return code from pthread_create is %d for logger\n", rc);
      exit(1);
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[LOGGER_WATCHDOG] = *localtime(&time_now);
  pthread_mutex_unlock(&watchdog_timer_mutex);
  printf("\n Created new thread (%lu) for logger \n", logger_id);

  /* create a new thread that will execute reader */
  rc = pthread_create(&watchdog_id, NULL, watchdog, NULL);
  if(rc)			/* could not create thread */
  {
      printf("\n ERROR: return code from pthread_create is %d for watchdog\n", rc);
      exit(1);
  }
  printf("\n Created new thread (%lu) for watchdog \n", reader_id);

  return 0;
}
