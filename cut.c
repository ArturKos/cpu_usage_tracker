#include <stdio.h>
#include <pthread.h>
#include "headers/global_varibles.h"
#include "lib/create_threads.c"


int main(int argc, char* argv[])
{
  if (create_threads()!=0)
    printf("\n Ettor creating threads \n");
}
