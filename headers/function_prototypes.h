#ifndef FUNCTION_PROTOTYPES
#define FUNCTION_PROTOTYPES

extern void free_memory(void);
extern void term(int signum);
extern void add_to_logger_queue(int message_number);
extern void add_to_logger_queue_without_mutex(int message_number);
extern int flush_logger_queue_to_file_without_mutex(void);
extern int flush_logger_queue_to_file(void);
extern void delete_most_older_reads(void);
extern int add_into_queue(struct cpustat *st);
extern void print_stats(struct cpustat *st);
extern void print_cores_percent_usage(void);
extern unsigned long count_cores(void);
extern void get_stats(void);
extern void* reader(void *t);
extern void* printer(void *t);
extern void calculate_percent_cpu_usage(void);
extern void* analyzer(void *t);
extern void* logger(void *t);
extern void* watchdog(void *t);
extern int create_threads(void);
extern void init_varibles(void);
extern int init_mutex(void);
extern void skip_lines(FILE *fp, int numlines);

//testing functions
extern void init_varibles_test(void);
extern void free_memory_test(void);
extern void create_thread_test(void);
#endif
