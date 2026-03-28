# CPU Usage Tracker

A multithreaded per-core CPU usage monitor for Linux, written in **C** with **POSIX threads**. Reads CPU statistics directly from `/proc/stat` and displays real-time utilization percentages for each core using a producer-consumer architecture.

![C](https://img.shields.io/badge/C-99-blue)
![POSIX](https://img.shields.io/badge/POSIX-pthreads-green)
![Valgrind](https://img.shields.io/badge/Valgrind-leak--free-brightgreen)
![Platform](https://img.shields.io/badge/Platform-Linux-lightgrey)

## Features

- **Producer-consumer architecture** with 5 dedicated threads: Reader, Analyzer, Printer, Logger, and Watchdog
- **Per-core utilization** -- automatically detects the number of CPU cores and calculates usage percentage for each
- **Ring buffer queue** for CPU statistics with configurable depth (default: 5 snapshots)
- **Mutex-protected shared data** -- all shared structures guarded by `pthread_mutex_t` for thread safety
- **Watchdog thread** -- monitors all worker threads via heartbeat timestamps; detects crashes within 2 seconds and triggers graceful shutdown
- **SIGTERM signal handling** -- clean shutdown on termination signal with proper thread detachment and memory cleanup
- **Logger thread** -- asynchronous event logging to `cut.log` via a 50-entry message queue
- **Unit tests** -- includes test harness for variable initialization and memory cleanup verification
- **Valgrind verified** -- zero memory leaks confirmed across all execution paths
- **Cross-distribution compatibility** -- tested on Ubuntu, Lubuntu, Debian, Raspbian, Fedora, and Linux Mint

## Dependencies

| Tool | Purpose |
|------|---------|
| GCC or Clang | C compiler with POSIX thread support |
| Make | Build system |
| pthreads | Thread creation and synchronization |
| Valgrind | Memory leak verification (optional) |

### Installing dependencies (Ubuntu / Debian)

```bash
sudo apt-get install build-essential valgrind
```

## Building

```bash
git clone https://github.com/ArturKos/cpu_usage_tracker.git
cd cpu_usage_tracker
make
```

For a debug build with symbols (for Valgrind):

```bash
cc -Wall -Wextra -g cut.c -o cut -lpthread
```

### Running tests

```bash
make test
./test
```

## Usage

```bash
./cut
```

The program runs continuously, printing per-core CPU usage percentages to the terminal every second. Send `SIGTERM` (Ctrl+C or `kill`) for a clean shutdown.

## Thread Architecture

```
Reader ──> [Queue Buffer] ──> Analyzer ──> [Ready Flag] ──> Printer
   │                             │                             │
   └──── heartbeat ──────────────┴──── heartbeat ──────────────┘
                                 │
                             Watchdog (monitors all heartbeats)
                                 │
   Logger <── event queue ───────┘
```

| Thread | Role | Interval |
|--------|------|----------|
| **Reader** | Reads `/proc/stat` and enqueues raw CPU counters | 200 ms |
| **Analyzer** | Computes per-core usage percentages from consecutive snapshots | 200 ms |
| **Printer** | Displays calculated percentages to stdout | 1 s |
| **Logger** | Flushes event messages from a ring buffer to `cut.log` | 200 ms |
| **Watchdog** | Checks heartbeat timestamps; shuts down on crash or SIGTERM | 200 ms |

## Memory Verification

Verified with Valgrind -- zero memory leaks:

```
==17653== HEAP SUMMARY:
==17653==     in use at exit: 0 bytes in 0 blocks
==17653==   total heap usage: 86 allocs, 86 frees, 28,731 bytes allocated
==17653== All heap blocks were freed -- no leaks are possible
==17653== ERROR SUMMARY: 0 errors from 0 contexts
```

## Project Structure

```
cpu_usage_tracker/
├── makefile                                # Build configuration (gcc, -lpthread)
├── README.md                               # This file
├── cut.c                                   # Main entry point: init, create threads, cleanup
├── test.c                                  # Unit test harness
├── headers/
│   ├── function_prototypes.h               # All function declarations
│   └── global_varibles.h                   # Shared state: queues, mutexes, thread IDs,
│                                           #   cpustat struct, logger messages
└── lib/
    ├── reader.c                            # Reader thread: reads /proc/stat into queue
    ├── get_stats.c                         # Parses /proc/stat fields into cpustat structs
    ├── analyzer.c                          # Analyzer thread: computes CPU usage percentages
    ├── calculate_percent_cpu_usage.c       # Per-core usage calculation from two snapshots
    ├── printer.c                           # Printer thread: displays results to stdout
    ├── print_cores_percent_usage.c         # Formats and prints per-core percentages
    ├── print_stats.c                       # Debug: prints raw cpustat fields
    ├── logger.c                            # Logger thread: flushes event queue to file
    ├── queue_logger.c                      # Logger ring buffer: enqueue and flush operations
    ├── watchdog.c                          # Watchdog thread: heartbeat monitoring, shutdown
    ├── count_cores.c                       # Detects number of CPU cores from /proc/stat
    ├── skip_lines.c                        # Utility: skip N lines in a file stream
    ├── queue.c                             # CPU stats ring buffer operations
    ├── create_threads.c                    # pthread_create calls for all 5 threads
    ├── init_varibles.c                     # Memory allocation and variable initialization
    ├── init_mutex.c                        # Mutex initialization for all locks
    ├── free_memory.c                       # Thread join and memory deallocation
    ├── term_signal.c                       # SIGTERM signal handler registration
    ├── testing.c                           # Shared test utilities
    ├── create_thread_test.c                # Thread creation test
    ├── init_varibles_test.c                # Variable initialization assertions
    └── free_memory_test.c                  # Memory cleanup assertions
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

## License

This project is provided as-is for educational purposes.

---

**Author:** Artur Kos
