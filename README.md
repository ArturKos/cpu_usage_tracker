# Cpu Usage Tracker

Cpu Usage Tracker is a console-based program for monitoring the usage of individual CPU cores. It reads CPU usage data directly from system files (`/proc/stat`), providing detailed information about the activity of each core.

## Features
- **Language**: Written in C++ for high performance and control over system resources.
- **Multithreading**: Each CPU core is monitored in a separate thread, allowing real-time data processing.
- **Synchronization**: Uses mutexes to manage synchronization between threads.
- **Testing**: Includes basic unit tests for some functions to ensure program correctness.
- **Cross-Distro Compatibility**: Tested on multiple Linux distributions including Ubuntu, Lubuntu, Debian, Raspbian, and Fedora.


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


Tested on Linux Mint (Intel i5 CPU)

![2022-07-15_22-26](https://user-images.githubusercontent.com/17749811/179307163-a688728d-44e8-4329-8d7e-3b67ee5e2558.png)

![2022-07-15_22-26_1](https://user-images.githubusercontent.com/17749811/179307253-bf3b8437-7446-43ec-a643-45cd54b1ae2b.png)

Tested on Linux Ubuntu(Intel i7 CPU)

![2022-07-15_22-32](https://user-images.githubusercontent.com/17749811/179307365-75195702-f065-4986-ac08-977c8666ba93.png)

![2022-07-15_22-33](https://user-images.githubusercontent.com/17749811/179307405-b3ff8575-b9fc-41e9-b042-23cc0b093cd9.png)

Tested on Linux Lubuntu(Intel Atom N550 CPU)

![2022-07-16_16-04](https://user-images.githubusercontent.com/17749811/179359930-5a901611-040d-4239-93f9-6d1480abef0e.png)

![2022-07-16_16-05](https://user-images.githubusercontent.com/17749811/179359940-41e42a4d-bf73-47b6-b1e3-04d0c8b43534.png)

Tested on Linux Ubuntu(Intel i5 CPU)

![Zrzut ekranu z 2022-07-16 16-45-28](https://user-images.githubusercontent.com/17749811/179360000-6120fe3f-21af-416a-a3b9-f07105767a06.png)

![Zrzut ekranu z 2022-07-16 16-46-58](https://user-images.githubusercontent.com/17749811/179360005-5c074e94-57a3-44e3-954d-90234cf05307.png)

Tested on Rasbian (Raspberry Pi 4 4GB) - have to compile on rasbian

![2022-07-16_16-12](https://user-images.githubusercontent.com/17749811/179360111-0121f732-fede-49f6-8f47-25a560da1df5.png)

![2022-07-16_16-20](https://user-images.githubusercontent.com/17749811/179360129-baaf30f6-71a9-447d-84fd-ad59c72e3b20.png)

Tested on Fedora Linux (Virtual Machnie KVM)

![2022-07-17_13-08](https://user-images.githubusercontent.com/17749811/179395639-a6f04e00-adba-4d95-954e-1c3ac9d72158.png)

![2022-07-17_13-09](https://user-images.githubusercontent.com/17749811/179395647-89db86f8-afe4-4d8c-8986-be84b6052b6e.png)

Tested on Debian Linux (Virtual Machnie KVM)

![2022-07-17_13-43](https://user-images.githubusercontent.com/17749811/179396609-db140c37-fe22-42ee-a830-607b36574ada.png)

![2022-07-17_13-44](https://user-images.githubusercontent.com/17749811/179396618-151d8958-6983-43a2-9595-308c6904d91f.png)













