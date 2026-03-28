# CPU Usage Tracker

Multithreaded per-core CPU usage monitor for Linux. Reads CPU statistics directly from `/proc/stat` and displays real-time utilization percentages for each core.

## Features

- **Language**: Written in C with POSIX threads for high performance and direct system resource access
- **Multithreading**: Producer-consumer architecture with dedicated reader, analyzer, printer, and watchdog threads
- **Synchronization**: Mutex-protected shared data structures for thread-safe operation
- **Testing**: Includes unit tests for core functions
- **Cross-distribution compatibility**: Tested on Ubuntu, Lubuntu, Debian, Raspbian, and Fedora

## Build

```bash
make
```

For debug/Valgrind build:
```bash
cc -Wall -Wextra -g cut.c -o cut -lpthread
```

## Memory Verification

Verified with Valgrind — zero memory leaks:

```
==17653== HEAP SUMMARY:
==17653==     in use at exit: 0 bytes in 0 blocks
==17653==   total heap usage: 86 allocs, 86 frees, 28,731 bytes allocated
==17653== All heap blocks were freed -- no leaks are possible
==17653== ERROR SUMMARY: 0 errors from 0 contexts
```

## Tested Platforms

**Linux Mint** (Intel i5)

![2022-07-15_22-26](https://user-images.githubusercontent.com/17749811/179307163-a688728d-44e8-4329-8d7e-3b67ee5e2558.png)

![2022-07-15_22-26_1](https://user-images.githubusercontent.com/17749811/179307253-bf3b8437-7446-43ec-a643-45cd54b1ae2b.png)

**Ubuntu** (Intel i7)

![2022-07-15_22-32](https://user-images.githubusercontent.com/17749811/179307365-75195702-f065-4986-ac08-977c8666ba93.png)

![2022-07-15_22-33](https://user-images.githubusercontent.com/17749811/179307405-b3ff8575-b9fc-41e9-b042-23cc0b093cd9.png)

**Lubuntu** (Intel Atom N550)

![2022-07-16_16-04](https://user-images.githubusercontent.com/17749811/179359930-5a901611-040d-4239-93f9-6d1480abef0e.png)

![2022-07-16_16-05](https://user-images.githubusercontent.com/17749811/179359940-41e42a4d-bf73-47b6-b1e3-04d0c8b43534.png)

**Ubuntu** (Intel i5)

![Screenshot](https://user-images.githubusercontent.com/17749811/179360000-6120fe3f-21af-416a-a3b9-f07105767a06.png)

![Screenshot](https://user-images.githubusercontent.com/17749811/179360005-5c074e94-57a3-44e3-954d-90234cf05307.png)

**Raspbian** (Raspberry Pi 4, 4GB RAM)

![2022-07-16_16-12](https://user-images.githubusercontent.com/17749811/179360111-0121f732-fede-49f6-8f47-25a560da1df5.png)

![2022-07-16_16-20](https://user-images.githubusercontent.com/17749811/179360129-baaf30f6-71a9-447d-84fd-ad59c72e3b20.png)

**Fedora** (KVM Virtual Machine)

![2022-07-17_13-08](https://user-images.githubusercontent.com/17749811/179395639-a6f04e00-adba-4d95-954e-1c3ac9d72158.png)

![2022-07-17_13-09](https://user-images.githubusercontent.com/17749811/179395647-89db86f8-afe4-4d8c-8986-be84b6052b6e.png)

**Debian** (KVM Virtual Machine)

![2022-07-17_13-43](https://user-images.githubusercontent.com/17749811/179396609-db140c37-fe22-42ee-a830-607b36574ada.png)

![2022-07-17_13-44](https://user-images.githubusercontent.com/17749811/179396618-151d8958-6983-43a2-9595-308c6904d91f.png)
