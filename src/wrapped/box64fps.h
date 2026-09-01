#ifndef BOX64_FPS_H
#define BOX64_FPS_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static inline void box64_log_frame_presented(void)
{
    static int fps_log_fd = -2;
    if (fps_log_fd == -2) {
        const char* path = getenv("BOX64_FPS_LOG");
        fps_log_fd = path && path[0]
            ? open(path, O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0644)
            : -1;
    }
    if (fps_log_fd < 0)
        return;

    struct timespec now;
    char line[64];
    if (clock_gettime(CLOCK_MONOTONIC, &now) != 0)
        return;
    int length = snprintf(line, sizeof(line), "%lld.%09ld\n",
                          (long long)now.tv_sec, now.tv_nsec);
    if (length > 0) {
        ssize_t written = write(fps_log_fd, line, (size_t)length);
        (void)written;
    }
}

#endif
