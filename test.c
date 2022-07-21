  #include <stdio.h>
  #include <pthread.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <stdbool.h>
  #include <time.h>
  #include <signal.h>
  #include <string.h>
  #include <assert.h>
  #include "headers/global_varibles.h"
  #include "lib/create_thread_test.c"
  #include "headers/function_prototypes.h"
  #include "lib/skip_lines.c"
  #include "lib/count_cores.c"
  #include "lib/free_memory.c"
  #include "lib/term_signal.c"
  #include "lib/queue_logger.c"
  #include "lib/create_threads.c"
  #include "lib/init_varibles.c"
  #include "lib/init_mutex.c"
  #include "lib/init_varibles_test.c"
  #include "lib/free_memory_test.c"

  
  int main (void)
  {
    init_varibles();
    init_varibles_test();

    free_memory();
    free_memory_test();
  }
