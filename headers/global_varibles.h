#ifndef GLOBAL_VAR
#define GLOBAL_VAR

#define QUEUE_SIZE 5
#define QUEUE_LOGGER_SIZE 50

#define READER_WATCHDOG 0
#define PRINTER_WATCHDOG 1
#define ANALYZER_WATCHDOG 2
#define LOGGER_WATCHDOG 3

unsigned long watchdog_timer[4];
volatile sig_atomic_t sigterm_received;

pthread_t  analyzer_id;
pthread_t  logger_id;
pthread_t  printer_id;
pthread_t  reader_id;
pthread_t  watchdog_id;

pthread_mutex_t lock_x;
pthread_mutex_t watchdog_timer_mutex;
pthread_mutex_t logger_mutex;
unsigned int number_of_cores;

unsigned int rear_queue;
bool ready_to_print;
struct cpustat {
    char          t_core[255];
    unsigned long t_user;
    unsigned long t_nice;
    unsigned long t_system;
    unsigned long t_idle;
    unsigned long t_iowait;
    unsigned long t_irq;
    unsigned long t_softirq;
    unsigned long t_steal;
    unsigned long t_guest;
    unsigned long t_guest_nice;
    unsigned long percent_usage;
} **queue_cpu;

int  logger_queue[QUEUE_LOGGER_SIZE];
unsigned int rear_queue_logger;
char *logger_file_name = "cut.log";
char **logger_messages = (char *[]) {"Mutex init has failed - lock_x\n",
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
