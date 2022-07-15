#ifndef GLOBAL_VAR
#define GLOBAL_VAR

#define QUEUE_SIZE 5
#define QUEUE_LOGGER_SIZE 50

#define READER_WATCHDOG 0
#define PRINTER_WATCHDOG 1
#define ANALYZER_WATCHDOG 2
#define LOGGER_WATCHDOG 3

static long watchdog_timer[4];
static volatile sig_atomic_t sigterm_received;
static int signal_number;

static pthread_t  analyzer_id;
static pthread_t  logger_id;
static pthread_t  printer_id;
static pthread_t  reader_id;
static pthread_t  watchdog_id;

static pthread_mutex_t lock_x;
static pthread_mutex_t watchdog_timer_mutex;
static pthread_mutex_t logger_mutex;
static unsigned long number_of_cores;

static unsigned int rear_queue;
static bool ready_to_print;

static struct cpustat {
  char t_core[256];
  unsigned int t_user;
  unsigned int t_nice;
  unsigned int t_system;
  unsigned int t_idle;
  unsigned int t_iowait;
  unsigned int t_irq;
  unsigned int t_softirq;
  unsigned int t_steal;
  unsigned int t_guest;
  unsigned int t_guest_nice;
  unsigned int percent_usage;
} **queue_cpu;

static int  logger_queue[QUEUE_LOGGER_SIZE];
static unsigned int rear_queue_logger;
static char *logger_file_name = "cut.log";
static char **logger_messages = (char *[]) {"Mutex init has failed - lock_x\n",
                                            "Mutex init has failed - logger_mutex\n",
                                            "Mutex init has failed - watchdog_timer_mutex\n",
                                            "Error creating threads \n",
                                            "Ending program with status OK \n",
                                            "ERROR: pthread_create for reader\n",
                                            "Created new thread for reader \n",
                                            "ERROR: pthread_create for analyzer\n",
                                            "Created new thread for analyzer \n",
                                            "ERROR: pthread_create for printer\n",
                                            "Created new thread or printer \n",
                                            "ERROR: pthread_create for logger\n",
                                            "Created new thread for logger \n",
                                            "ERROR: pthread_create for watchdog\n",
                                            "Created new thread for watchdog \n",
                                            "SIGTERM signal  received. I close all threads, free memory, quit the program.\n",
                                            "One of the threads has crashed, I close all threads, free memory, quit the program. \n"};



#endif /* GLOBAL_VAR */
