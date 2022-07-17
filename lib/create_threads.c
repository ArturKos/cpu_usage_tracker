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
    add_to_logger_queue(5); //ERROR: pthread_create for reader
    return 1;
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[READER_WATCHDOG] = time(NULL);
  pthread_mutex_unlock(&watchdog_timer_mutex);

  add_to_logger_queue(6); //Created new thread for reader

  /* create a new thread that will execute analyzer */
  rc = pthread_create(&analyzer_id, NULL, analyzer, NULL);
  if(rc)			/* could not create thread */
  {
    add_to_logger_queue(7); //ERROR: pthread_create for analyzer
    return 1;
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[ANALYZER_WATCHDOG] = time(NULL);
  pthread_mutex_unlock(&watchdog_timer_mutex);

  add_to_logger_queue(8); //Created new thread for analyzer

  /* create a new thread that will execute printer */
  rc = pthread_create(&printer_id, NULL, printer, NULL);
  if(rc)			/* could not create thread */
  {
    add_to_logger_queue(9); //ERROR: pthread_create for printer
    return 1;
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[PRINTER_WATCHDOG] = time(NULL);
  pthread_mutex_unlock(&watchdog_timer_mutex);
  add_to_logger_queue(10); //Created new thread for printer

  /* create a new thread that will execute logger */
  rc = pthread_create(&logger_id, NULL, logger, NULL);
  if(rc)			/* could not create thread */
  {
    add_to_logger_queue(11); //ERROR: pthread_create for logger
    return 1;
  }
  pthread_mutex_lock(&watchdog_timer_mutex);
  watchdog_timer[LOGGER_WATCHDOG] = time(NULL);
  pthread_mutex_unlock(&watchdog_timer_mutex);
  add_to_logger_queue(12); //Created new thread for logger

  /* create a new thread that will execute reader */
  rc = pthread_create(&watchdog_id, NULL, watchdog, NULL);
  if(rc)			/* could not create thread */
  {
    add_to_logger_queue(13); //ERROR: pthread_create for watchdog
    return 1;
  }

  add_to_logger_queue(14); //Created new thread for watchdog

  pthread_join(watchdog_id, NULL);

  return 0;
}
