#ifndef CALLBACK_TRACK_BENCH_H
#define CALLBACK_TRACK_BENCH_H

#include <stdint.h>

typedef struct callback_track_bench_s {
    uint64_t samples;
    uint64_t guest_elf_ticks;
    uint64_t host_dladdr_ticks;
    uint64_t protection_ticks;
    uint64_t got_ticks;
    uint64_t wrapper_ticks;
    uint64_t wrapper_checks;
} callback_track_bench_t;

extern callback_track_bench_t callback_track_bench;

int callback_track_bench_enabled(void);
uint64_t callback_track_counter(void);
uint64_t callback_track_counter_hz(void);
void callback_track_bench_report(void);

#endif
