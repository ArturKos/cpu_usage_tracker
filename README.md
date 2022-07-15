# cpu_usage_tracker

Builded project for valgrind 
cc -Wall -Wextra -g cut.c -o cut -lpthread

Output valgrind (command valgrind --leak-check=yes cut)
==17653== Memcheck, a memory error detector
==17653== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17653== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==17653== Command: cut
==17653== 
cut: musisz podać listę bajtów, znaków albo pól
Napisz „cut --help” dla uzyskania informacji.
==17653== 
==17653== HEAP SUMMARY:
==17653==     in use at exit: 0 bytes in 0 blocks
==17653==   total heap usage: 86 allocs, 86 frees, 28,731 bytes allocated
==17653== 
==17653== All heap blocks were freed -- no leaks are possible
==17653== 
==17653== For lists of detected and suppressed errors, rerun with: -s
==17653== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
