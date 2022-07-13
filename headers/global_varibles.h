#ifndef GLOBAL_VAR
#define GLOBAL_VAR
#define QUEUE_SIZE 5

pthread_t  analyzer_id;
pthread_t  logger_id;
pthread_t  printer_id;
pthread_t  reader_id;
pthread_t  watchdog_id;

pthread_mutex_t lock_x;
unsigned int number_of_cores;

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
};

unsigned int rear_queue;
bool ready_to_print;
struct cpustat **queue_cpu;

#endif /* GLOBAL_VAR */
